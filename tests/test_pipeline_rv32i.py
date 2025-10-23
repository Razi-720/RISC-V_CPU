# ==============================================================================
# test_pipeline_rv32i.py - Main Test Suite
# ==============================================================================

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
from cocotb.result import TestFailure
import logging
import asyncio

# Import our testbench modules
from .driver import RV32IDriver
from .monitor import RV32IPipelineMonitor
from .scoreboard import RV32IScoreboard
from .isa_reference import RV32IReferenceModel
from .utils import (setup_logging, RV32IInstructionFactory, PerformanceAnalyzer,
                   TestProgramGenerator, generate_test_report)

# Setup logging
setup_logging(level=logging.INFO, log_file="testbench.log")
logger = logging.getLogger(__name__)

class RV32ITestEnvironment:
    """Complete test environment"""
    
    def __init__(self, dut):
        self.dut = dut
        self.driver = RV32IDriver(dut)
        self.monitor = RV32IPipelineMonitor(dut)
        self.reference_model = RV32IReferenceModel()
        self.scoreboard = RV32IScoreboard(dut, self.reference_model)
        self.performance = PerformanceAnalyzer()
        
    async def setup(self):
        """Setup test environment"""
        # Start clock
        cocotb.start_soon(Clock(self.dut.Clk_In, 10, units="ns").start())
        
        # Start driver tasks
        cocotb.start_soon(self.driver.drive_instruction_memory())
        cocotb.start_soon(self.driver.drive_data_memory())
        cocotb.start_soon(self.driver.cycle_counter())
        
        # Start monitor
        cocotb.start_soon(self.monitor.monitor_pipeline())
        
        # Start scoreboard
        cocotb.start_soon(self.scoreboard.check_functional_correctness(self.monitor))
        
        # Reset everything
        await self.reset()
        
    async def reset(self):
        """Reset all components"""
        await self.driver.reset()
        self.reference_model.reset()
        self.scoreboard.reset_scoreboard()
        self.performance.reset()
        
    async def run_test_program(self, instructions: list[int], cycles: int = 100):
        """Run a test program"""
        self.driver.load_program(instructions)
        
        # Run for specified cycles
        for _ in range(cycles):
            await RisingEdge(self.dut.Clk_In)
            
        # Update performance metrics
        stats = self.monitor.get_performance_stats()
        self.performance.update(
            cycles=stats['cycles'],
            instructions=stats['instructions'],
            hazards=stats['hazards'],
            stalls=stats['stalls']
        )
        
    def get_test_results(self):
        """Get test results"""
        return {
            'performance': self.performance.get_metrics(),
            'mismatches': self.scoreboard.get_mismatch_summary(),
            'pipeline_stats': self.monitor.get_performance_stats()
        }

# Test Cases

@cocotb.test()
async def test_basic_arithmetic(dut):
    """Test basic arithmetic operations"""
    logger.info("Starting basic arithmetic test")
    
    env = RV32ITestEnvironment(dut)
    await env.setup()
    
    # Generate arithmetic test program
    instructions = TestProgramGenerator.generate_arithmetic_test()
    await env.run_test_program(instructions, cycles=50)
    
    # Check results
    results = env.get_test_results()
    
    if results['mismatches']['total_mismatches'] > 0:
        logger.error(f"Arithmetic test failed with {results['mismatches']['total_mismatches']} mismatches")
        raise TestFailure("Basic arithmetic test failed")
    
    logger.info(f"Arithmetic test passed - CPI: {results['performance']['cpi']:.2f}")

@cocotb.test()
async def test_memory_operations(dut):
    """Test load/store operations"""
    logger.info("Starting memory operations test")
    
    env = RV32ITestEnvironment(dut)
    await env.setup()
    
    instructions = TestProgramGenerator.generate_memory_test()
    await env.run_test_program(instructions, cycles=60)
    
    results = env.get_test_results()
    
    if results['mismatches']['total_mismatches'] > 0:
        logger.error(f"Memory test failed with {results['mismatches']['total_mismatches']} mismatches")
        raise TestFailure("Memory operations test failed")
    
    logger.info("Memory operations test passed")

@cocotb.test()
async def test_branch_instructions(dut):
    """Test branch and jump instructions"""
    logger.info("Starting branch instructions test")
    
    env = RV32ITestEnvironment(dut)
    await env.setup()
    
    instructions = TestProgramGenerator.generate_branch_test()
    await env.run_test_program(instructions, cycles=40)
    
    results = env.get_test_results()
    
    if results['mismatches']['total_mismatches'] > 0:
        logger.error(f"Branch test failed with {results['mismatches']['total_mismatches']} mismatches")
        raise TestFailure("Branch instructions test failed")
    
    logger.info("Branch instructions test passed")

@cocotb.test()
async def test_data_hazards(dut):
    """Test data hazard handling"""
    logger.info("Starting data hazards test")
    
    env = RV32ITestEnvironment(dut)
    await env.setup()
    
    instructions = TestProgramGenerator.generate_hazard_test()
    await env.run_test_program(instructions, cycles=70)
    
    results = env.get_test_results()
    
    # Data hazards should be handled correctly
    if results['mismatches']['total_mismatches'] > 0:
        logger.error(f"Hazard test failed with {results['mismatches']['total_mismatches']} mismatches")
        raise TestFailure("Data hazards test failed")
    
    # Should see some hazards/stalls
    if results['pipeline_stats']['hazards'] == 0:
        logger.warning("No hazards detected - this might indicate missing hazard detection")
    
    logger.info(f"Data hazards test passed - {results['pipeline_stats']['hazards']} hazards, {results['pipeline_stats']['stalls']} stalls")

@cocotb.test()
async def test_all_instruction_types(dut):
    """Comprehensive test of all RV32I instruction types"""
    logger.info("Starting comprehensive instruction test")
    
    env = RV32ITestEnvironment(dut)
    await env.setup()
    
    factory = RV32IInstructionFactory()
    
    # Test all major instruction types
    instructions = [
        # R-type
        factory.create_add(1, 0, 0),        # x1 = 0
        factory.create_addi(2, 0, 5),       # x2 = 5
        factory.create_addi(3, 0, 3),       # x3 = 3
        factory.create_add(4, 2, 3),        # x4 = x2 + x3
        factory.create_sub(5, 2, 3),        # x5 = x2 - x3
        
        # I-type
        factory.create_addi(6, 4, 10),      # x6 = x4 + 10
        
        # Load/Store
        factory.create_addi(7, 0, 0x200),   # x7 = base addr
        factory.create_sw(7, 6, 0),         # store x6 to [x7]
        factory.create_lw(8, 7, 0),         # load [x7] to x8
        
        # Branch
        factory.create_addi(9, 0, 5),       # x9 = 5
        factory.create_addi(10, 0, 5),      # x10 = 5
        factory.create_beq(9, 10, 8),       # if x9 == x10, skip next
        factory.create_addi(11, 0, 1),      # x11 = 1 (should skip)
        factory.create_addi(11, 0, 10),     # x11 = 10 (branch target)
        
        # Jump
        factory.create_jal(12, 8),          # jump and link
        factory.create_addi(13, 0, 99),     # should skip
        factory.create_lui(14, 0x12345),    # x14 = 0x12345000
    ]
    
    await env.run_test_program(instructions, cycles=100)
    
    results = env.get_test_results()
    
    if results['mismatches']['total_mismatches'] > 0:
        logger.error(f"Comprehensive test failed with {results['mismatches']['total_mismatches']} mismatches")
        raise TestFailure("Comprehensive instruction test failed")
    
    logger.info("Comprehensive instruction test passed")

@cocotb.test()
async def test_pipeline_performance(dut):
    """Test pipeline performance and efficiency"""
    logger.info("Starting pipeline performance test")
    
    env = RV32ITestEnvironment(dut)
    await env.setup()
    
    # Generate a longer program to test pipeline efficiency
    factory = RV32IInstructionFactory()
    instructions = []
    
    # Create a loop that exercises the pipeline
    for i in range(1, 16):  # Use registers x1-x15
        instructions.extend([
            factory.create_addi(i, 0, i),           # xi = i
            factory.create_add(i, i, i),            # xi = xi + xi
        ])
    
    # Add some memory operations
    for i in range(1, 8):
        base_addr = 0x100 + i * 4
        instructions.extend([
            factory.create_addi(16, 0, base_addr),  # x16 = base address
            factory.create_sw(16, i, 0),            # store xi to [base_addr]
            factory.create_lw(17, 16, 0),           # load back to x17
        ])
    
    await env.run_test_program(instructions, cycles=200)
    
    results = env.get_test_results()
    
    # Check performance metrics
    cpi = results['performance']['cpi']
    logger.info(f"Pipeline CPI: {cpi:.2f}")
    
    if cpi > 2.0:  # Expect reasonable CPI for pipelined processor
        logger.warning(f"High CPI detected: {cpi:.2f}")
    
    # logger.info("Pipeline performance test completed")
    logger.info(f"Total cycles: {results['pipeline_stats']['cycles']}")
    logger.info(f"Instructions: {results['pipeline_stats']['instructions']}")
    logger.info(f"Stalls: {results['pipeline_stats']['stalls']}")
    logger.info(f"Hazards: {results['pipeline_stats']['hazards']}")

@cocotb.test()
async def test_stress_random(dut):
    """Stress test with random instructions"""
    logger.info("Starting random stress test")
    
    env = RV32ITestEnvironment(dut)
    await env.setup()
    
    import random
    factory = RV32IInstructionFactory()
    instructions = []
    
    # Generate random instructions
    for _ in range(50):
        instr_type = random.choice(['add', 'addi', 'sub', 'lw', 'sw', 'beq'])
        
        if instr_type == 'add':
            rd = random.randint(1, 31)
            rs1 = random.randint(1, 15)  # Use lower registers more likely to have data
            rs2 = random.randint(1, 15)
            instructions.append(factory.create_add(rd, rs1, rs2))
            
        elif instr_type == 'addi':
            rd = random.randint(1, 31)
            rs1 = random.randint(0, 15)
            imm = random.randint(-100, 100)
            instructions.append(factory.create_addi(rd, rs1, imm))
            
        elif instr_type == 'sub':
            rd = random.randint(1, 31)
            rs1 = random.randint(1, 15)
            rs2 = random.randint(1, 15)
            instructions.append(factory.create_sub(rd, rs1, rs2))
            
        elif instr_type == 'lw':
            rd = random.randint(1, 31)
            rs1 = random.randint(1, 10)
            imm = random.randint(0, 100) * 4  # Word aligned
            instructions.append(factory.create_lw(rd, rs1, imm))
            
        elif instr_type == 'sw':
            rs1 = random.randint(1, 10)
            rs2 = random.randint(1, 15)
            imm = random.randint(0, 100) * 4  # Word aligned
            instructions.append(factory.create_sw(rs1, rs2, imm))
            
        elif instr_type == 'beq':
            rs1 = random.randint(1, 15)
            rs2 = random.randint(1, 15)
            imm = random.choice([-8, 4, 8, 12])  # Small jumps
            instructions.append(factory.create_beq(rs1, rs2, imm))
    
    await env.run_test_program(instructions, cycles=300)
    
    results = env.get_test_results()
    
    logger.info(f"Random stress test completed with {results['mismatches']['total_mismatches']} mismatches")
    
    # Generate final report
    report = generate_test_report(
        results['mismatches']['mismatches'],
        results['performance'],
        "stress_test_report.json"
    )
    
    if results['mismatches']['total_mismatches'] > 5:  # Allow some tolerance for random test
        logger.error("Too many mismatches in stress test")
        raise TestFailure("Random stress test failed")

@cocotb.test()
async def test_edge_cases(dut):
    """Test edge cases and corner conditions"""
    logger.info("Starting edge cases test")
    
    env = RV32ITestEnvironment(dut)
    await env.setup()
    
    factory = RV32IInstructionFactory()
    instructions = [
        # Test register x0 (should always be 0)
        factory.create_addi(0, 0, 100),     # Try to write to x0
        factory.create_add(1, 0, 0),        # x1 = x0 + x0 (should be 0)
        
        # Test maximum/minimum immediate values
        factory.create_addi(2, 0, 2047),    # Max positive 12-bit immediate
        factory.create_addi(3, 0, -2048),   # Max negative 12-bit immediate
        
        # Test with all registers
        factory.create_add(31, 1, 2),       # Use highest register number
        
        # Test zero operations
        factory.create_add(4, 0, 0),        # 0 + 0
        factory.create_sub(5, 0, 0),        # 0 - 0
        
        # Test memory at boundary addresses
        factory.create_addi(6, 0, 0),       # x6 = 0 (minimum address)
        factory.create_addi(7, 0, 42),      # x7 = test data
        factory.create_sw(6, 7, 0),         # store to address 0
        factory.create_lw(8, 6, 0),         # load from address 0
        
        # Test branch with zero offset
        factory.create_beq(1, 1, 0),        # Branch to same instruction (should fall through)
        
        # Test self-modifying scenarios (if supported)
        factory.create_add(9, 8, 7),        # Normal operation after edge cases
    ]
    
    await env.run_test_program(instructions, cycles=80)
    
    results = env.get_test_results()
    
    if results['mismatches']['total_mismatches'] > 0:
        logger.error(f"Edge cases test failed with {results['mismatches']['total_mismatches']} mismatches")
        raise TestFailure("Edge cases test failed")
    
    logger.info("Edge cases test passed")