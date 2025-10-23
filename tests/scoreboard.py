# ==============================================================================
# scoreboard.py - Functional Correctness Checking
# ==============================================================================

import cocotb
from cocotb.triggers import RisingEdge
from typing import Dict, List, Any, Optional, Tuple
import logging
from dataclasses import dataclass
from enum import Enum

logger = logging.getLogger(__name__)

class MismatchType(Enum):
    REGISTER_WRITE = "register_write"
    MEMORY_WRITE = "memory_write"
    MEMORY_READ = "memory_read"
    CONTROL_FLOW = "control_flow"

@dataclass
class Mismatch:
    """Represents a mismatch between expected and actual behavior"""
    cycle: int
    mismatch_type: MismatchType
    pc: int
    instruction: int
    expected: Any
    actual: Any
    register_id: Optional[int] = None
    memory_addr: Optional[int] = None
    description: str = ""

class ExpectedTransaction:
    """Expected transaction for comparison"""
    def __init__(self, cycle: int, transaction_type: str, **kwargs):
        self.cycle = cycle
        self.type = transaction_type
        self.data = kwargs

class RV32IScoreboard:
    """Scoreboard for functional verification"""
    
    def __init__(self, dut, reference_model):
        self.dut = dut
        self.reference_model = reference_model
        self.mismatches = []
        self.expected_transactions = []
        self.cycle_count = 0
        self.checking_enabled = True
        
    async def check_functional_correctness(self, monitor):
        """Main checking loop"""
        while True:
            await RisingEdge(self.dut.Clk_In)
            self.cycle_count += 1
            
            if not self.checking_enabled:
                continue
                
            # Get latest snapshot from monitor
            if monitor.snapshots:
                snapshot = monitor.snapshots[-1]
                
                # Check register writes
                await self._check_register_writes(snapshot, monitor)
                
                # Check memory transactions
                await self._check_memory_transactions(snapshot, monitor)
                
                # Update reference model
                self._update_reference_model(snapshot)
                
    async def _check_register_writes(self, snapshot, monitor):
        """Check register write correctness"""
        # This would need access to register file or writeback signals
        # For now, we'll check against expected values from reference model
        
        # Example: if we can observe a register write
        if hasattr(self.dut, 'wb_reg_write') and self.dut.wb_reg_write.value:
            reg_num = int(self.dut.wb_reg_addr.value) if hasattr(self.dut, 'wb_reg_addr') else 0
            actual_value = int(self.dut.wb_reg_data.value) if hasattr(self.dut, 'wb_reg_data') else 0
            
            expected_value = self.reference_model.get_expected_register_value(reg_num)
            
            if expected_value is not None and actual_value != expected_value:
                mismatch = Mismatch(
                    cycle=self.cycle_count,
                    mismatch_type=MismatchType.REGISTER_WRITE,
                    pc=snapshot.instruction_addr,
                    instruction=snapshot.instruction,
                    expected=expected_value,
                    actual=actual_value,
                    register_id=reg_num,
                    description=f"Register x{reg_num} write mismatch"
                )
                self.mismatches.append(mismatch)
                logger.error(f"Register write mismatch: {mismatch}")
                
    async def _check_memory_transactions(self, snapshot, monitor):
        """Check memory transaction correctness"""
        if snapshot.dm_write_enable:
            # Check if this memory write was expected
            expected_write = self.reference_model.get_expected_memory_write(
                snapshot.dm_addr
            )
            
            if expected_write is not None:
                if expected_write['data'] != snapshot.dm_data_out:
                    mismatch = Mismatch(
                        cycle=self.cycle_count,
                        mismatch_type=MismatchType.MEMORY_WRITE,
                        pc=snapshot.instruction_addr,
                        instruction=snapshot.instruction,
                        expected=expected_write['data'],
                        actual=snapshot.dm_data_out,
                        memory_addr=snapshot.dm_addr,
                        description=f"Memory write mismatch at 0x{snapshot.dm_addr:08x}"
                    )
                    self.mismatches.append(mismatch)
                    logger.error(f"Memory write mismatch: {mismatch}")
                    
    def _update_reference_model(self, snapshot):
        """Update reference model with observed instruction"""
        if snapshot.instruction != 0:
            self.reference_model.execute_instruction(
                snapshot.instruction_addr,
                snapshot.instruction
            )
            
    def add_expected_transaction(self, transaction: ExpectedTransaction):
        """Add expected transaction for future checking"""
        self.expected_transactions.append(transaction)
        
    def get_mismatch_summary(self) -> Dict[str, Any]:
        """Get summary of all mismatches"""
        summary = {
            'total_mismatches': len(self.mismatches),
            'register_mismatches': len([m for m in self.mismatches 
                                       if m.mismatch_type == MismatchType.REGISTER_WRITE]),
            'memory_mismatches': len([m for m in self.mismatches 
                                     if m.mismatch_type in [MismatchType.MEMORY_WRITE, 
                                                           MismatchType.MEMORY_READ]]),
            'control_mismatches': len([m for m in self.mismatches 
                                      if m.mismatch_type == MismatchType.CONTROL_FLOW]),
            'mismatches': self.mismatches
        }
        return summary
        
    def enable_checking(self, enabled: bool = True):
        """Enable or disable functional checking"""
        self.checking_enabled = enabled
        
    def reset_scoreboard(self):
        """Reset scoreboard state"""
        self.mismatches.clear()
        self.expected_transactions.clear()
        self.cycle_count = 0
