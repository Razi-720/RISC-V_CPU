# RV32I 5-Stage Pipeline Testbench

A production-grade, modular Cocotb testbench for comprehensive verification of 5-stage pipelined RV32I processors.

## Overview

This testbench provides complete functional and performance verification for the `Pip_RV32I` processor, including:

- **Modular Architecture**: Separate driver, monitor, scoreboard, and reference model components
- **Comprehensive Coverage**: All RV32I instruction types, hazard detection, and pipeline performance
- **Reference Model**: Cycle-accurate ISA reference implementation for golden model comparison
- **Performance Analysis**: CPI, hazard rates, and pipeline efficiency metrics
- **Extensible Design**: Easy to add new test cases and verification features

## Directory Structure

```
tests/
├── __init__.py                 # Package initialization
├── driver.py                   # Memory and instruction drivers
├── monitor.py                  # Pipeline state monitoring
├── scoreboard.py               # Functional correctness checking
├── isa_reference.py            # RV32I reference model
├── utils.py                    # Utilities and helper functions
├── test_pipeline_rv32i.py      # Main test suite
├── conftest.py                 # Pytest configuration (optional)
├── Makefile                    # Build and run configuration
└── README.md                   # This file
```

## Features

### Driver (`driver.py`)
- **Instruction Memory Model**: Configurable instruction memory with programmable latency
- **Data Memory Model**: Byte-masked data memory with proper alignment checking
- **Memory Interface**: Drives `Instruction_In`, `DM_Data_In` and monitors memory transactions
- **Reset and Clock Management**: Proper reset sequencing and clock domain handling

### Monitor (`monitor.py`) 
- **Pipeline State Capture**: Records PC, instructions, memory transactions per cycle
- **Hazard Detection**: Monitors stalls, flushes, and hazard conditions
- **Performance Counters**: Tracks CPI, instruction count, and pipeline efficiency
- **Register File Monitoring**: Observes register writes and state changes
- **Memory Transaction Logging**: Complete record of all load/store operations

### Scoreboard (`scoreboard.py`)
- **Functional Verification**: Compares DUT behavior against reference model
- **Mismatch Detection**: Identifies register write, memory access, and control flow errors
- **Error Reporting**: Detailed mismatch analysis with cycle-accurate context
- **Expected Transaction Tracking**: Validates memory and register updates

### Reference Model (`isa_reference.py`)
- **Complete RV32I Implementation**: All integer instructions with proper semantics
- **Instruction Decoder**: Automatic instruction parsing and type detection
- **Memory Model**: Integrated memory for load/store instruction simulation
- **Golden Reference**: Provides expected behavior for scoreboard comparison

### Utilities (`utils.py`)
- **Instruction Encoding**: Complete RV32I instruction encoder with all formats
- **Test Program Generation**: Pre-built test sequences for common scenarios
- **Performance Analysis**: CPI calculation, hazard statistics, and efficiency metrics
- **Logging and Reporting**: Comprehensive test reports in JSON format

## Quick Start

### 1. Prerequisites

```bash
# Install cocotb and dependencies
pip install cocotb pytest

# Ensure simulator is installed (Icarus Verilog, ModelSim, etc.)
sudo apt-get install iverilog  # For Icarus Verilog
```

### 2. Setup RTL Files

Place your Verilog RTL files in the `src/` directory:

```
src/
├── Pip_RV32I.v           # Top-level processor
├── PC_Unit.v             # Program counter unit
├── Decoder.v             # Instruction decoder
├── Register_File.v       # Register file
├── ALU.v                 # Arithmetic logic unit
├── Extend_Unit.v         # Sign extension unit
├── Imm_Adder.v          # Immediate adder
├── Branch_Predictor.v    # Branch predictor
├── Hazard_Unit.v         # Hazard detection unit
├── Store_Unit.v          # Store unit
├── Load_Unit.v           # Load unit
├── WB_Unit.v             # Write-back unit
├── Reg_F_D.v            # Fetch-Decode pipeline register
├── Reg_D_E.v            # Decode-Execute pipeline register
├── Reg_E_M.v            # Execute-Memory pipeline register
└── Reg_M_W.v            # Memory-Writeback pipeline register
```

### 3. Run Tests

```bash
# Run all tests
make test-all

# Run specific test categories
make test-basic        # Basic arithmetic operations
make test-memory       # Load/store instructions
make test-branch       # Branch and jump instructions
make test-hazards      # Data hazard detection
make test-performance  # Pipeline performance analysis
make test-stress       # Random instruction stress test
make test-edge         # Edge cases and corner conditions

# Run regression suite
make regression

# Debug with waveforms
make debug
```

### 4. Advanced Usage

```bash
# Use different simulator
make SIM=questa test-all
make SIM=ghdl test-all

# Set random seed for reproducible tests
make RANDOM_SEED=42 test-stress

# Enable detailed logging
make COCOTB_LOG_LEVEL=DEBUG test-basic

# Generate coverage report (if supported)
make coverage
```

## Test Cases

### Basic Functionality Tests

| Test | Description | Instructions Covered |
|------|-------------|---------------------|
| `test_basic_arithmetic` | Integer ALU operations | ADD, SUB, ADDI, immediate variants |
| `test_memory_operations` | Load/store functionality | LW, SW, LB, LH, SB, SH with addressing |
| `test_branch_instructions` | Control flow | BEQ, BNE, BLT, BGE, BLTU, BGEU |
| `test_all_instruction_types` | Complete RV32I coverage | All R/I/S/B/U/J type instructions |

### Advanced Verification Tests

| Test | Description | Verification Focus |
|------|-------------|-------------------|
| `test_data_hazards` | Pipeline hazard handling | RAW, WAR, WAW hazard detection and forwarding |
| `test_pipeline_performance` | Performance analysis | CPI calculation, stall rates, throughput |
| `test_stress_random` | Stress testing | Random instruction sequences, corner cases |
| `test_edge_cases` | Boundary conditions | Register x0, maximum immediates, alignment |

## Configuration

### DUT Interface Requirements

Your `Pip_RV32I` module should have these signals:

```verilog
module Pip_RV32I (
    input wire Clk_In,              // Clock
    input wire Rst_In,              // Reset (active high)
    
    // Instruction Memory Interface
    input wire [31:0] Instruction_In,   // Instruction input
    output wire [31:0] Instr_Addr_Out,  // Instruction address
    
    // Data Memory Interface  
    input wire [31:0] DM_Data_In,       // Data memory input
    output wire [31:0] DM_Addr_Out,     // Data memory address
    output wire [31:0] DM_Data_Out,     // Data memory output
    output wire [3:0] DM_Mask_Out,      // Data memory byte mask
    output wire DM_WrEn_Out             // Data memory write enable
);
```

### Optional Debug Signals

For enhanced monitoring, expose these optional signals:

```verilog
// Pipeline stage program counters
output wire [31:0] if_pc,     // IF stage PC
output wire [31:0] id_pc,     // ID stage PC  
output wire [31:0] ex_pc,     // EX stage PC
output wire [31:0] mem_pc,    // MEM stage PC
output wire [31:0] wb_pc,     // WB stage PC

// Pipeline control signals
output wire hazard_detected,  // Hazard detection signal
output wire stall,           // Pipeline stall signal
output wire flush,           // Pipeline flush signal

// Register file interface (for verification)
output wire [4:0] wb_reg_addr,   // Writeback register address
output wire [31:0] wb_reg_data,  // Writeback register data
output wire wb_reg_write         // Writeback register write enable
```

## Customization

### Adding New Test Cases

1. **Create test function** in `test_pipeline_rv32i.py`:

```python
@cocotb.test()
async def test_my_custom_case(dut):
    """My custom test case"""
    env = RV32ITestEnvironment(dut)
    await env.setup()
    
    # Generate custom instruction sequence
    instructions = [
        # Your instructions here
    ]
    
    await env.run_test_program(instructions, cycles=100)
    results = env.get_test_results()
    
    # Add custom checks
    assert results['mismatches']['total_mismatches'] == 0
```

2. **Add to Makefile**:

```makefile
test-custom:
	$(MAKE) MODULE=tests.test_pipeline_rv32i TESTCASE=test_my_custom_case
```

### Extending the Reference Model

Add new instruction support in `isa_reference.py`:

```python
def _execute_my_instruction(self, instr, result):
    """Execute custom instruction"""
    # Implementation here
    pass
```

### Custom Performance Metrics

Extend `PerformanceAnalyzer` in `utils.py`:

```python
def get_custom_metrics(self) -> Dict[str, float]:
    """Calculate custom performance metrics"""
    # Add your metrics here
    pass
```

## Debugging

### Common Issues

1. **Signal not found errors**: Check that your RTL exposes the required interface signals
2. **Timing violations**: Adjust clock period in test setup (default 10ns)
3. **Memory access errors**: Verify data memory address alignment and masking
4. **Instruction encoding errors**: Use the provided instruction factory functions

### Debug Techniques

1. **Enable waveform dumping**:
```bash
make debug  # Generates debug.vcd
```

2. **Increase logging verbosity**:
```bash
make COCOTB_LOG_LEVEL=DEBUG test-basic
```

3. **Add custom logging** in test code:
```python
logger.info(f"Cycle {cycle}: PC=0x{pc:08x}, Instr=0x{instr:08x}")
```

4. **Use pipeline snapshots** for cycle-by-cycle analysis:
```python
snapshots = monitor.get_recent_snapshots(10)
for snapshot in snapshots:
    print(f"Cycle {snapshot.cycle}: {snapshot}")
```

## Performance Metrics

The testbench automatically collects these metrics:

- **CPI (Cycles Per Instruction)**: Pipeline efficiency indicator
- **IPC (Instructions Per Cycle)**: Throughput measurement  
- **Hazard Rate**: Percentage of cycles with hazards detected
- **Stall Rate**: Percentage of cycles with pipeline stalls
- **Branch Miss Rate**: Branch prediction accuracy (if supported)
- **Memory Latency**: Average memory access cycles

## Integration with CI/CD

### GitHub Actions Example

```yaml
name: RV32I Testbench CI

on: [push, pull_request]

jobs:
  test:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v2
    - name: Setup Python
      uses: actions/setup-python@v2
      with:
        python-version: '3.8'
    - name: Install dependencies
      run: |
        pip install cocotb pytest
        sudo apt-get install iverilog
    - name: Run tests
      run: make regression
    - name: Upload results
      uses: actions/upload-artifact@v2
      with:
        name: test-results
        path: '*_report.json'
```

## Contributing

1. **Fork the repository** and create a feature branch
2. **Add tests** for new functionality
3. **Ensure all tests pass**: `make regression`
4. **Update documentation** as needed
5. **Submit pull request** with detailed description

## License

This testbench is provided under the MIT License. See LICENSE file for details.

## Support

For questions, issues, or contributions:

1. **Check the documentation** in this README
2. **Review example test cases** in `test_pipeline_rv32i.py`
3. **Enable debug logging** for detailed operation traces
4. **Generate waveforms** for signal-level debugging

The testbench is designed to be self-documenting with comprehensive logging and error reporting to facilitate debugging and verification.
