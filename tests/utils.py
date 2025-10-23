# ==============================================================================
# utils.py - Utility Functions and Helpers
# ==============================================================================

import logging
import time
from typing import Dict, List, Any, Optional
from dataclasses import dataclass
import json

# Configure logging
def setup_logging(level=logging.INFO, log_file=None):
    """Setup logging configuration"""
    # Remove any existing handlers to avoid duplicates and resource leaks
    root_logger = logging.getLogger()
    for handler in root_logger.handlers[:]:
        handler.close()
        root_logger.removeHandler(handler)
    
    formatter = logging.Formatter(
        '%(asctime)s - %(name)s - %(levelname)s - %(message)s'
    )
    
    # Console handler
    console_handler = logging.StreamHandler()
    console_handler.setFormatter(formatter)
    
    # Setup handlers list
    handlers = [console_handler]
    
    # File handler (optional)
    if log_file:
        file_handler = logging.FileHandler(log_file, mode='w')  # 'w' to overwrite
        file_handler.setFormatter(formatter)
        handlers.append(file_handler)
    
    # Configure root logger
    root_logger.setLevel(level)
    for handler in handlers:
        root_logger.addHandler(handler)

class RV32IInstructionEncoder:
    """Utility class for encoding RV32I instructions"""
    
    @staticmethod
    def encode_r_type(opcode: int, rd: int, funct3: int, rs1: int, rs2: int, funct7: int) -> int:
        """Encode R-type instruction"""
        return (funct7 << 25) | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode
    
    @staticmethod
    def encode_i_type(opcode: int, rd: int, funct3: int, rs1: int, imm: int) -> int:
        """Encode I-type instruction"""
        return ((imm & 0xFFF) << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode
    
    @staticmethod
    def encode_s_type(opcode: int, funct3: int, rs1: int, rs2: int, imm: int) -> int:
        """Encode S-type instruction"""
        imm_11_5 = (imm >> 5) & 0x7F
        imm_4_0 = imm & 0x1F
        return (imm_11_5 << 25) | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | (imm_4_0 << 7) | opcode
    
    @staticmethod
    def encode_b_type(opcode: int, funct3: int, rs1: int, rs2: int, imm: int) -> int:
        """Encode B-type instruction"""
        imm_12 = (imm >> 12) & 0x1
        imm_10_5 = (imm >> 5) & 0x3F
        imm_4_1 = (imm >> 1) & 0xF
        imm_11 = (imm >> 11) & 0x1
        return (imm_12 << 31) | (imm_10_5 << 25) | (rs2 << 20) | (rs1 << 15) | \
               (funct3 << 12) | (imm_4_1 << 8) | (imm_11 << 7) | opcode
    
    @staticmethod
    def encode_u_type(opcode: int, rd: int, imm: int) -> int:
        """Encode U-type instruction"""
        return ((imm >> 12) << 12) | (rd << 7) | opcode
    
    @staticmethod
    def encode_j_type(opcode: int, rd: int, imm: int) -> int:
        """Encode J-type instruction"""
        imm_20 = (imm >> 20) & 0x1
        imm_10_1 = (imm >> 1) & 0x3FF
        imm_11 = (imm >> 11) & 0x1
        imm_19_12 = (imm >> 12) & 0xFF
        return (imm_20 << 31) | (imm_19_12 << 12) | (imm_11 << 11) | (imm_10_1 << 1) | (rd << 7) | opcode

class RV32IInstructionFactory:
    """Factory for creating common RV32I instructions"""
    
    @staticmethod
    def create_add(rd: int, rs1: int, rs2: int) -> int:
        return RV32IInstructionEncoder.encode_r_type(0b0110011, rd, 0b000, rs1, rs2, 0b0000000)
    
    @staticmethod
    def create_sub(rd: int, rs1: int, rs2: int) -> int:
        return RV32IInstructionEncoder.encode_r_type(0b0110011, rd, 0b000, rs1, rs2, 0b0100000)
    
    @staticmethod
    def create_addi(rd: int, rs1: int, imm: int) -> int:
        return RV32IInstructionEncoder.encode_i_type(0b0010011, rd, 0b000, rs1, imm)
    
    @staticmethod
    def create_lw(rd: int, rs1: int, imm: int) -> int:
        return RV32IInstructionEncoder.encode_i_type(0b0000011, rd, 0b010, rs1, imm)
    
    @staticmethod
    def create_sw(rs1: int, rs2: int, imm: int) -> int:
        return RV32IInstructionEncoder.encode_s_type(0b0100011, 0b010, rs1, rs2, imm)
    
    @staticmethod
    def create_beq(rs1: int, rs2: int, imm: int) -> int:
        return RV32IInstructionEncoder.encode_b_type(0b1100011, 0b000, rs1, rs2, imm)
    
    @staticmethod
    def create_bne(rs1: int, rs2: int, imm: int) -> int:
        return RV32IInstructionEncoder.encode_b_type(0b1100011, 0b001, rs1, rs2, imm)
    
    @staticmethod
    def create_blt(rs1: int, rs2: int, imm: int) -> int:
        return RV32IInstructionEncoder.encode_b_type(0b1100011, 0b100, rs1, rs2, imm)
    
    @staticmethod
    def create_bge(rs1: int, rs2: int, imm: int) -> int:
        return RV32IInstructionEncoder.encode_b_type(0b1100011, 0b101, rs1, rs2, imm)
    
    @staticmethod
    def create_jal(rd: int, imm: int) -> int:
        return RV32IInstructionEncoder.encode_j_type(0b1101111, rd, imm)
    
    @staticmethod
    def create_jalr(rd: int, rs1: int, imm: int) -> int:
        return RV32IInstructionEncoder.encode_i_type(0b1100111, rd, 0b000, rs1, imm)
    
    @staticmethod
    def create_lui(rd: int, imm: int) -> int:
        return RV32IInstructionEncoder.encode_u_type(0b0110111, rd, imm)
    
    @staticmethod
    def create_auipc(rd: int, imm: int) -> int:
        return RV32IInstructionEncoder.encode_u_type(0b0010111, rd, imm)
    
    @staticmethod
    def create_nop() -> int:
        return RV32IInstructionFactory.create_addi(0, 0, 0)

class PerformanceAnalyzer:
    """Analyze processor performance metrics"""
    
    def __init__(self):
        self.reset()
    
    def reset(self):
        self.start_time = time.time()
        self.cycles = 0
        self.instructions = 0
        self.hazards = 0
        self.stalls = 0
        self.branches = 0
        self.branch_mispredicts = 0
        
    def update(self, cycles: int, instructions: int, hazards: int = 0, 
               stalls: int = 0, branches: int = 0, mispredicts: int = 0):
        self.cycles = cycles
        self.instructions = instructions
        self.hazards = hazards
        self.stalls = stalls
        self.branches = branches
        self.branch_mispredicts = mispredicts
        
    def get_metrics(self) -> Dict[str, float]:
        """Calculate performance metrics"""
        metrics = {}
        
        if self.instructions > 0:
            metrics['cpi'] = self.cycles / self.instructions
            metrics['ipc'] = self.instructions / self.cycles
        else:
            metrics['cpi'] = 0
            metrics['ipc'] = 0
            
        if self.branches > 0:
            metrics['branch_miss_rate'] = self.branch_mispredicts / self.branches
        else:
            metrics['branch_miss_rate'] = 0
            
        metrics['stall_rate'] = self.stalls / max(self.cycles, 1)
        metrics['hazard_rate'] = self.hazards / max(self.cycles, 1)
        
        elapsed_time = time.time() - self.start_time
        if elapsed_time > 0:
            metrics['simulation_speed'] = self.cycles / elapsed_time
        else:
            metrics['simulation_speed'] = 0
            
        return metrics

class TestProgramGenerator:
    """Generate test programs for specific scenarios"""
    
    @staticmethod
    def generate_arithmetic_test() -> List[int]:
        """Generate arithmetic instruction test"""
        factory = RV32IInstructionFactory()
        return [
            factory.create_addi(1, 0, 10),      # x1 = 10
            factory.create_addi(2, 0, 20),      # x2 = 20
            factory.create_add(3, 1, 2),        # x3 = x1 + x2 = 30
            factory.create_sub(4, 2, 1),        # x4 = x2 - x1 = 10
            factory.create_addi(5, 3, -5),      # x5 = x3 - 5 = 25
            factory.create_nop(),                # NOP for pipeline flush
        ]
    
    @staticmethod
    def generate_memory_test() -> List[int]:
        """Generate memory access test"""
        factory = RV32IInstructionFactory()
        return [
            factory.create_addi(1, 0, 0x100),   # x1 = base address 0x100
            factory.create_addi(2, 0, 0x42),    # x2 = test data 0x42
            factory.create_sw(1, 2, 0),         # store x2 to [x1+0]
            factory.create_nop(),                # Pipeline delay
            factory.create_lw(3, 1, 0),         # load [x1+0] to x3
            factory.create_sw(1, 3, 4),         # store x3 to [x1+4]
            factory.create_nop(),                # Pipeline delay
            factory.create_lw(4, 1, 4),         # load [x1+4] to x4
            factory.create_nop(),                # NOP for completion
        ]
    
    @staticmethod
    def generate_branch_test() -> List[int]:
        """Generate branch instruction test"""
        factory = RV32IInstructionFactory()
        return [
            factory.create_addi(1, 0, 5),       # x1 = 5
            factory.create_addi(2, 0, 5),       # x2 = 5
            factory.create_beq(1, 2, 8),        # if x1 == x2, jump forward
            factory.create_addi(3, 0, 1),       # x3 = 1 (should be skipped)
            factory.create_addi(3, 0, 10),      # x3 = 10 (branch target)
            factory.create_nop(),                # NOP
        ]
    
    @staticmethod
    def generate_hazard_test() -> List[int]:
        """Generate data hazard test"""
        factory = RV32IInstructionFactory()
        return [
            factory.create_addi(1, 0, 10),      # x1 = 10
            factory.create_add(2, 1, 1),        # x2 = x1 + x1 = 20 (RAW hazard on x1)
            factory.create_add(3, 2, 1),        # x3 = x2 + x1 = 30 (RAW hazard on x2)
            factory.create_sub(4, 3, 2),        # x4 = x3 - x2 = 10 (RAW hazard on x3)
            factory.create_addi(5, 4, 5),       # x5 = x4 + 5 = 15 (RAW hazard on x4)
            factory.create_nop(),                # NOP for completion
        ]

def generate_test_report(mismatches: List, performance_stats: Dict, 
                        output_file: str = "test_report.json"):
    """Generate comprehensive test report"""
    report = {
        'timestamp': time.strftime('%Y-%m-%d %H:%M:%S'),
        'performance': performance_stats,
        'functional_verification': {
            'total_mismatches': len(mismatches),
            'mismatch_breakdown': {},
            'mismatches': []
        }
    }
    
    # Categorize mismatches
    for mismatch in mismatches:
        mtype = mismatch.mismatch_type.value if hasattr(mismatch.mismatch_type, 'value') else str(mismatch.mismatch_type)
        if mtype not in report['functional_verification']['mismatch_breakdown']:
            report['functional_verification']['mismatch_breakdown'][mtype] = 0
        report['functional_verification']['mismatch_breakdown'][mtype] += 1
        
        # Add mismatch details
        report['functional_verification']['mismatches'].append({
            'cycle': mismatch.cycle,
            'type': mtype,
            'pc': f"0x{mismatch.pc:08x}",
            'instruction': f"0x{mismatch.instruction:08x}",
            'expected': mismatch.expected,
            'actual': mismatch.actual,
            'description': mismatch.description
        })
    
    # Write report
    with open(output_file, 'w') as f:
        json.dump(report, f, indent=2)
    
    return report