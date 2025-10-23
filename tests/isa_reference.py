# ==============================================================================
# isa_reference.py - RV32I Reference Model
# ==============================================================================

import struct
import logging
from typing import Dict, List, Optional, Any
from enum import Enum

logger = logging.getLogger(__name__)

class InstructionType(Enum):
    R_TYPE = "R"
    I_TYPE = "I"  
    S_TYPE = "S"
    B_TYPE = "B"
    U_TYPE = "U"
    J_TYPE = "J"

class RV32IInstruction:
    """RV32I Instruction decoder and encoder"""
    
    def __init__(self, instruction: int):
        self.raw = instruction
        self.opcode = instruction & 0x7F
        self.rd = (instruction >> 7) & 0x1F
        self.funct3 = (instruction >> 12) & 0x7
        self.rs1 = (instruction >> 15) & 0x1F
        self.rs2 = (instruction >> 20) & 0x1F
        self.funct7 = (instruction >> 25) & 0x7F
        
        # Immediate extraction
        self.imm_i = self._sign_extend((instruction >> 20) & 0xFFF, 12)
        self.imm_s = self._sign_extend(((instruction >> 25) << 5) | ((instruction >> 7) & 0x1F), 12)
        self.imm_b = self._sign_extend(
            ((instruction >> 31) << 12) | (((instruction >> 7) & 0x1) << 11) |
            (((instruction >> 25) & 0x3F) << 5) | (((instruction >> 8) & 0xF) << 1), 13)
        self.imm_u = (instruction >> 12) << 12
        self.imm_j = self._sign_extend(
            ((instruction >> 31) << 20) | (((instruction >> 12) & 0xFF) << 12) |
            (((instruction >> 20) & 0x1) << 11) | (((instruction >> 21) & 0x3FF) << 1), 21)
    
    @staticmethod
    def _sign_extend(value: int, bits: int) -> int:
        """Sign extend a value"""
        if value & (1 << (bits - 1)):
            return value | (-1 << bits)
        return value
    
    def get_instruction_name(self) -> str:
        """Get instruction mnemonic"""
        # Basic instruction decoding
        if self.opcode == 0b0110111:  # LUI
            return "LUI"
        elif self.opcode == 0b0010111:  # AUIPC
            return "AUIPC"
        elif self.opcode == 0b1101111:  # JAL
            return "JAL"
        elif self.opcode == 0b1100111:  # JALR
            return "JALR"
        elif self.opcode == 0b1100011:  # Branch
            branch_names = ["BEQ", "BNE", "", "", "BLT", "BGE", "BLTU", "BGEU"]
            return branch_names[self.funct3] if self.funct3 < len(branch_names) else "BRANCH"
        elif self.opcode == 0b0000011:  # Load
            load_names = ["LB", "LH", "LW", "", "LBU", "LHU", "", ""]
            return load_names[self.funct3] if self.funct3 < len(load_names) else "LOAD"
        elif self.opcode == 0b0100011:  # Store
            store_names = ["SB", "SH", "SW", "", "", "", "", ""]
            return store_names[self.funct3] if self.funct3 < len(store_names) else "STORE"
        elif self.opcode == 0b0010011:  # OP-IMM
            imm_names = ["ADDI", "SLLI", "SLTI", "SLTIU", "XORI", "SRLI/SRAI", "ORI", "ANDI"]
            return imm_names[self.funct3] if self.funct3 < len(imm_names) else "OP-IMM"
        elif self.opcode == 0b0110011:  # OP
            if self.funct7 == 0b0000000:
                op_names = ["ADD", "SLL", "SLT", "SLTU", "XOR", "SRL", "OR", "AND"]
            else:
                op_names = ["SUB", "", "", "", "", "SRA", "", ""]
            return op_names[self.funct3] if self.funct3 < len(op_names) else "OP"
        else:
            return f"UNKNOWN_0x{self.opcode:02x}"

class RV32IReferenceModel:
    """Reference implementation of RV32I processor"""
    
    def __init__(self):
        self.registers = [0] * 32  # 32 registers
        self.memory = bytearray(1024 * 1024)  # 1MB memory
        self.pc = 0
        self.instruction_count = 0
        self.expected_writes = []  # Track expected register/memory writes
        
    def reset(self):
        """Reset processor state"""
        self.registers = [0] * 32
        self.pc = 0
        self.instruction_count = 0
        self.expected_writes.clear()
        
    def execute_instruction(self, pc: int, instruction: int) -> Dict[str, Any]:
        """Execute single instruction and return effects"""
        self.pc = pc
        instr = RV32IInstruction(instruction)
        
        result = {
            'pc': pc,
            'instruction': instruction,
            'name': instr.get_instruction_name(),
            'register_writes': [],
            'memory_writes': [],
            'next_pc': pc + 4
        }
        
        try:
            # Execute based on opcode
            if instr.opcode == 0b0110111:  # LUI
                self._execute_lui(instr, result)
            elif instr.opcode == 0b0010111:  # AUIPC
                self._execute_auipc(instr, result)
            elif instr.opcode == 0b1101111:  # JAL
                self._execute_jal(instr, result)
            elif instr.opcode == 0b1100111:  # JALR
                self._execute_jalr(instr, result)
            elif instr.opcode == 0b1100011:  # Branch
                self._execute_branch(instr, result)
            elif instr.opcode == 0b0000011:  # Load
                self._execute_load(instr, result)
            elif instr.opcode == 0b0100011:  # Store
                self._execute_store(instr, result)
            elif instr.opcode == 0b0010011:  # OP-IMM
                self._execute_op_imm(instr, result)
            elif instr.opcode == 0b0110011:  # OP
                self._execute_op(instr, result)
            else:
                logger.warning(f"Unimplemented instruction: 0x{instruction:08x}")
                
        except Exception as e:
            logger.error(f"Error executing instruction 0x{instruction:08x}: {e}")
            
        self.instruction_count += 1
        return result
    
    def _execute_lui(self, instr, result):
        """Execute LUI instruction"""
        if instr.rd != 0:
            self.registers[instr.rd] = instr.imm_u
            result['register_writes'].append({'register': instr.rd, 'value': instr.imm_u})
    
    def _execute_auipc(self, instr, result):
        """Execute AUIPC instruction"""
        if instr.rd != 0:
            value = self.pc + instr.imm_u
            self.registers[instr.rd] = value & 0xFFFFFFFF
            result['register_writes'].append({'register': instr.rd, 'value': value & 0xFFFFFFFF})
    
    def _execute_jal(self, instr, result):
        """Execute JAL instruction"""
        if instr.rd != 0:
            self.registers[instr.rd] = (self.pc + 4) & 0xFFFFFFFF
            result['register_writes'].append({'register': instr.rd, 'value': (self.pc + 4) & 0xFFFFFFFF})
        result['next_pc'] = (self.pc + instr.imm_j) & 0xFFFFFFFF
    
    def _execute_jalr(self, instr, result):
        """Execute JALR instruction"""
        target = (self.registers[instr.rs1] + instr.imm_i) & 0xFFFFFFFE
        if instr.rd != 0:
            self.registers[instr.rd] = (self.pc + 4) & 0xFFFFFFFF
            result['register_writes'].append({'register': instr.rd, 'value': (self.pc + 4) & 0xFFFFFFFF})
        result['next_pc'] = target
    
    def _execute_branch(self, instr, result):
        """Execute branch instructions"""
        rs1_val = self.registers[instr.rs1]
        rs2_val = self.registers[instr.rs2]
        
        taken = False
        if instr.funct3 == 0b000:  # BEQ
            taken = rs1_val == rs2_val
        elif instr.funct3 == 0b001:  # BNE
            taken = rs1_val != rs2_val
        elif instr.funct3 == 0b100:  # BLT
            taken = self._signed(rs1_val) < self._signed(rs2_val)
        elif instr.funct3 == 0b101:  # BGE
            taken = self._signed(rs1_val) >= self._signed(rs2_val)
        elif instr.funct3 == 0b110:  # BLTU
            taken = rs1_val < rs2_val
        elif instr.funct3 == 0b111:  # BGEU
            taken = rs1_val >= rs2_val
            
        if taken:
            result['next_pc'] = (self.pc + instr.imm_b) & 0xFFFFFFFF
    
    def _execute_load(self, instr, result):
        """Execute load instructions"""
        addr = (self.registers[instr.rs1] + instr.imm_i) & 0xFFFFFFFF
        
        if instr.funct3 == 0b000:  # LB
            value = self._sign_extend(self._load_byte(addr), 8)
        elif instr.funct3 == 0b001:  # LH  
            value = self._sign_extend(self._load_halfword(addr), 16)
        elif instr.funct3 == 0b010:  # LW
            value = self._load_word(addr)
        elif instr.funct3 == 0b100:  # LBU
            value = self._load_byte(addr)
        elif instr.funct3 == 0b101:  # LHU
            value = self._load_halfword(addr)
        else:
            value = 0
            
        if instr.rd != 0:
            self.registers[instr.rd] = value & 0xFFFFFFFF
            result['register_writes'].append({'register': instr.rd, 'value': value & 0xFFFFFFFF})
    
    def _execute_store(self, instr, result):
        """Execute store instructions"""
        addr = (self.registers[instr.rs1] + instr.imm_s) & 0xFFFFFFFF
        data = self.registers[instr.rs2]
        
        if instr.funct3 == 0b000:  # SB
            self._store_byte(addr, data)
            result['memory_writes'].append({'address': addr, 'data': data & 0xFF, 'size': 1})
        elif instr.funct3 == 0b001:  # SH
            self._store_halfword(addr, data)
            result['memory_writes'].append({'address': addr, 'data': data & 0xFFFF, 'size': 2})
        elif instr.funct3 == 0b010:  # SW
            self._store_word(addr, data)
            result['memory_writes'].append({'address': addr, 'data': data & 0xFFFFFFFF, 'size': 4})
    
    def _execute_op_imm(self, instr, result):
        """Execute immediate ALU operations"""
        rs1_val = self.registers[instr.rs1]
        
        if instr.funct3 == 0b000:  # ADDI
            value = (rs1_val + instr.imm_i) & 0xFFFFFFFF
        elif instr.funct3 == 0b010:  # SLTI
            value = 1 if self._signed(rs1_val) < self._signed(instr.imm_i) else 0
        elif instr.funct3 == 0b011:  # SLTIU
            value = 1 if rs1_val < (instr.imm_i & 0xFFFFFFFF) else 0
        elif instr.funct3 == 0b100:  # XORI
            value = rs1_val ^ instr.imm_i
        elif instr.funct3 == 0b110:  # ORI
            value = rs1_val | instr.imm_i
        elif instr.funct3 == 0b111:  # ANDI
            value = rs1_val & instr.imm_i
        elif instr.funct3 == 0b001:  # SLLI
            shamt = instr.imm_i & 0x1F
            value = (rs1_val << shamt) & 0xFFFFFFFF
        elif instr.funct3 == 0b101:  # SRLI/SRAI
            shamt = instr.imm_i & 0x1F
            if instr.funct7 == 0b0100000:  # SRAI
                value = self._signed(rs1_val) >> shamt
                if value < 0:
                    value = (value + (1 << 32)) & 0xFFFFFFFF
            else:  # SRLI
                value = rs1_val >> shamt
        else:
            value = 0
            
        if instr.rd != 0:
            self.registers[instr.rd] = value & 0xFFFFFFFF
            result['register_writes'].append({'register': instr.rd, 'value': value & 0xFFFFFFFF})
    
    def _execute_op(self, instr, result):
        """Execute register ALU operations"""
        rs1_val = self.registers[instr.rs1]
        rs2_val = self.registers[instr.rs2]
        
        if instr.funct3 == 0b000:
            if instr.funct7 == 0b0000000:  # ADD
                value = (rs1_val + rs2_val) & 0xFFFFFFFF
            else:  # SUB
                value = (rs1_val - rs2_val) & 0xFFFFFFFF
        elif instr.funct3 == 0b001:  # SLL
            value = (rs1_val << (rs2_val & 0x1F)) & 0xFFFFFFFF
        elif instr.funct3 == 0b010:  # SLT
            value = 1 if self._signed(rs1_val) < self._signed(rs2_val) else 0
        elif instr.funct3 == 0b011:  # SLTU
            value = 1 if rs1_val < rs2_val else 0
        elif instr.funct3 == 0b100:  # XOR
            value = rs1_val ^ rs2_val
        elif instr.funct3 == 0b101:
            if instr.funct7 == 0b0000000:  # SRL
                value = rs1_val >> (rs2_val & 0x1F)
            else:  # SRA
                value = self._signed(rs1_val) >> (rs2_val & 0x1F)
                if value < 0:
                    value = (value + (1 << 32)) & 0xFFFFFFFF
        elif instr.funct3 == 0b110:  # OR
            value = rs1_val | rs2_val
        elif instr.funct3 == 0b111:  # AND
            value = rs1_val & rs2_val
        else:
            value = 0
            
        if instr.rd != 0:
            self.registers[instr.rd] = value & 0xFFFFFFFF
            result['register_writes'].append({'register': instr.rd, 'value': value & 0xFFFFFFFF})
    
    def _signed(self, value: int) -> int:
        """Convert unsigned to signed 32-bit"""
        if value & 0x80000000:
            return value - (1 << 32)
        return value
    
    def _load_byte(self, addr: int) -> int:
        """Load byte from memory"""
        if addr < len(self.memory):
            return self.memory[addr]
        return 0
    
    def _load_halfword(self, addr: int) -> int:
        """Load halfword from memory"""
        if addr + 1 < len(self.memory):
            return struct.unpack('<H', self.memory[addr:addr+2])[0]
        return 0
    
    def _load_word(self, addr: int) -> int:
        """Load word from memory"""
        if addr + 3 < len(self.memory):
            return struct.unpack('<I', self.memory[addr:addr+4])[0]
        return 0
    
    def _store_byte(self, addr: int, data: int):
        """Store byte to memory"""
        if addr < len(self.memory):
            self.memory[addr] = data & 0xFF
    
    def _store_halfword(self, addr: int, data: int):
        """Store halfword to memory"""
        if addr + 1 < len(self.memory):
            self.memory[addr:addr+2] = struct.pack('<H', data & 0xFFFF)
    
    def _store_word(self, addr: int, data: int):
        """Store word to memory"""
        if addr + 3 < len(self.memory):
            self.memory[addr:addr+4] = struct.pack('<I', data & 0xFFFFFFFF)
    
    def get_expected_register_value(self, reg_num: int) -> Optional[int]:
        """Get expected register value"""
        if 0 <= reg_num < 32:
            return self.registers[reg_num]
        return None
    
    def get_expected_memory_write(self, addr: int) -> Optional[Dict[str, Any]]:
        """Get expected memory write for address"""
        # This would track expected memory writes
        return None
