
# Entity: Pip_RV32I 
- **File**: Pip_RV32I.v

## Diagram
![Diagram](Pip_RV32I.svg "Diagram")
## Description

Top-level module for a 5-stage pipelined RISC-V RV32I processor

## Ports

| Port name      | Direction | Type   | Description                                  |
| -------------- | --------- | ------ | -------------------------------------------- |
| Clk_In         | input     |        | Clock input                                  |
| Rst_In         | input     |        | Reset input                                  |
| Instruction_In | input     | [31:0] | Instruction input from instruction memory    |
| Instr_Addr_Out | output    | [31:0] | Program Counter output to instruction memory |
| DM_Data_In     | input     | [31:0] | Data input from data memory                  |
| DM_Addr_Out    | output    | [31:0] | Address output to data memory                |
| DM_Data_Out    | output    | [31:0] | Data output to data memory                   |
| DM_Mask_Out    | output    | [3:0]  | Byte-enable mask for data memory             |
| DM_WrEn_Out    | output    |        | Write enable signal for data memory          |

## Signals

| Name            | Type        | Description                                        |
| --------------- | ----------- | -------------------------------------------------- |
| PC_F            | wire [31:0] | Current Program Counter                            |
| PC_Plus4_F      | wire [31:0] | PC + 4                                             |
| Instruction_F   | wire [31:0] | Fetched instruction                                |
| PC_D            | wire [31:0] | PC in Decode stage                                 |
| PC_Plus4_D      | wire [31:0] | PC + 4 in Decode stage                             |
| Instruction_D   | wire [31:0] | Instruction in Decode stage                        |
| Opcode_D        | wire [6:0]  | Opcode field                                       |
| Func3_D         | wire [2:0]  | Function 3 field                                   |
| Func7_D         | wire        | Function 7 field (only bit 30 used)                |
| Src_Addr1_D     | wire [4:0]  | Source register 1 address                          |
| Src_Addr2_D     | wire [4:0]  | Source register 2 address                          |
| Des_Addr_D      | wire [4:0]  | Destination register address                       |
| Immediate_D     | wire [24:0] | Immediate field                                    |
| Read_Data1_D    | wire [31:0] | Data from source register 1                        |
| Read_Data2_D    | wire [31:0] | Data from source register 2                        |
| Imm_Ext_D       | wire [31:0] | Extended immediate value                           |
| Reg_WrEn_D      | wire        | Register write enable                              |
| Result_Src_D    | wire [2:0]  | Source selector for write-back                     |
| Imm_Type_D      | wire [2:0]  | Immediate type                                     |
| Iadder_Src_D    | wire        | Immediate adder source selector                    |
| ALU_Src_D       | wire        | ALU source selector                                |
| ALU_Control_D   | wire [3:0]  | ALU control signals                                |
| DM_WrEn_D       | wire        | Data memory write enable                           |
| Branch_Cond_D   | wire [7:0]  | Branch condition codes                             |
| Load_Unsigned_D | wire        | Load unsigned flag                                 |
| Load_Size_D     | wire [1:0]  | Load size (byte, half-word, word)                  |
| PC_E            | wire [31:0] | PC in Execute stage                                |
| PC_Plus4_E      | wire [31:0] | PC + 4 in Execute stage                            |
| Func3_E         | wire [1:0]  | Function 3 field in Execute stage                  |
| Reg_WrEn_E      | wire        | Register write enable in Execute stage             |
| Result_Src_E    | wire [2:0]  | Source selector for write-back in Execute stage    |
| Iadder_Src_E    | wire        | Immediate adder source selector in Execute stage   |
| ALU_Src_E       | wire        | ALU source selector in Execute stage               |
| ALU_Control_E   | wire [3:0]  | ALU control signals in Execute stage               |
| DM_WrEn_E       | wire        | Data memory write enable in Execute stage          |
| Branch_Cond_E   | wire [7:0]  | Branch condition codes in Execute stage            |
| Load_Unsigned_E | wire        | Load unsigned flag in Execute stage                |
| Load_Size_E     | wire [1:0]  | Load size in Execute stage                         |
| Read_Data1_E    | wire [31:0] | Data from source register 1 in Execute stage       |
| Read_Data2_E    | wire [31:0] | Data from source register 2 in Execute stage       |
| Imm_Ext_E       | wire [31:0] | Extended immediate value in Execute stage          |
| ALU_Result_E    | wire [31:0] | Result from ALU                                    |
| Imm_Added_E     | wire [31:0] | Result from immediate adder                        |
| Des_Addr_E      | wire [4:0]  | Destination register address in Execute stage      |
| Branch_Taken_E  | wire        | Branch taken flag                                  |
| PC_Plus4_M      | wire [31:0] | PC + 4 in Memory stage                             |
| ALU_Result_M    | wire [31:0] | Result from ALU in Memory stage                    |
| Read_Data2_M    | wire [31:0] | Data from source register 2 in Memory stage        |
| Reg_WrEn_M      | wire        | Register write enable in Memory stage              |
| Func3_M         | wire [1:0]  | Function 3 field in Memory stage                   |
| Result_Src_M    | wire [2:0]  | Source selector for write-back in Memory stage     |
| Load_Size_M     | wire [1:0]  | Load size in Memory stage                          |
| Load_Unsigned_M | wire        | Load unsigned flag in Memory stage                 |
| Loaded_Data_M   | wire [31:0] | Data loaded from memory                            |
| DM_WrData_M     | wire [31:0] | Data to write to memory                            |
| DM_Addr_M       | wire [31:0] | Address for data memory                            |
| DM_Wr_Req_M     | wire        | Data memory write request                          |
| DM_Mask_M       | wire [3:0]  | Byte-enable mask for data memory                   |
| DM_WrEn_M       | wire        | Data memory write enable in Memory stage           |
| Imm_Ext_M       | wire [31:0] | Extended immediate value in Memory stage           |
| Imm_Added_M     | wire [31:0] | Result from immediate adder in Memory stage        |
| Des_Addr_M      | wire [4:0]  | Destination register address in Memory stage       |
| Data_M          | wire [31:0] | Data from data memory                              |
| PC_Plus4_W      | wire [31:0] | PC + 4 in Write Back stage                         |
| ALU_Result_W    | wire [31:0] | Result from ALU in Write Back stage                |
| Loaded_Data_W   | wire [31:0] | Data loaded from memory in Write Back stage        |
| Imm_Ext_W       | wire [31:0] | Extended immediate value in Write Back stage       |
| Imm_Added_W     | wire [31:0] | Result from immediate adder in Write Back stage    |
| Result_W        | wire [31:0] | Final result to write back to register             |
| Reg_WrEn_W      | wire        | Register write enable in Write Back stage          |
| Result_Src_W    | wire [2:0]  | Source selector for write-back in Write Back stage |
| Des_Addr_W      | wire [4:0]  | Destination register address in Write Back stage   |

## Instantiations

- pc_unit: PC_Unit
  -  Module Instantiations Program Counter Unit
- reg_f_d: Reg_F_D
  -  Fetch to Decode Pipeline Register- decoder: Decoder
  -  Assign fetched instruction Decode instruction fields
 Instruction Decoder
- reg_file: Register_File
  -  Register File- imm_extend: Extend_Unit
  -  Immediate Extension Unit- reg_d_e: Reg_D_E
  -  Decode to Execute Pipeline Register- alu: ALU
  -  ALU Unit- branch_unit: Branch_Unit
  -  Immediate Adder (Branch Target Address) Branch Decision Logic
- reg_e_m: Reg_E_M
  -  Execute to Memory Pipeline Register- wr_mask_gen: DM_WrMask_Generator
  -  Data Memory Address Assignment Address to memory
 Data to write
 Write enable signal
 Write Mask Generator (based on load size and alignment)
- load_unit: Load_Unit
  -  Memory Load Data Processing- reg_m_w: Reg_M_W
  -  Memory to Write Back Pipeline Register- wb_unit: WB_Unit
  -  Result Mux: Select data to be written back to register file