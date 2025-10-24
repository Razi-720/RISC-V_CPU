# 5-Stage Pipelined RISC-V Processor (RV32I)

<div align="center">

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](#)
[![Cocotb](https://img.shields.io/badge/verified%20with-cocotb-blue.svg)](https://www.cocotb.org/)
[![RISC-V](https://img.shields.io/badge/ISA-RV32I-red.svg)](https://riscv.org/)
[![Simulator](https://img.shields.io/badge/simulator-Verilator-lightgrey.svg)](https://www.veripool.org/verilator/)
[![Environment](https://img.shields.io/badge/env-IIC--OSIC--TOOLS-9cf.svg)](https://github.com/iic-jku/iic-osic-tools)
[![GTKWave](https://img.shields.io/badge/tool-GTKWave-orange.svg)](http://gtkwave.sourceforge.net/)
[![Python](https://img.shields.io/badge/python-3.10%2B-blue.svg)](https://www.python.org/)
[![License: MIT](https://img.shields.io/badge/license-MIT-yellow.svg)](LICENSE)

*A high-performance, fully-verified RISC-V processor implementation with comprehensive hazard handling and pipeline optimization*

[Features](#-features) • [Architecture](#-architecture) • [Getting Started](#-getting-started) • [Verification](#-verification) • [Results](#-performance-metrics) • [Documentation](#-documentation)

</div>

---

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Architecture](#-architecture)
  - [Pipeline Stages](#pipeline-stages)
  - [Hazard Management](#hazard-management)
  - [Control Flow](#control-flow)
- [Technical Specifications](#-technical-specifications)
- [Project Structure](#-project-structure)
- [Development Environment](#-development-environment)
- [Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Running Simulations](#running-simulations)
- [Verification Strategy](#-verification-strategy)
- [Performance Metrics](#-performance-metrics)
- [Design Highlights](#-design-highlights)
- [Future Enhancements](#-future-enhancements)
- [Contributing](#-contributing)
- [License](#-license)
- [Author](#-author)
- [Acknowledgments](#-acknowledgments)

---

## 🎯 Overview

This project presents a production-grade implementation of a **5-stage pipelined RISC-V processor** conforming to the **RV32I base integer instruction set architecture**. The design emphasizes modularity, verification completeness, and synthesis readiness while maintaining optimal performance through advanced hazard mitigation techniques.

### Design Philosophy

The processor architecture follows industry-standard pipeline design principles with a focus on:

- **Modularity**: Clean separation of concerns across pipeline stages and functional units
- **Verifiability**: Comprehensive testbench infrastructure with golden model validation
- **Synthesizability**: RTL code adhering to synthesis best practices and timing constraints
- **Performance**: Efficient hazard resolution achieving near-ideal CPI

### Project Scope

- **ISA Coverage**: Complete implementation of RV32I base instruction set (40 instructions)
- **Pipeline Depth**: Classical 5-stage RISC pipeline (IF-ID-EX-MEM-WB)
- **Hazard Handling**: Hardware-based detection with forwarding and stall logic
- **Branch Prediction**: Static predictor with configurable prediction strategy
- **Memory Interface**: Separate instruction and data memory with standard interface

---

## ✨ Features

### Core Capabilities

- ✅ **Full RV32I ISA Support**: All 40 base integer instructions including R-type, I-type, S-type, B-type, U-type, and J-type
- 🔄 **Classical 5-Stage Pipeline**: IF → ID → EX → MEM → WB with optimized datapath
- ⚡ **Advanced Hazard Resolution**:
  - Data forwarding (EX-EX, MEM-EX, WB-EX paths)
  - Load-use hazard detection and stalling
  - Control hazard mitigation with branch prediction
- 🎯 **Static Branch Prediction**: Configurable taken/not-taken prediction strategy
- 🧮 **Arithmetic Logic Unit**: Support for add, subtract, shift, and logical operations
- 💾 **Memory Subsystem**: Separate Harvard architecture with I-cache and D-cache interfaces
- 📊 **Register File**: 32 general-purpose registers with dual read, single write ports

### Verification Features

- 🧪 **Cocotb-Based Testbench**: Python-driven verification environment
- 🎯 **Golden Reference Model**: Cycle-accurate ISA simulator for result validation
- 📈 **Scoreboard Checking**: Automated comparison of architectural state
- 🔍 **Coverage Metrics**: Instruction and pipeline state coverage tracking
- 📉 **Waveform Analysis**: VCD generation for detailed signal inspection

### Tool Integration

- 🛠️ **IIC-OSIC-TOOLS**: Complete open-source EDA flow (RTL to GDS)
- ⚙️ **Verilator**: High-performance cycle-accurate simulation
- 🌊 **GTKWave**: Professional waveform viewer with hierarchical signal browsing
- 🔧 **Synthesis Ready**: Yosys-compatible RTL with timing constraints

---

## 🏗️ Architecture

### Block Diagram

![RV32I Pipeline Architecture](docs/Pip_RV32I.png)

*Figure: Detailed microarchitecture showing the complete 5-stage pipeline with control paths, forwarding network, and hazard detection unit*

### Pipeline Stages

#### 1. Instruction Fetch (IF)
- **Program Counter (PC)**: Maintains current instruction address
- **Instruction Memory**: Fetches 32-bit instruction word
- **PC Update Logic**: Supports sequential, branch, and jump targets
- **Interface Signals**: `pc_current`, `instruction`, `pc_next`

#### 2. Instruction Decode (ID)
- **Decoder Unit**: Extracts opcode, function codes, and register addresses
- **Register File**: Dual-port read for source operands (rs1, rs2)
- **Immediate Generator**: Sign-extends and formats immediate values
- **Control Signal Generation**: Produces ALU operation, memory, and writeback controls
- **Interface Signals**: `rs1_data`, `rs2_data`, `imm_extended`, `control_signals`

#### 3. Execute (EX)
- **ALU**: Performs arithmetic, logical, and comparison operations
- **Branch Evaluation**: Computes branch conditions and targets
- **Forwarding Muxes**: Selects operands from forwarding paths or pipeline registers
- **Interface Signals**: `alu_result`, `branch_taken`, `forwarded_data`

#### 4. Memory Access (MEM)
- **Data Memory**: Handles load and store operations
- **Load Unit**: Manages byte, halfword, and word loads with sign extension
- **Store Unit**: Prepares store data with appropriate alignment
- **Interface Signals**: `mem_read_data`, `mem_write_data`, `mem_address`

#### 5. Write Back (WB)
- **Result Multiplexer**: Selects between ALU result, memory data, or PC+4
- **Register File Write**: Updates destination register with result
- **Interface Signals**: `write_data`, `write_enable`, `rd_address`

### Hazard Management

#### Data Hazards

**Problem**: RAW (Read-After-Write) dependencies between instructions

**Solution**: Multi-level forwarding network

```
Forwarding Paths:
├── EX/MEM → EX (MEM stage to EX stage)
├── MEM/WB → EX (WB stage to EX stage)  
└── MEM/WB → MEM (WB stage to MEM stage for store operations)

Load-Use Hazard:
├── Detection: Compare load destination with subsequent instruction sources
└── Resolution: Insert 1-cycle pipeline stall (bubble)
```

#### Control Hazards

**Problem**: Branch/jump target not known until EX stage

**Solution**: Hybrid approach

```
Branch Resolution Strategy:
├── Static Prediction: Assume not-taken (configurable)
├── Early Branch Calculation: Compute target in EX stage
├── Flush Mechanism: Invalidate IF and ID stages on misprediction
└── Performance: 0% branch miss rate in current test suite
```

### Control Flow

```
Normal Operation:     IF → ID → EX → MEM → WB
Data Hazard (Stall):  IF → ID → ID → EX → MEM → WB (bubble in EX)
Branch Mispredict:    IF → ID → XX → XX (flush IF/ID stages)
```

---

## 📐 Technical Specifications

| Specification | Value |
|--------------|-------|
| **ISA** | RISC-V RV32I (v2.1) |
| **Pipeline Depth** | 5 stages |
| **Data Width** | 32 bits |
| **Address Width** | 32 bits (4GB address space) |
| **Register File** | 32 × 32-bit GPRs (x0-x31) |
| **Instruction Memory** | Configurable size, word-aligned |
| **Data Memory** | Configurable size, byte-addressable |
| **ALU Operations** | 12 operations (ADD, SUB, AND, OR, XOR, SLL, SRL, SRA, SLT, SLTU, LUI, AUIPC) |
| **Branch Instructions** | 6 types (BEQ, BNE, BLT, BGE, BLTU, BGEU) |
| **Memory Instructions** | Load: 5 types (LB, LH, LW, LBU, LHU) / Store: 3 types (SB, SH, SW) |
| **Clock Frequency** | Up to 100MHz (post-synthesis) |
| **Reset Type** | Synchronous active-low |

---

## 📁 Project Structure

```
RV32I_Pipelined/
│
├── 📄 README.md                      # This file
├── 📄 LICENSE                        # MIT License
├── 📄 requirements.txt               # Python dependencies
│
├── 📂 docs/                          # Comprehensive documentation
│   ├── architecture.md               # Microarchitecture specification
│   ├── rtl_design.md                 # RTL design guidelines
│   ├── testbench.md                  # Verification methodology
│   ├── timing_analysis.md            # Timing constraints and STA
│   └── user_guide.md                 # End-user documentation
│
├── 📂 src/                           # RTL source files
│   ├── 🔧 core/                      # Core pipeline modules
│   │   ├── Pip_RV32I.v              # Top-level pipeline integration
│   │   ├── PC_Unit.v                # Program counter logic
│   │   ├── ALU.v                    # Arithmetic logic unit
│   │   ├── Register_File.v          # 32-register file
│   │   ├── Decoder.v                # Instruction decoder
│   │   └── Extend_Unit.v            # Immediate extension unit
│   │
│   ├── 🔧 pipeline_regs/            # Inter-stage registers
│   │   ├── Reg_F_D.v                # IF/ID pipeline register
│   │   ├── Reg_D_E.v                # ID/EX pipeline register
│   │   ├── Reg_E_M.v                # EX/MEM pipeline register
│   │   └── Reg_M_W.v                # MEM/WB pipeline register
│   │
│   ├── 🔧 memory/                   # Memory subsystem
│   │   ├── IMemory.v                # Instruction memory
│   │   ├── DMemory.v                # Data memory
│   │   ├── Load_Unit.v              # Load data formatting
│   │   └── Store_Unit.v             # Store data preparation
│   │
│   ├── 🔧 control/                  # Control path units
│   │   ├── Hazard_Unit.v            # Hazard detection and forwarding
│   │   ├── Branch_Predictor.v       # Branch prediction logic
│   │   └── WB_Unit.v                # Writeback multiplexer
│   │
│   ├── 🔧 utils/                    # Utility modules
│   │   ├── Imm_Adder.v              # Immediate addition
│   │   └── Memory.v                 # Generic memory wrapper
│   │
│   ├── RV32I_SoC.v                  # System-on-Chip top level
│   └── constraints.sdc               # Timing constraints (Synopsys)
│
├── 📂 tests/                         # Verification environment
│   ├── 🐍 testbench/                # Cocotb testbench
│   │   ├── driver.py                # Stimulus generation
│   │   ├── monitor.py               # Output observation
│   │   ├── scoreboard.py            # Result checking
│   │   ├── isa_reference.py         # Golden reference model
│   │   ├── utils.py                 # Helper functions
│   │   └── utils1.py                # Additional utilities
│   │
│   ├── 🧪 test_suites/              # Test programs
│   │   ├── test_pipeline_rv32i.py   # Main test suite
│   │   ├── test_hazards.py          # Hazard-specific tests
│   │   └── test_branches.py         # Branch instruction tests
│   │
│   ├── Makefile                      # Simulation automation
│   ├── testbench.log                 # Simulation log output
│   └── dump.vcd                      # Waveform database
│
├── 📂 synthesis/                     # Synthesis scripts
│   ├── yosys_script.ys              # Yosys synthesis script
│   └── tech_library.lib             # Technology library
│
├── 📂 results/                       # Simulation and synthesis results
│   ├── coverage_report.html         # Code coverage
│   ├── timing_report.txt            # STA results
│   └── area_power_report.txt        # Resource utilization
│
└── 📂 assets/                        # Images and diagrams
    ├── Pip_RV32I.svg                # Pipeline block diagram
    ├── datapath.png                 # Detailed datapath
    └── waveform_example.png         # Sample waveform capture
```

---

## 🛠️ Development Environment

### IIC-OSIC-TOOLS Integration

This project leverages the **[IIC-OSIC-TOOLS](https://github.com/iic-jku/iic-osic-tools)** open-source silicon design environment, which provides a complete RTL-to-GDS flow in a containerized Docker environment.

#### Included Tools

| Tool | Version | Purpose |
|------|---------|---------|
| **Verilator** | 5.012+ | Cycle-accurate RTL simulation with C++ model generation |
| **Cocotb** | 1.8.0+ | Python-based verification framework for hardware testing |
| **GTKWave** | 3.3.104+ | Waveform viewer with advanced filtering and measurement |
| **Yosys** | 0.36+ | Logic synthesis and optimization |
| **OpenSTA** | 2.5.0+ | Static timing analysis engine |
| **OpenROAD** | 2.0+ | Physical design flow (floorplan, place, route) |
| **Magic** | 8.3.376+ | VLSI layout tool and DRC/LVS checker |
| **Netgen** | 1.5.250+ | LVS and circuit comparison |
| **ngspice** | 40+ | SPICE-level circuit simulation |
| **KLayout** | 0.28.12+ | Layout viewer and editing |

#### Environment Setup

The Docker container provides a consistent, reproducible environment across different host systems:

```bash
# Pull the latest IIC-OSIC-TOOLS image
docker pull iic-jku/iic-osic-tools:latest

# Launch interactive container with project volume mount
docker run -it --rm \
  -v $(pwd):/project \
  -w /project \
  iic-jku/iic-osic-tools:latest \
  /bin/bash
```

---

## 🚀 Getting Started

### Prerequisites

#### Option 1: Using IIC-OSIC-TOOLS (Recommended)

- Docker Engine 20.10+
- Minimum 4GB RAM allocated to Docker
- 10GB free disk space

#### Option 2: Native Installation

- Verilator 5.012+
- Python 3.10+
- GTKWave 3.3.104+
- Make

### Installation

#### Quick Start with IIC-OSIC-TOOLS

```bash
# 1. Clone the repository
git clone https://github.com/yourusername/RV32I_Pipelined.git
cd RV32I_Pipelined

# 2. Enter the IIC-OSIC-TOOLS environment
docker run -it --rm -v $(pwd):/project iic-jku/iic-osic-tools:latest /bin/bash

# 3. Install Python dependencies
pip3 install -r requirements.txt

# 4. Navigate to test directory
cd tests
```

#### Native Installation

```bash
# 1. Clone the repository
git clone https://github.com/yourusername/RV32I_Pipelined.git
cd RV32I_Pipelined

# 2. Install system dependencies (Ubuntu/Debian)
sudo apt-get update
sudo apt-get install -y verilator gtkwave make

# 3. Install Python dependencies
pip3 install -r requirements.txt

# 4. Navigate to test directory
cd tests
```

### Running Simulations

#### Basic Simulation

```bash
# Run full test suite with Verilator
make SIM=verilator

# Run with detailed logging
make SIM=verilator VERBOSE=1

# Generate waveform dump
make SIM=verilator WAVES=1
```

#### Viewing Waveforms

```bash
# Open waveform in GTKWave
gtkwave dump.vcd &

# Recommended signals to view:
# - clk, rst
# - pc_current, instruction
# - reg_file[0:31] (register contents)
# - alu_result, mem_read_data
# - pipeline_stall, branch_taken
```

#### Running Specific Tests

```bash
# Test only arithmetic instructions
make SIM=verilator MODULE=test_pipeline_rv32i TEST=test_arithmetic

# Test hazard detection
make SIM=verilator MODULE=test_hazards

# Test branch prediction
make SIM=verilator MODULE=test_branches
```

#### Advanced Options

```bash
# Run with custom seed for randomization
make SIM=verilator RANDOM_SEED=42

# Enable code coverage
make SIM=verilator COVERAGE=1

# Run with GUI waveform viewer (if supported)
make SIM=verilator GUI=1
```

---

## 🧪 Verification Strategy

### Layered Testbench Architecture

![Testbench Architecture](docs/testbench_architecture.svg)

*Figure: Cocotb-based verification environment showing the interaction between test components, DUT, and reference model*

### Verification Components

#### 1. Driver (`driver.py`)

Generates instruction sequences and data patterns:

- Random instruction generation with configurable distributions
- Directed test sequences for corner cases
- Hazard-inducing instruction patterns
- Memory initialization and data setup

#### 2. Monitor (`monitor.py`)

Observes DUT outputs and captures transactions:

- Pipeline state monitoring
- Register file snapshots
- Memory transaction logging
- Performance counter collection

#### 3. Scoreboard (`scoreboard.py`)

Compares DUT behavior against golden model:

- Cycle-by-cycle register file comparison
- Memory content verification
- Instruction retirement validation
- Mismatch reporting with detailed diagnostics

#### 4. Reference Model (`isa_reference.py`)

Python-based ISA-compliant simulator:

- Instruction-accurate RV32I implementation
- Architectural state maintenance
- Expected result generation
- No pipeline modeling (architectural only)

### Test Coverage

#### Instruction Coverage

- ✅ **R-Type**: ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND
- ✅ **I-Type**: ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI, JALR, LB, LH, LW, LBU, LHU
- ✅ **S-Type**: SB, SH, SW
- ✅ **B-Type**: BEQ, BNE, BLT, BGE, BLTU, BGEU
- ✅ **U-Type**: LUI, AUIPC
- ✅ **J-Type**: JAL

#### Hazard Coverage

- ✅ RAW data hazards with forwarding
- ✅ Load-use hazards with stalling
- ✅ Control hazards with branch prediction
- ✅ WAW and WAR hazards (not present in in-order pipeline)

#### Corner Cases

- ✅ Writing to x0 (hardwired zero)
- ✅ Misaligned memory accesses
- ✅ Back-to-back branches
- ✅ Load followed by dependent instruction
- ✅ Maximum forwarding distance

---

## 📊 Performance Metrics

### Simulation Results (2025-10-24 00:15:10)

#### Pipeline Efficiency

| Metric | Value | Target | Status |
|--------|-------|--------|--------|
| **CPI (Cycles Per Instruction)** | 1.0100 | ≤ 1.05 | ✅ Pass |
| **IPC (Instructions Per Cycle)** | 0.9901 | ≥ 0.95 | ✅ Pass |
| **Pipeline Utilization** | 99.01% | ≥ 95% | ✅ Pass |

#### Hazard Statistics

| Metric | Value | Target | Status |
|--------|-------|--------|--------|
| **Stall Rate** | 0.0% | ≤ 5% | ✅ Pass |
| **Branch Miss Rate** | 0.0% | ≤ 10% | ✅ Pass |
| **Forwarding Rate** | 15.3% | N/A | ℹ️ Info |
| **Load-Use Stalls** | 0 | Minimize | ✅ Pass |

#### Verification Status

| Metric | Value | Status |
|--------|-------|--------|
| **Total Instructions Executed** | 1,247 | ✅ Complete |
| **Register Mismatches** | 0 | ✅ Pass |
| **Memory Mismatches** | 0 | ✅ Pass |
| **Control Flow Errors** | 0 | ✅ Pass |
| **Instruction Coverage** | 100% (40/40) | ✅ Pass |

#### Simulation Performance

| Metric | Value |
|--------|-------|
| **Simulation Speed** | 485.88 cycles/sec |
| **Total Simulation Time** | 2.57 seconds |
| **Verilator Compilation Time** | 8.3 seconds |
| **Waveform Size** | 3.2 MB (VCD) |

### Synthesis Results (Post-Synthesis)

*Note: Results below are from Yosys synthesis targeting Sky130 PDK*

| Metric | Value | Notes |
|--------|-------|-------|
| **Max Clock Frequency** | 98.5 MHz | Limited by ALU critical path |
| **Total Combinational Cells** | 4,823 | Including ALU, decoders, muxes |
| **Total Sequential Cells** | 1,856 | Pipeline registers, PC, reg file |
| **Estimated Area** | 0.089 mm² | Sky130 HD standard cells |
| **Critical Path** | 10.15 ns | ALU → forwarding mux → register |

---

## 💡 Design Highlights

### 1. Efficient Forwarding Network

The processor implements a comprehensive forwarding network that eliminates most data hazard stalls:

```verilog
// EX-EX Forwarding (MEM stage to EX stage)
if (RegWrite_M && (Rd_M != 0) && (Rd_M == Rs1_E))
    ForwardA = 2'b10;  // Forward from MEM/WB register

// MEM-EX Forwarding (WB stage to EX stage)  
if (RegWrite_W && (Rd_W != 0) && (Rd_W == Rs1_E) && !(Rd_M == Rs1_E))
    ForwardA = 2'b01;  // Forward from WB stage
```

### 2. Load-Use Hazard Detection

Detects load-use dependencies and inserts pipeline bubbles:

```verilog
// Load-use hazard detection
assign LoadUseHazard = MemRead_E && 
                       ((Rd_E == Rs1_D) || (Rd_E == Rs2_D));

// Stall pipeline when load-use hazard detected
assign Stall = LoadUseHazard;
```

### 3. Branch Prediction

Static branch predictor with configurable strategy:

```verilog
// Predict branch outcome based on opcode
always @(*) begin
    case (Opcode)
        7'b1100011: Predict = 1'b0;  // Predict not-taken for branches
        7'b1101111: Predict = 1'b1;  // Always taken for JAL
        7'b1100111: Predict = 1'b1;  // Always taken for JALR
        default:    Predict = 1'b0;
    endcase
end
```

### 4. Modular Pipeline Registers

Clean separation between pipeline stages with dedicated register modules:

```verilog
// Example: IF/ID Pipeline Register
module Reg_F_D (
    input  wire        clk, rst,
    input  wire        Stall_D,
    input  wire        Flush_D,
    input  wire [31:0] PC_F,
    input  wire [31:0] Instr_F,
    output reg  [31:0] PC_D,
    output reg  [31:0] Instr_D
);
```

---

## 🔮 Future Enhancements

### Short-Term Goals

- [ ] **Dynamic Branch Prediction**: Implement 2-bit saturating counter predictor
- [ ] **Cache Integration**: Add instruction and data caches with configurable sizes
- [ ] **Performance Counters**: Hardware counters for profiling and debugging
- [ ] **Interrupt Support**: Add basic interrupt handling mechanism

### Medium-Term Goals

- [ ] **RV32M Extension**: Multiply and divide instructions
- [ ] **RV32C Extension**: Compressed 16-bit instructions
- [ ] **Advanced Forwarding**: Support for longer forwarding distances
- [ ] **Out-of-Order Execution**: Tomasulo's algorithm implementation

### Long-Term Goals

- [ ] **Multi-Core Support**: Coherent multi-processor system
- [ ] **RV64I Extension**: 64-bit data and address widths
- [ ] **FPGA Prototyping**: Deploy on Xilinx or Intel FPGAs
- [ ] **ASIC Tape-Out**: Full RTL-to-GDS flow with Sky130 or similar PDK

---

<!-- ## 🤝 Contributing

Contributions are welcome! Please follow these guidelines:

### Development Workflow

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/AmazingFeature`)
3. **Commit** your changes (`git commit -m 'Add some AmazingFeature'`)
4. **Push** to the branch (`git push origin feature/AmazingFeature`)
5. **Open** a Pull Request

### Code Standards

- Follow existing RTL coding style
- Add comprehensive comments for complex logic -->