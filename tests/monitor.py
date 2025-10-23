# ==============================================================================
# monitor.py - Pipeline State Monitor
# ==============================================================================

import cocotb
from cocotb.triggers import RisingEdge
from typing import Dict, Any, List, Optional
import logging
from dataclasses import dataclass, field

logger = logging.getLogger(__name__)

@dataclass
class PipelineSnapshot:
    """Snapshot of pipeline state at a given cycle"""
    cycle: int
    pc: int = 0
    instruction: int = 0
    instruction_addr: int = 0
    
    # Memory interface
    dm_addr: int = 0
    dm_data_out: int = 0
    dm_data_in: int = 0
    dm_write_enable: bool = False
    dm_mask: int = 0
    
    # Pipeline stage data (if accessible)
    fetch_data: Dict[str, Any] = field(default_factory=dict)
    decode_data: Dict[str, Any] = field(default_factory=dict)
    execute_data: Dict[str, Any] = field(default_factory=dict)
    memory_data: Dict[str, Any] = field(default_factory=dict)
    writeback_data: Dict[str, Any] = field(default_factory=dict)
    
    # Hazard and control signals
    hazard_detected: bool = False
    stall: bool = False
    flush: bool = False

class RegisterFileMonitor:
    """Monitor register file writes"""
    
    def __init__(self):
        self.register_writes = []
        self.current_state = [0] * 32
        
    def record_write(self, cycle: int, reg_num: int, value: int):
        """Record a register write"""
        if 0 <= reg_num < 32:
            self.register_writes.append({
                'cycle': cycle,
                'register': reg_num,
                'value': value,
                'old_value': self.current_state[reg_num]
            })
            # x0 is always 0 in RISC-V
            if reg_num != 0:
                self.current_state[reg_num] = value
                
    def get_register_value(self, reg_num: int) -> int:
        """Get current register value"""
        if 0 <= reg_num < 32:
            return self.current_state[reg_num]
        return 0

class MemoryMonitor:
    """Monitor memory transactions"""
    
    def __init__(self):
        self.transactions = []
        
    def record_transaction(self, cycle: int, addr: int, data: int, 
                         write_enable: bool, mask: int = 0xF):
        """Record memory transaction"""
        self.transactions.append({
            'cycle': cycle,
            'address': addr,
            'data': data,
            'write': write_enable,
            'mask': mask
        })

class RV32IPipelineMonitor:
    """Comprehensive pipeline monitor"""
    
    def __init__(self, dut):
        self.dut = dut
        self.snapshots = []
        self.reg_monitor = RegisterFileMonitor()
        self.mem_monitor = MemoryMonitor()
        self.cycle_count = 0
        self.instruction_count = 0
        
        # Performance counters
        self.hazard_count = 0
        self.stall_count = 0
        self.flush_count = 0
        self.branch_count = 0
        self.branch_taken_count = 0
        
    async def monitor_pipeline(self):
        """Main monitoring loop"""
        while True:
            await RisingEdge(self.dut.Clk_In)
            self.cycle_count += 1
            
            # Create pipeline snapshot
            snapshot = self._capture_snapshot()
            self.snapshots.append(snapshot)
            
            # Monitor specific events
            self._monitor_memory_transactions(snapshot)
            self._monitor_hazards(snapshot)
            self._monitor_control_flow(snapshot)
            
            # Keep only recent snapshots to save memory
            if len(self.snapshots) > 1000:
                self.snapshots.pop(0)
                
    def _capture_snapshot(self) -> PipelineSnapshot:
        """Capture current pipeline state"""
        snapshot = PipelineSnapshot(cycle=self.cycle_count)
        
        # Capture basic signals
        try:
            if hasattr(self.dut, 'Instr_Addr_Out'):
                snapshot.instruction_addr = int(self.dut.Instr_Addr_Out.value)
                
            if hasattr(self.dut, 'Instruction_In'):
                snapshot.instruction = int(self.dut.Instruction_In.value)
                
            # Memory interface
            if hasattr(self.dut, 'DM_Addr_Out'):
                snapshot.dm_addr = int(self.dut.DM_Addr_Out.value)
            if hasattr(self.dut, 'DM_Data_Out'):
                snapshot.dm_data_out = int(self.dut.DM_Data_Out.value)
            if hasattr(self.dut, 'DM_Data_In'):
                snapshot.dm_data_in = int(self.dut.DM_Data_In.value)
            if hasattr(self.dut, 'DM_WrEn_Out'):
                snapshot.dm_write_enable = bool(self.dut.DM_WrEn_Out.value)
            if hasattr(self.dut, 'DM_Mask_Out'):
                snapshot.dm_mask = int(self.dut.DM_Mask_Out.value)
                
            # Hazard signals (if exposed)
            if hasattr(self.dut, 'hazard_detected'):
                snapshot.hazard_detected = bool(self.dut.hazard_detected.value)
            if hasattr(self.dut, 'stall'):
                snapshot.stall = bool(self.dut.stall.value)
            if hasattr(self.dut, 'flush'):
                snapshot.flush = bool(self.dut.flush.value)
                
        except Exception as e:
            logger.warning(f"Error capturing snapshot: {e}")
            
        return snapshot
        
    def _monitor_memory_transactions(self, snapshot: PipelineSnapshot):
        """Monitor memory transactions"""
        if snapshot.dm_write_enable and snapshot.dm_addr != 0:
            self.mem_monitor.record_transaction(
                self.cycle_count,
                snapshot.dm_addr,
                snapshot.dm_data_out,
                True,
                snapshot.dm_mask
            )
            
    def _monitor_hazards(self, snapshot: PipelineSnapshot):
        """Monitor pipeline hazards"""
        if snapshot.hazard_detected:
            self.hazard_count += 1
        if snapshot.stall:
            self.stall_count += 1
        if snapshot.flush:
            self.flush_count += 1
            
    def _monitor_control_flow(self, snapshot: PipelineSnapshot):
        """Monitor control flow changes"""
        # This would need to be implemented based on available signals
        # For now, just count instructions
        if snapshot.instruction != 0:
            self.instruction_count += 1
            
    def get_performance_stats(self) -> Dict[str, Any]:
        """Get performance statistics"""
        cpi = self.cycle_count / max(self.instruction_count, 1)
        
        return {
            'cycles': self.cycle_count,
            'instructions': self.instruction_count,
            'cpi': cpi,
            'hazards': self.hazard_count,
            'stalls': self.stall_count,
            'flushes': self.flush_count,
            'branches': self.branch_count,
            'branches_taken': self.branch_taken_count
        }
        
    def get_recent_snapshots(self, count: int = 10) -> List[PipelineSnapshot]:
        """Get recent pipeline snapshots"""
        return self.snapshots[-count:] if len(self.snapshots) >= count else self.snapshots[:]
