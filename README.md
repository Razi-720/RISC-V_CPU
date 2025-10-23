# Pipelined RV32I Processor: RTL-to-GDSII Implementation

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/yourusername/pipelined-rv32i-processor)
[![Verilator](https://img.shields.io/badge/Verilator-5.028-orange)](https://verilator.org)
[![Yosys](https://img.shields.io/badge/Yosys-0.44-yellow)](https://yosyshq.net/yosys/)
[![OpenLane](https://img.shields.io/badge/OpenLane-2.1.7-green)](https://openlane.readthedocs.io)
[![IIC-OSIC-TOOLS](https://img.shields.io/badge/IIC--OSIC--TOOLS-2024.12-red)](https://github.com/iic-jku/iic-osic-tools)

## Overview

This project presents a complete implementation of a 5-stage pipelined RISC-V RV32I processor featuring Harvard architecture with comprehensive RTL design, verification, physical design, and performance analysis. The processor implements all base integer instructions with advanced features including branch prediction and hazard detection.

**Team Collaboration:**
- 2 members: RTL design and verification development
- 1 member: Physical design and synthesis optimization  
- Shared: Performance analysis and documentation

The implementation leverages the IIC-OSIC-TOOLS environment for a complete open-source digital design flow from RTL to GDSII. All tools and methodologies follow industry-standard practices ensuring reproducible results across different environments.

**Key Features:**
- 5-stage pipeline: Fetch, Decode, Execute, Memory, Writeback
- Harvard architecture with separate instruction and data memories
- Advanced branch predictor with hazard detection unit
- Complete RV32I ISA support
- Comprehensive verification suite with cocotb framework
- Full synthesis and physical design flow

## Repository Structure

```
├── config.json                    # Project configuration
├── docs/                          # Documentation
│   ├── architecture.md           # Processor architecture details
│   ├── physical_design.md        # Physical design methodology
│   ├── rtl_design.md             # RTL design specifications
│   └── testbench.md              # Verification strategy
├── src/                          # RTL source files
│   ├── Pip_RV32I.v              # Top-level processor module
│   ├── ALU.v                     # Arithmetic Logic Unit
│   ├── Branch_Predictor.v        # Branch prediction unit
│   ├── Hazard_Unit.v             # Pipeline hazard detection
│   ├── Register_File.v           # 32-entry register file
│   ├── IMemory.v / DMemory.v     # Instruction/Data memories
│   ├── Reg_*.v                   # Pipeline registers
│   └── constraints.sdc           # Synthesis constraints
├── tests/                        # Verification environment
│   ├── testbench.log             # Simulation logs
│   ├── driver.py                 # Test stimulus driver
│   ├── scoreboard.py             # Results checking
│   ├── monitor.py                # Signal monitoring
│   ├── stress_test_report.json   # Performance metrics
│   └── results.xml               # Test results summary
├── Synthesized/                  # Post-synthesis netlists
│   ├── SCRV32I_synth.v          # Synthesized netlist
│   └── lec_log.txt              # Logic equivalence check
└── runs/                         # Tool execution outputs
    └── RUN_2025-05-03_07-06-43/  # OpenLane run results
```

## Getting Started

### Prerequisites

- **Docker**: Container runtime environment
- **IIC-OSIC-TOOLS**: Complete open-source IC design toolchain
- **X11 forwarding** (for GUI tools): Xming/XQuartz for Windows/macOS

### Installation

1. **Install IIC-OSIC-TOOLS**:
   ```bash
   # Follow installation guide at:
   # https://github.com/iic-jku/iic-osic-tools#installation
   ```

2. **Clone Repository**:
   ```bash
   git clone https://github.com/yourusername/pipelined-rv32i-processor.git
   cd pipelined-rv32i-processor
   ```

3. **Launch Container**:
   ```bash
   # For local X11 display
   ./start_x.sh
   
   # Or standard container launch
   docker run -it --rm -v $(pwd):/workspace iic-osic-tools:latest
   ```

### Quick Start

**Run Verification Suite**:
```bash
cd tests/
make clean && make
```

**Synthesize Design**:
```bash
cd src/
yosys -s synthesis_script.ys
```

**View Results**:
```bash
# Check test results
cat tests/results.xml
cat tests/stress_test_report.json

# View synthesis reports
ls Synthesized/
```

## Toolflow

### RTL Design

The processor implementation consists of modular Verilog components:

- **ALU.v**: 32-bit arithmetic and logic operations with overflow detection
- **Branch_Predictor.v**: Two-level adaptive branch predictor for performance optimization
- **Hazard_Unit.v**: Data/control hazard detection with forwarding and stalling logic
- **Register_File.v**: Dual-ported 32x32-bit register file with bypass capabilities
- **Pipeline Registers**: Reg_F_D.v, Reg_D_E.v, Reg_E_M.v, Reg_M_W.v for stage isolation
- **Memory Units**: Harvard architecture with separate instruction and data paths

Detailed RTL specifications available in [docs/rtl_design.md](docs/rtl_design.md).

### Verification

Comprehensive verification environment built with cocotb Python framework:

- **driver.py**: Generates comprehensive test vectors including edge cases
- **scoreboard.py**: Implements golden model comparison and coverage tracking
- **monitor.py**: Signal observation and protocol checking
- **isa_reference.py**: RISC-V ISA compliance verification
- **Stress Testing**: Random instruction sequences with performance profiling

Architecture and methodology detailed in [docs/testbench.md](docs/testbench.md).

### Synthesis and Physical Design

Complete RTL-to-GDSII flow using open-source tools:

- **Synthesis**: Yosys with sky130A PDK targeting performance optimization
- **Constraints**: Timing constraints in constraints.sdc for 100MHz operation
- **Physical Design**: OpenLane automated flow with custom configuration
- **Verification**: Logic Equivalence Check (LEC) ensuring functional correctness

Physical design methodology available in [docs/physical_design.md](docs/physical_design.md).

## Performance Metrics

The processor tracks comprehensive performance and implementation metrics:

**Functional Metrics**:
- Instruction throughput and CPI (Cycles Per Instruction)
- Branch prediction accuracy and pipeline efficiency
- Memory access patterns and cache performance

**Implementation Metrics**:
- Gate count and area utilization
- Critical path timing and frequency analysis
- Power consumption estimates

Results stored in:
- `tests/stress_test_report.json`: Performance benchmarking data
- `tests/results.xml`: Verification coverage and pass/fail status
- `runs/*/reports/`: Synthesis and PnR detailed reports

## Contributing

We welcome contributions to improve the processor design and verification coverage:

1. **Issues**: Report bugs or request features via GitHub Issues
2. **Pull Requests**: Submit improvements with comprehensive testing
3. **Documentation**: Help improve design documentation and tutorials

Please follow the IIC-OSIC-TOOLS support routine for environment-related questions:
- Check existing issues and documentation first
- Provide minimal reproducible examples
- Include tool versions and configuration details

## License

This project is private.

## Acknowledgments

- **IIC-OSIC-TOOLS Team** at Johannes Kepler University for providing the comprehensive open-source IC design environment
- **SkyWater Technology** for the open-source SKY130 PDK
- **GlobalFoundries** for additional PDK support and resources
- **The RISC-V Foundation** for the open ISA specification
- **Cocotb Development Team** for the Python verification framework

## References

- IIC-OSIC-TOOLS: [DOI: 10.1109/OSIC.2023.10155886](https://doi.org/10.1109/OSIC.2023.10155886)
- RISC-V ISA Specification: [riscv.org](https://riscv.org/specifications/)
- SkyWater SKY130 PDK: [skywater-pdk.readthedocs.io](https://skywater-pdk.readthedocs.io/)

---

For detailed technical documentation, please refer to the files in the `docs/` directory.
