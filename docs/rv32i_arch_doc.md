# 5-Stage Pipelined RISC-V RV32I Processor Architecture Documentation

## 1. Overview

This document describes a 5-stage pipelined implementation of the RISC-V RV32I instruction set architecture. The processor implements data forwarding, hazard detection, and branch prediction to maximize throughput while maintaining correct execution semantics.

### 1.1 Architecture Diagram

The complete processor architecture is illustrated in the diagram below, showing all five pipeline stages, functional units, pipeline registers, and data/control paths:

![RV32I Pipeline Architecture](Pip_RV32I.png)

**Diagram Components:**
- **Pipeline Stages**: Fetch (F), Decode (D), Execute (E), Memory (M), Writeback (W)
- **Pipeline Registers**: F/D, D/E, E/M, M/W (shown as vertical dividers)
- **Functional Units**: PC, Instruction Memory, Decoder, Register File, ALU, Branch Predictor, Data Memory, etc.
- **Data Paths**: 
  - Blue lines: Main datapath flow
  - Green lines: Writeback path to Register File
  - Red dashed lines: Branch feedback path
  - Pink dashed lines: Forwarding paths from Memory and Writeback stages
- **Hazard Unit**: Controls stalling, flushing, and forwarding (shown at bottom with connections to all stages)

### 1.2 Key Features

- **5-Stage Pipeline**: Fetch, Decode, Execute, Memory, Writeback
- **Data Forwarding**: Eliminates most data hazards without stalling
- **Hazard Detection**: Automatic stall and flush control
- **Branch Prediction**: Early branch resolution in Execute stage
- **Full RV32I Support**: All 40 base integer instructions
- **Memory Interface**: Byte-addressable with byte-enable mask

### 1.3 Reading the Architecture Diagram

The architecture diagram shows the complete datapath and control flow:

**Stage Organization (Left to Right):**
1. **Fetch (F)**: PC unit, Instruction Memory, PC+4 adder
2. **Decode (D)**: Decoder, Register File, Extend Unit, instruction field extraction
3. **Execute (E)**: Forwarding muxes, ALU, Immediate Adder, Branch Predictor
4. **Memory (M)**: Store Unit, Data Memory, Load Unit
5. **Writeback (W)**: WB Unit (result multiplexer)

**Pipeline Registers (Vertical Dividers):**
- Orange/yellow vertical bars between stages store intermediate results
- Control signals: Stall (hold values), Flush (insert bubble/NOP)

**Key Paths:**
- **Solid colored lines**: Main datapath carrying instruction data
- **Green thick line (bottom)**: Writeback path feeding Register File
- **Red dashed line (bottom left)**: Branch target feedback to PC
- **Pink dashed lines (top right)**: Forwarding paths bypassing pipeline registers
- **Red dotted lines**: Hazard Unit monitoring and control connections

**Multiplexers (Triangular symbols):**
- Control data path selection based on hazards and instruction types
- Forward muxes select between register file, forwarded Memory data, or forwarded Writeback data
- ALUSrc mux selects between register value or immediate for ALU operand B

**Hazard Unit (Bottom):**
- Monitors all stages for register dependencies
- Generates control signals: Stall_F, Stall_D, Flush_D, Flush_E, ForwardA_E, ForwardB_E
- Dashed lines show bidirectional communication with pipeline stages

---

## 2. Pipeline Stages

### 2.1 Fetch Stage (F)

**Purpose**: Retrieves instructions from instruction memory and updates the program counter.

**Components**:
- **PC Unit**: Maintains the program counter
  - Inputs: Clock, Reset, Stall signal, Branch taken, Target PC
  - Outputs: Current PC, PC+4
  - Operation: Updates PC every cycle unless stalled or branching

**Operations**:
1. Output current PC to instruction memory
2. Calculate PC+4 for sequential execution
3. Select next PC (PC+4 or branch target)
4. Update PC on clock edge if not stalled

**Pipeline Register**: F/D (Fetch-to-Decode)
- Stores: PC, PC+4, Instruction
- Control: Stall_D (holds values), Flush_D (inserts bubble)

---

### 2.2 Decode Stage (D)

**Purpose**: Decodes instructions, generates control signals, reads register file, and extends immediates.

**Components**:

1. **Instruction Decoder**
   - Inputs: Opcode[6:0], Func3[2:0], Func7[30]
   - Outputs: All control signals
   - Generates: Reg_WrEn, ALU_Control, DM_WrEn, Branch_Cond, Result_Src, Imm_Type, etc.

2. **Register File**
   - 32 registers (x0-x31), x0 hardwired to zero
   - 2 read ports, 1 write port
   - Reads occur in Decode, writes occur in Writeback

3. **Extend Unit**
   - Sign-extends or zero-extends immediates
   - Supports I-type, S-type, B-type, U-type, J-type formats

**Instruction Fields Extracted**:
```
Opcode:     Instruction[6:0]
Func3:      Instruction[14:12]
Func7:      Instruction[30]
Src_Addr1:  Instruction[19:15]  (rs1)
Src_Addr2:  Instruction[24:20]  (rs2)
Des_Addr:   Instruction[11:7]   (rd)
Immediate:  Instruction[31:7]
```

**Control Signals Generated**:
- `Reg_WrEn`: Register write enable
- `ALU_Control[3:0]`: ALU operation selector
- `ALU_Src`: Select ALU operand B (register or immediate)
- `DM_WrEn`: Data memory write enable
- `Branch_Cond[7:0]`: Branch condition (BEQ, BNE, BLT, BGE, BLTU, BGEU, JAL, JALR)
- `Result_Src[2:0]`: Writeback data source selector
- `Imm_Type[2:0]`: Immediate format type
- `Iadder_Src`: Immediate adder source (PC or register)
- `Load_Size[1:0]`: Load data size (byte, halfword, word)
- `Load_Unsigned`: Sign-extension control for loads

**Pipeline Register**: D/E (Decode-to-Execute)
- Stores: PC, PC+4, Register data (RD1, RD2), Immediate, Control signals, Addresses
- Control: Flush_E (inserts bubble on control hazard)

---

### 2.3 Execute Stage (E)

**Purpose**: Performs ALU operations, calculates branch targets, and makes branch decisions.

**Components**:

1. **Forwarding Multiplexers**
   - **ForwardA_E**: Selects source for ALU operand A
     - `00`: Register file data (RD1_E)
     - `01`: ALU result from Memory stage (ALU_Result_M)
     - `10`: Writeback data (Result_W)
   
   - **ForwardB_E**: Selects source for ALU operand B (before immediate mux)
     - `00`: Register file data (RD2_E)
     - `01`: ALU result from Memory stage (ALU_Result_M)
     - `10`: Writeback data (Result_W)

2. **ALU (Arithmetic Logic Unit)**
   - Operations: ADD, SUB, AND, OR, XOR, SLL, SRL, SRA, SLT, SLTU
   - 32-bit operands and result
   - Control signals from ALU_Control[3:0]

3. **Immediate Adder**
   - Calculates branch targets and AUIPC results
   - Sources: PC+Immediate or Register+Immediate
   - Used for: Branches, JAL, JALR, AUIPC

4. **Branch Predictor**
   - Compares operands for branch conditions
   - Generates Branch_Taken signal
   - Conditions: BEQ, BNE, BLT, BGE, BLTU, BGEU
   - Unconditional: JAL, JALR

**Data Forwarding Logic**:
```
ForwardA_Data = (ForwardA_E == 2'b01) ? ALU_Result_M :
                (ForwardA_E == 2'b10) ? Result_W :
                Read_Data1_E;

ForwardB_Data = (ForwardB_E == 2'b01) ? ALU_Result_M :
                (ForwardB_E == 2'b10) ? Result_W :
                Read_Data2_E;

SrcA = ForwardA_Data;
SrcB = ALU_Src_E ? Imm_Ext_E : ForwardB_Data;
```

**Pipeline Register**: E/M (Execute-to-Memory)
- Stores: PC+4, ALU result, Read_Data2, Immediate, Added data, Control signals, Addresses
- No flush control (control hazards resolved before this stage)

---

### 2.4 Memory Stage (M)

**Purpose**: Interfaces with data memory for load and store instructions.

**Components**:

1. **Store Unit**
   - Prepares data for memory writes
   - Generates byte-enable mask based on store size (SB, SH, SW)
   - Aligns write data to correct byte lanes
   - Outputs: DM_WrData, DM_Addr, DM_Mask, DM_WrEn

2. **Data Memory Interface**
   - Address: From ALU result or immediate adder
   - Write Data: From Read_Data2 (rs2 value)
   - Read Data: Loaded from memory
   - Byte-enable mask: Supports byte, halfword, word accesses

3. **Load Unit**
   - Extracts and aligns loaded data
   - Performs sign/zero extension based on Load_Unsigned
   - Handles LB, LBU, LH, LHU, LW instructions
   - Uses lower 2 bits of address for byte/halfword alignment

**Memory Operations**:
- **Store Instructions (SB, SH, SW)**:
  - Func3 determines size (00=byte, 01=half, 10=word)
  - Data from Read_Data2_M
  - Mask generation ensures only intended bytes are written

- **Load Instructions (LB, LBU, LH, LHU, LW)**:
  - Data extracted from memory
  - Aligned based on address[1:0]
  - Sign-extended or zero-extended

**Pipeline Register**: M/W (Memory-to-Writeback)
- Stores: PC+4, ALU result, Loaded data, Immediate, Added data, Control signals, Address

---

### 2.5 Writeback Stage (W)

**Purpose**: Selects final result and writes it back to the register file.

**Components**:

1. **Writeback Unit (Multiplexer)**
   - Selects from multiple sources based on Result_Src[2:0]
   - Sources:
     - ALU result (arithmetic/logic operations)
     - Loaded data (load instructions)
     - PC+4 (JAL, JALR - return address)
     - Immediate (LUI - load upper immediate)
     - Added result (AUIPC - add upper immediate to PC)

**Result Selection**:
```
Result_Src encoding:
000: ALU_Result_W      (R-type, I-type arithmetic)
001: Loaded_Data_W     (Load instructions)
010: PC_Plus4_W        (JAL, JALR)
011: Imm_Ext_W         (LUI)
100: Imm_Added_W       (AUIPC)
```

**Writeback to Register File**:
- Occurs on clock edge
- Destination address: Des_Addr_W
- Write enable: Reg_WrEn_W
- Write data: Result_W
- x0 remains hardwired to zero

---

## 3. Hazard Detection and Control

### 3.1 Hazard Unit

**Purpose**: Detects and resolves pipeline hazards through stalling, flushing, and forwarding.

**Inputs**:
- Source addresses from Decode and Execute stages
- Destination addresses from Execute, Memory, and Writeback stages
- Register write enables from all stages
- Result source from Execute stage (for load-use detection)
- Branch taken signal

**Outputs**:
- `Stall_F`: Stall Fetch stage
- `Stall_D`: Stall Decode stage
- `Flush_D`: Flush Decode stage pipeline register
- `Flush_E`: Flush Execute stage pipeline register
- `ForwardA_E[1:0]`: Forward control for ALU operand A
- `ForwardB_E[1:0]`: Forward control for ALU operand B

---

### 3.2 Data Hazards

**Types**:

1. **RAW (Read-After-Write) Hazards**
   - Instruction needs data produced by previous instruction
   - **Solution**: Data forwarding

2. **Load-Use Hazards**
   - Instruction immediately following load needs loaded data
   - **Solution**: 1-cycle stall (data not available until Memory stage)

**Forwarding Conditions**:

**Forward from Memory Stage (ForwardA_E = 01, ForwardB_E = 01)**:
```
Condition:
  - Reg_WrEn_M = 1 (Memory stage will write)
  - Des_Addr_M ≠ 0 (not writing to x0)
  - Des_Addr_M = Src_Addr1_E or Src_Addr2_E (register match)
```

**Forward from Writeback Stage (ForwardA_E = 10, ForwardB_E = 10)**:
```
Condition:
  - Reg_WrEn_W = 1 (Writeback stage will write)
  - Des_Addr_W ≠ 0 (not writing to x0)
  - Des_Addr_W = Src_Addr1_E or Src_Addr2_E (register match)
  - Not already forwarding from Memory stage (Memory has priority)
```

**Load-Use Stall**:
```
Condition:
  - Result_Src_E[0] = 1 (Execute stage is a load instruction)
  - (Des_Addr_E = Src_Addr1_D) OR (Des_Addr_E = Src_Addr2_D)
  
Action:
  - Stall_F = 1, Stall_D = 1 (hold Fetch and Decode)
  - Flush_E = 1 (insert bubble in Execute)
```

---

### 3.3 Control Hazards

**Branch Resolution**: Occurs in Execute stage

**When Branch Taken**:
1. Two instructions after branch have entered pipeline (in Fetch and Decode)
2. These instructions are incorrect (wrong path)
3. **Action**: Flush Decode and Fetch stages
   - `Flush_D = 1`: Clear F/D pipeline register
   - PC updated with branch target
   - Next instruction fetched from correct path

**Branch Penalty**: 2 cycles (flushing 2 instructions)

**Branch Instructions**:
- Conditional: BEQ, BNE, BLT, BGE, BLTU, BGEU
- Unconditional: JAL, JALR

---

## 4. Instruction Set Support

### 4.1 R-Type Instructions

**Format**: `opcode rd, rs1, rs2`

**Instructions**: ADD, SUB, AND, OR, XOR, SLL, SRL, SRA, SLT, SLTU

**Datapath**:
1. Decode: Read rs1 and rs2 from register file
2. Execute: Perform ALU operation
3. Memory: No memory access
4. Writeback: Write ALU result to rd

**Control Signals**:
- `Reg_WrEn = 1`
- `ALU_Src = 0` (use register for operand B)
- `Result_Src = 000` (select ALU result)

---

### 4.2 I-Type Instructions

**Arithmetic**: ADDI, ANDI, ORI, XORI, SLLI, SRLI, SRAI, SLTI, SLTIU

**Format**: `opcode rd, rs1, imm`

**Datapath**:
1. Decode: Read rs1, extend immediate
2. Execute: ALU operation with register and immediate
3. Memory: No memory access
4. Writeback: Write ALU result to rd

**Control Signals**:
- `Reg_WrEn = 1`
- `ALU_Src = 1` (use immediate for operand B)
- `Result_Src = 000` (select ALU result)

---

### 4.3 Load Instructions

**Instructions**: LB, LH, LW, LBU, LHU

**Format**: `opcode rd, imm(rs1)`

**Datapath**:
1. Decode: Read rs1, extend immediate
2. Execute: Calculate address (rs1 + immediate)
3. Memory: Read from data memory, process with Load Unit
4. Writeback: Write loaded data to rd

**Control Signals**:
- `Reg_WrEn = 1`
- `Result_Src = 001` (select loaded data)
- `DM_WrEn = 0`
- `Load_Size`: 00=byte, 01=half, 10=word
- `Load_Unsigned`: 1=zero-extend, 0=sign-extend

**Load-Use Hazard**: Requires 1-cycle stall if next instruction uses rd

---

### 4.4 Store Instructions

**Instructions**: SB, SH, SW

**Format**: `opcode rs2, imm(rs1)`

**Datapath**:
1. Decode: Read rs1 and rs2, extend immediate
2. Execute: Calculate address (rs1 + immediate)
3. Memory: Write rs2 data to memory with Store Unit
4. Writeback: No writeback

**Control Signals**:
- `Reg_WrEn = 0` (no register write)
- `DM_WrEn = 1`
- `Func3`: 00=byte, 01=half, 10=word

---

### 4.5 Branch Instructions

**Instructions**: BEQ, BNE, BLT, BGE, BLTU, BGEU

**Format**: `opcode rs1, rs2, imm`

**Datapath**:
1. Decode: Read rs1 and rs2, extend immediate
2. Execute: Compare operands, calculate target (PC + immediate)
3. Branch decision made, flush if taken
4. Memory/Writeback: No operation

**Control Signals**:
- `Reg_WrEn = 0`
- `Iadder_Src = 0` (use PC for target calculation)
- `Branch_Cond`: Encoded condition type

---

### 4.6 Jump Instructions

**JAL (Jump and Link)**:
- `opcode rd, imm`
- Unconditional jump to PC + immediate
- Save PC+4 to rd

**JALR (Jump and Link Register)**:
- `opcode rd, imm(rs1)`
- Jump to (rs1 + immediate) & ~1
- Save PC+4 to rd

**Datapath**:
1. Decode: Read rs1 (JALR only), extend immediate
2. Execute: Calculate target, always branch
3. Memory/Writeback: Write PC+4 to rd

**Control Signals**:
- `Reg_WrEn = 1`
- `Result_Src = 010` (select PC+4)
- Branch always taken

---

### 4.7 Upper Immediate Instructions

**LUI (Load Upper Immediate)**:
- `opcode rd, imm`
- Load immediate into upper 20 bits of rd
- Lower 12 bits = 0

**AUIPC (Add Upper Immediate to PC)**:
- `opcode rd, imm`
- rd = PC + (imm << 12)

**Datapath**:
- LUI: Immediate extended, written directly to rd
- AUIPC: PC + immediate calculated in Execute, written to rd

**Control Signals**:
- `Reg_WrEn = 1`
- `Result_Src`: 011 (LUI), 100 (AUIPC)

---

## 5. Pipeline Registers

### 5.1 F/D Register (Fetch-to-Decode)

**Signals Stored**:
- `PC[31:0]`: Program counter
- `PC_Plus4[31:0]`: PC + 4
- `Instruction[31:0]`: Fetched instruction

**Control**:
- `Stall_D = 1`: Hold current values (load-use hazard)
- `Flush_D = 1`: Clear register (branch taken)
- Both can be active simultaneously (flush takes priority)

---

### 5.2 D/E Register (Decode-to-Execute)

**Signals Stored**:
- Program counter and PC+4
- Register read data (handled in register file for forwarding)
- Extended immediate
- Source and destination addresses
- All control signals

**Control**:
- `Flush_E = 1`: Clear all control signals (insert bubble)
- Used for load-use hazards and branch mispredictions

---

### 5.3 E/M Register (Execute-to-Memory)

**Signals Stored**:
- PC+4
- ALU result
- Read_Data2 (for stores)
- Immediate and added values
- Control signals
- Destination address

**No flush control** (hazards resolved before this point)

---

### 5.4 M/W Register (Memory-to-Writeback)

**Signals Stored**:
- PC+4
- ALU result
- Loaded data
- Immediate and added values
- Control signals
- Destination address

**No stall or flush control** (final stage before writeback)

---

## 6. Memory Interface

### 6.1 Instruction Memory Interface

**Signals**:
- `Instr_Addr_Out[31:0]`: Address to fetch (PC)
- `Instruction_In[31:0]`: Instruction fetched

**Timing**: Combinational read (address in, instruction out)

---

### 6.2 Data Memory Interface

**Signals**:
- `DM_Addr_Out[31:0]`: Memory address
- `DM_Data_Out[31:0]`: Data to write
- `DM_Data_In[31:0]`: Data read
- `DM_Mask_Out[3:0]`: Byte-enable mask
  - `4'b0001`: Byte 0
  - `4'b0011`: Bytes 0-1 (halfword)
  - `4'b1111`: All bytes (word)
- `DM_WrEn_Out`: Write enable

**Access Sizes**:
- Byte (8-bit): mask = 1 bit active
- Halfword (16-bit): mask = 2 bits active
- Word (32-bit): mask = 4 bits active

**Alignment**: Address[1:0] determines byte lane for sub-word accesses

---

## 7. Performance Analysis

### 7.1 Ideal CPI (Cycles Per Instruction)

**Without hazards**: CPI = 1 (one instruction completes per cycle)

---

### 7.2 Hazard Penalties

1. **Data Hazard with Forwarding**: 0 cycles (resolved by forwarding)
2. **Load-Use Hazard**: 1 cycle stall
3. **Branch Taken**: 2 cycle penalty (flush 2 stages)
4. **Branch Not Taken**: 0 cycle penalty

---

### 7.3 Effective CPI

```
CPI_effective = 1 + (Load-Use% × 1) + (Branch% × Branch_Taken% × 2)
```

**Example**:
- 20% loads, 10% followed by dependent instruction
- 15% branches, 50% taken

```
CPI_effective = 1 + (0.20 × 0.10 × 1) + (0.15 × 0.50 × 2)
              = 1 + 0.02 + 0.15
              = 1.17
```

---

### 7.4 Throughput

**Peak**: 1 instruction per cycle (ignoring hazards)

**Realistic**: 0.85 - 0.90 instructions per cycle (with typical hazards)

---

## 8. Design Considerations

### 8.1 Critical Path

**Longest combinational path**: Execute stage
- Forwarding mux → ALU → Branch comparator
- Determines maximum clock frequency

**Optimization**: Pipeline forwarding logic or use faster ALU design

---

### 8.2 Register File Design

**Implementation**:
- Read: Combinational (data available same cycle)
- Write: Synchronous (occurs on clock edge)
- Forwarding from Writeback stage handles write-then-read hazard

---

### 8.3 Branch Prediction

**Current**: Always assume not taken (simple prediction)

**Improvements**:
- Static prediction (backward taken, forward not taken)
- Dynamic prediction (branch history table)
- Branch target buffer (BTB)

---

### 8.4 Memory System

**Current**: Single-cycle memory access (idealized)

**Realistic Extensions**:
- Cache hierarchy (I-cache, D-cache)
- Multi-cycle memory access
- Stall pipeline on cache miss

---

## 9. Verification and Testing

### 9.1 Test Strategies

1. **Individual Instructions**: Test each instruction in isolation
2. **Hazard Scenarios**: Specifically trigger each hazard type
3. **Branch Testing**: All branch conditions, taken/not taken
4. **Load-Store Testing**: All sizes, alignments
5. **Edge Cases**: x0 register, immediate values, memory boundaries

---

### 9.2 Key Test Cases

**Data Hazards**:
```assembly
ADD x1, x2, x3
ADD x4, x1, x5  # RAW on x1 (forward from E/M)
ADD x6, x4, x7  # RAW on x4 (forward from M/W)
```

**Load-Use Hazard**:
```assembly
LW  x1, 0(x2)
ADD x3, x1, x4  # Stall required
```

**Branch Hazard**:
```assembly
BEQ x1, x2, target
ADD x3, x4, x5  # Flushed if branch taken
ADD x6, x7, x8  # Flushed if branch taken
```

---

## 10. Conclusion

This 5-stage pipelined RISC-V RV32I processor implements a complete instruction set with hazard handling through forwarding, stalling, and flushing. The design achieves near-optimal performance for a simple pipeline while maintaining correct execution semantics.

**Key Strengths**:
- Complete RV32I support
- Efficient data forwarding minimizes stalls
- Clean separation of pipeline stages
- Modular design for easy verification

**Possible Enhancements**:
- Branch prediction
- Cache integration
- Out-of-order execution
- Superscalar design (multiple issue)
- Support for RV32M (multiply/divide) extension

---

## Appendix A: Signal Reference

### Control Signals

| Signal | Width | Description |
|--------|-------|-------------|
| Reg_WrEn | 1 | Register file write enable |
| ALU_Src | 1 | ALU operand B source (0=reg, 1=imm) |
| ALU_Control | 4 | ALU operation selector |
| DM_WrEn | 1 | Data memory write enable |
| Branch_Cond | 8 | Branch condition encoding |
| Result_Src | 3 | Writeback source selector |
| Imm_Type | 3 | Immediate format type |
| Iadder_Src | 1 | Immediate adder source (0=PC, 1=reg) |
| Load_Size | 2 | Load data size |
| Load_Unsigned | 1 | Load sign extension control |

### Hazard Control Signals

| Signal | Width | Description |
|--------|-------|-------------|
| Stall_F | 1 | Stall Fetch stage |
| Stall_D | 1 | Stall Decode stage |
| Flush_D | 1 | Flush Decode stage |
| Flush_E | 1 | Flush Execute stage |
| ForwardA_E | 2 | Forward control for ALU operand A |
| ForwardB_E | 2 | Forward control for ALU operand B |

### Datapath Signals

| Signal | Width | Description |
|--------|-------|-------------|
| PC | 32 | Program counter |
| Instruction | 32 | Current instruction |
| Read_Data1/2 | 32 | Register file outputs |
| ALU_Result | 32 | ALU computation result |
| Imm_Ext | 32 | Extended immediate value |
| Loaded_Data | 32 | Data loaded from memory |
| Result | 32 | Final writeback result |

---

*Document Version 1.0 - Generated for RV32I 5-Stage Pipelined Processor*