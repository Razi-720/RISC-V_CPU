# ==============================================================================
# driver.py - Memory and Instruction Driver for RV32I Pipeline
# ==============================================================================

import cocotb
from cocotb.triggers import RisingEdge, Timer
from cocotb.binary import BinaryValue
import random
import struct
from typing import Dict, List, Optional, Tuple
from dataclasses import dataclass
import logging

logger = logging.getLogger(__name__)

@dataclass
class MemoryTransaction:
    """Memory transaction data structure"""
    addr: int
    data: int = 0
    mask: int = 0xF
    write_enable: bool = False
    cycle: int = 0

class InstructionMemory:
    """Instruction memory model"""
    
    def __init__(self, size: int = 64 * 1024):  # 64KB default
        self.memory = bytearray(size)
        self.size = size
        self.access_delay = 0  # Configurable access delay
        
    def write_instruction(self, addr: int, instruction: int):
        """Write 32-bit instruction to memory"""
        if addr >= self.size - 3:
            raise ValueError(f"Instruction memory access out of bounds: 0x{addr:08x}")
        self.memory[addr:addr+4] = struct.pack('<I', instruction & 0xFFFFFFFF)
        
    def read_instruction(self, addr: int) -> int:
        """Read 32-bit instruction from memory"""
        if addr >= self.size - 3:
            logger.warning(f"Instruction fetch out of bounds: 0x{addr:08x}")
            return 0  # Return NOP for out-of-bounds
        return struct.unpack('<I', self.memory[addr:addr+4])[0]
        
    def load_program(self, instructions: List[int], base_addr: int = 0):
        """Load instruction sequence into memory"""
        for i, instr in enumerate(instructions):
            self.write_instruction(base_addr + i * 4, instr)

class DataMemory:
    """Data memory model with proper masking support"""
    
    def __init__(self, size: int = 4 * 1024* 1024* 1024):  # 64KB default
        self.memory = bytearray(size)
        self.size = size
        self.pending_transactions = []
        self.access_delay = 0
        
    def write(self, addr: int, data: int, mask: int = 0xF) -> bool:
        """Write data with byte masking"""
        if addr >= self.size:
            logger.error(f"Data memory write out of bounds: 0x{addr:08x}")
            return False
            
        # Apply byte mask
        for i in range(4):
            if mask & (1 << i):
                byte_addr = addr + i
                if byte_addr < self.size:
                    self.memory[byte_addr] = (data >> (i * 8)) & 0xFF
        return True
        
    def read(self, addr: int, mask: int = 0xF) -> int:
        """Read data with byte masking"""
        if addr >= self.size:
            logger.error(f"Data memory read out of bounds: 0x{addr:08x}")
            return 0
            
        result = 0
        for i in range(4):
            if mask & (1 << i):
                byte_addr = addr + i
                if byte_addr < self.size:
                    result |= (self.memory[byte_addr] << (i * 8))
        return result

class RV32IDriver:
    """Main driver for RV32I processor"""
    
    def __init__(self, dut):
        self.dut = dut
        self.imem = InstructionMemory()
        self.dmem = DataMemory()
        self.cycle_count = 0
        self.memory_latency = 1  # Configurable memory latency
        
    async def reset(self):
        """Reset the processor"""
        logger.info("Resetting processor...")
        self.dut.Rst_In.value = 1
        await Timer(10, units='ns')
        await RisingEdge(self.dut.Clk_In)
        self.dut.Rst_In.value = 0
        await RisingEdge(self.dut.Clk_In)
        self.cycle_count = 0
        
    async def drive_instruction_memory(self):
        """Drive instruction memory interface"""
        while True:
            await RisingEdge(self.dut.Clk_In)
            
            # Read instruction address
            if hasattr(self.dut, 'Instr_Addr_Out'):
                addr = int(self.dut.Instr_Addr_Out.value)
                instruction = self.imem.read_instruction(addr)
                
                # Drive instruction with optional delay
                if self.imem.access_delay > 0:
                    await Timer(self.imem.access_delay, units='ns')
                    
                self.dut.Instruction_In.value = instruction
                logger.debug(f"Cycle {self.cycle_count}: Fetch @ 0x{addr:08x} = 0x{instruction:08x}")
                
    async def drive_data_memory(self):
        """Drive data memory interface"""
        while True:
            await RisingEdge(self.dut.Clk_In)
            
            # Handle data memory write
            if (hasattr(self.dut, 'DM_WrEn_Out') and 
                int(self.dut.DM_WrEn_Out.value) == 1):
                
                addr = int(self.dut.DM_Addr_Out.value)
                data = int(self.dut.DM_Data_Out.value)
                mask = int(self.dut.DM_Mask_Out.value) if hasattr(self.dut, 'DM_Mask_Out') else 0xF
                
                success = self.dmem.write(addr, data, mask)
                logger.debug(f"Cycle {self.cycle_count}: Store @ 0x{addr:08x} = 0x{data:08x}, mask=0x{mask:x}")
                
            # Handle data memory read
            elif hasattr(self.dut, 'DM_Addr_Out'):
                addr = int(self.dut.DM_Addr_Out.value)
                mask = int(self.dut.DM_Mask_Out.value) if hasattr(self.dut, 'DM_Mask_Out') else 0xF
                
                # Only read if address is valid and not a write
                if addr != 0:  # Assuming 0 is invalid address
                    read_data = self.dmem.read(addr, mask)
                    
                    # Drive read data with optional delay
                    if self.dmem.access_delay > 0:
                        await Timer(self.dmem.access_delay, units='ns')
                        
                    self.dut.DM_Data_In.value = read_data
                    logger.debug(f"Cycle {self.cycle_count}: Load @ 0x{addr:08x} = 0x{read_data:08x}")
                    
    async def cycle_counter(self):
        """Track cycle count"""
        while True:
            await RisingEdge(self.dut.Clk_In)
            self.cycle_count += 1
            
    def load_program(self, instructions: List[int], base_addr: int = 0):
        """Load instruction program into memory"""
        self.imem.load_program(instructions, base_addr)
        logger.info(f"Loaded {len(instructions)} instructions at base 0x{base_addr:08x}")
        
    def set_memory_latency(self, cycles: int):
        """Set memory access latency"""
        self.memory_latency = cycles
        self.imem.access_delay = cycles
        self.dmem.access_delay = cycles