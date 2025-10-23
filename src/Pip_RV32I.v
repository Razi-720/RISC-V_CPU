`include "ALU.v"
`include "Branch_Predictor.v"
`include "Decoder.v"
`include "Extend_Unit.v"
`include "Imm_Adder.v"
`include "Load_Unit.v"
`include "PC_Unit.v"
`include "Register_File.v"
`include "Store_Unit.v"
`include "WB_Unit.v"
`include "Reg_D_E.v"
`include "Reg_E_M.v"
`include "Reg_M_W.v"
`include "Reg_F_D.v"
`include "Hazard_Unit.v"


//! Top-level module for a 5-stage pipelined RISC-V RV32I processor
module Pip_RV32I(
  input         Clk_In,          //! Clock input
  input         Rst_In,          //! Reset input
  input  [31:0] Instruction_In,  //! Instruction input from instruction memory
  output [31:0] Instr_Addr_Out,  //! Program Counter output to instruction memory

  //! Data memory interface
  input  [31:0] DM_Data_In,      //! Data input from data memory
  output [31:0] DM_Addr_Out,     //! Address output to data memory
  output [31:0] DM_Data_Out,     //! Data output to data memory
  output [3:0]  DM_Mask_Out,     //! Byte-enable mask for data memory
  output        DM_WrEn_Out      //! Write enable signal for data memory
);

// -----------------------------
//! Fetch Stage Signals
// -----------------------------
wire [31:0] PC_F;           //! Current Program Counter
wire [31:0] PC_Plus4_F;     //! PC + 4
wire [31:0] Instruction_F;  //! Fetched instruction

//! Program Counter (PC) output
assign Instr_Addr_Out = PC_F;

// -----------------------------
//! Decode Stage Signals
// -----------------------------
wire [31:0] PC_D;           //! PC in Decode stage
wire [31:0] PC_Plus4_D;     //! PC + 4 in Decode stage
wire [31:0] Instruction_D;  //! Instruction in Decode stage
wire [6:0]  Opcode_D;       //! Opcode field
wire [2:0]  Func3_D;        //! Function 3 field
wire        Func7_D;        //! Function 7 field (only bit 30 used)
wire [4:0]  Src_Addr1_D;    //! Source register 1 address
wire [4:0]  Src_Addr2_D;    //! Source register 2 address
wire [4:0]  Des_Addr_D;     //! Destination register address
wire [24:0] Immediate_D;    //! Immediate field
// wire [31:0] Read_Data1_D;   //! Data from source register 1
// wire [31:0] Read_Data2_D;   //! Data from source register 2
wire [31:0] Imm_Ext_D;      //! Extended immediate value
wire        Reg_WrEn_D;     //! Register write enable
wire [2:0]  Result_Src_D;   //! Source selector for write-back
wire [2:0]  Imm_Type_D;     //! Immediate type
wire        Iadder_Src_D;   //! Immediate adder source selector
wire        ALU_Src_D;      //! ALU source selector
wire [3:0]  ALU_Control_D;  //! ALU control signals
wire        DM_WrEn_D;      //! Data memory write enable
wire [7:0]  Branch_Cond_D;  //! Branch condition codes
wire        Load_Unsigned_D;//! Load unsigned flag
wire [1:0]  Load_Size_D;    //! Load size (byte, half-word, word)

// -----------------------------
//! Execute Stage Signals
// -----------------------------
wire [31:0] PC_E;           //! PC in Execute stage
wire [31:0] PC_Plus4_E;     //! PC + 4 in Execute stage
wire [1:0]  Func3_E;        //! Function 3 field in Execute stage
wire        Reg_WrEn_E;     //! Register write enable in Execute stage
wire [2:0]  Result_Src_E;   //! Source selector for write-back in Execute stage
wire        Iadder_Src_E;   //! Immediate adder source selector in Execute stage
wire        ALU_Src_E;      //! ALU source selector in Execute stage
wire [3:0]  ALU_Control_E;  //! ALU control signals in Execute stage
wire        DM_WrEn_E;      //! Data memory write enable in Execute stage
wire [7:0]  Branch_Cond_E;  //! Branch condition codes in Execute stage
wire        Load_Unsigned_E;//! Load unsigned flag in Execute stage
wire [1:0]  Load_Size_E;    //! Load size in Execute stage
wire [31:0] Read_Data1_E;   //! Data from source register 1 in Execute stage
wire [31:0] Read_Data2_E;   //! Data from source register 2 in Execute stage
wire [31:0] Imm_Ext_E;      //! Extended immediate value in Execute stage
wire [31:0] ALU_Result_E;   //! Result from ALU
wire [31:0] Imm_Added_E;    //! Result from immediate adder
wire [4:0]  Des_Addr_E;     //! Destination register address in Execute stage
wire        Branch_Taken_E; //! Branch taken flag

// -----------------------------
//! Memory Stage Signals
// -----------------------------
wire [31:0] PC_Plus4_M;     //! PC + 4 in Memory stage
wire [31:0] ALU_Result_M;   //! Result from ALU in Memory stage
wire [31:0] Read_Data2_M;   //! Data from source register 2 in Memory stage
wire        Reg_WrEn_M;     //! Register write enable in Memory stage
wire [1:0]  Func3_M;        //! Function 3 field in Memory stage
wire [2:0]  Result_Src_M;   //! Source selector for write-back in Memory stage
wire [1:0]  Load_Size_M;    //! Load size in Memory stage
wire        Load_Unsigned_M;//! Load unsigned flag in Memory stage
wire [31:0] Loaded_Data_M;  //! Data loaded from memory
wire [31:0] DM_WrData_M;    //! Data to write to memory
wire [31:0] DM_Addr_M;      //! Address for data memory
wire        DM_Wr_Req_M;    //! Data memory write request
wire [3:0]  DM_Mask_M;      //! Byte-enable mask for data memory
wire        DM_WrEn_M;      //! Data memory write enable in Memory stage
wire [31:0] Imm_Ext_M;      //! Extended immediate value in Memory stage
wire [31:0] Imm_Added_M;    //! Result from immediate adder in Memory stage
wire [4:0]  Des_Addr_M;     //! Destination register address in Memory stage
wire [31:0] Data_M;         //! Data from data memory

// -----------------------------
//! Write Back Stage Signals
// -----------------------------
wire [31:0] PC_Plus4_W;     //! PC + 4 in Write Back stage
wire [31:0] ALU_Result_W;   //! Result from ALU in Write Back stage
wire [31:0] Loaded_Data_W;  //! Data loaded from memory in Write Back stage
wire [31:0] Imm_Ext_W;      //! Extended immediate value in Write Back stage
wire [31:0] Imm_Added_W;    //! Result from immediate adder in Write Back stage
wire [31:0] Result_W;       //! Final result to write back to register
wire        Reg_WrEn_W;     //! Register write enable in Write Back stage
wire [2:0]  Result_Src_W;   //! Source selector for write-back in Write Back stage
wire [4:0]  Des_Addr_W;     //! Destination register address in Write Back stage

// -----------------------------
//! Hazard Detection and Forwarding Signals
// -----------------------------
wire        Stall_F;        //! Stall fetch stage           // <NEW>
wire        Stall_D;        //! Stall decode stage          // <NEW>
wire        Flush_D;        //! Flush decode stage          // <NEW>
wire        Flush_E;        //! Flush execute stage         // <NEW>
wire [1:0]  ForwardA_E;     //! Forward control for ALU A   // <NEW>
wire [1:0]  ForwardB_E;     //! Forward control for ALU B   // <NEW>
wire [4:0]  Src_Addr1_E;    //! Source addr 1 in execute   // <NEW>
wire [4:0]  Src_Addr2_E;    //! Source addr 2 in execute   // <NEW>
wire [31:0] ForwardA_Data;  //! Forwarded data for A        // <NEW>
wire [31:0] ForwardB_Data;  //! Forwarded data for B        // <NEW>

// -----------------------------
//! Module Instantiations
// -----------------------------

//! Program Counter Unit
PC_Unit pc_unit (
  .Clk_In(Clk_In),
  .Rst_In(Rst_In),
  .Stall_In(Stall_F),                                       // <NEW>
  .Branch_Taken_In(Branch_Taken_E),
  .Target_PC_In(Imm_Added_E),
  .PC_Out(PC_F),
  .PC_Plus4_Out(PC_Plus4_F)
);

//! Fetch to Decode Pipeline Register
Reg_F_D reg_f_d (
  .Clk_In(Clk_In),
  .Rst_In(Rst_In),
  .Stall_In(Stall_D),                                       // <NEW>
  .Flush_In(Flush_D),                                       // <NEW>
  .PC_In(PC_F),
  .PC_Plus4_In(PC_Plus4_F),
  .Instr_In(Instruction_F),
  .PC_Out(PC_D),
  .PC_Plus4_Out(PC_Plus4_D),
  .Instr_Out(Instruction_D)
);

//! Assign fetched instruction
assign Instruction_F = Instruction_In;

//! Decode instruction fields
assign Opcode_D     = Instruction_D[6:0];
assign Func3_D      = Instruction_D[14:12];
assign Func7_D      = Instruction_D[30];
assign Src_Addr1_D  = Instruction_D[19:15];
assign Src_Addr2_D  = Instruction_D[24:20];
assign Des_Addr_D   = Instruction_D[11:7];
assign Immediate_D  = Instruction_D[31:7];

//! Instruction Decoder
Decoder decoder (
  .Opcode(Opcode_D),
  .Func3(Func3_D),
  .Func7(Func7_D),
  .Reg_WrEn_Out(Reg_WrEn_D),
  .Imm_Type_Out(Imm_Type_D),
  .Iadder_Src_Out(Iadder_Src_D),
  .ALU_Src_Out(ALU_Src_D),
  .ALU_Control_Out(ALU_Control_D),
  .DM_WrEn_Out(DM_WrEn_D),
  .bgeu_bltu_bge_blt_bne_beq_jalr_jal(Branch_Cond_D),
  .Load_Unsigned_Out(Load_Unsigned_D),
  .Load_Size_Out(Load_Size_D),
  .Result_Src_Out(Result_Src_D)
);

//! Register File
Register_File reg_file (
  .Clk_In(Clk_In),
  .Rst_In(Rst_In),
  .WrEn_In(Reg_WrEn_W),
  .Src_Addr1_In(Src_Addr1_D),
  .Src_Addr2_In(Src_Addr2_D),
  .Des_Addr_In(Des_Addr_W),
  .Des_Data_In(Result_W),
  .Src_Data1_Out(Read_Data1_E),
  .Src_Data2_Out(Read_Data2_E)
);

//! Immediate Extension Unit
Extend_Unit imm_extend (
  .Instr_In(Immediate_D),
  .Imm_Type_In(Imm_Type_D),
  .Imm_Out(Imm_Ext_D)
);

//! Decode to Execute Pipeline Register
Reg_D_E reg_d_e (
  .Clk_In(Clk_In),
  .Rst_In(Rst_In),
  .Flush_In(Flush_E),                                       // <NEW>
  .PC_In(PC_D),
  .PC_Plus4_In(PC_Plus4_D),
  // .Read_Data1_In(Read_Data1_D),
  // .Read_Data2_In(Read_Data2_D),
  .Imm_Ext_In(Imm_Ext_D),
  .Func3_In(Func3_D[1:0]),
  .Reg_WrEn_In(Reg_WrEn_D),
  .Result_Src_In(Result_Src_D),
  .Iadder_Src_In(Iadder_Src_D),
  .ALU_Src_In(ALU_Src_D),
  .ALU_Control_In(ALU_Control_D),
  .DM_WrEn_In(DM_WrEn_D),
  .Branch_Cond_In(Branch_Cond_D),
  .Load_Unsigned_In(Load_Unsigned_D),
  .Load_Size_In(Load_Size_D),
  .Des_Addr_In(Des_Addr_D),
  .Src_Addr1_In(Src_Addr1_D),                              // <NEW>
  .Src_Addr2_In(Src_Addr2_D),                              // <NEW>

  .PC_Out(PC_E),
  .PC_Plus4_Out(PC_Plus4_E),
  // .Read_Data1_Out(Read_Data1_E),
  // .Read_Data2_Out(Read_Data2_E),
  .Imm_Ext_Out(Imm_Ext_E),
  .Func3_Out(Func3_E),
  .Reg_WrEn_Out(Reg_WrEn_E),
  .Result_Src_Out(Result_Src_E),
  .Iadder_Src_Out(Iadder_Src_E),
  .ALU_Src_Out(ALU_Src_E),
  .ALU_Control_Out(ALU_Control_E),
  .DM_WrEn_Out(DM_WrEn_E),
  .Branch_Cond_Out(Branch_Cond_E),
  .Load_Unsigned_Out(Load_Unsigned_E),
  .Load_Size_Out(Load_Size_E),
  .Des_Addr_Out(Des_Addr_E),
  .Src_Addr1_Out(Src_Addr1_E),                             // <NEW>
  .Src_Addr2_Out(Src_Addr2_E)                              // <NEW>
);

wire [31:0] SrcA; //! ALU source A
wire [31:0] SrcB; //! ALU source B

//! Forwarding MUX for ALU Source A                         // <NEW>
assign ForwardA_Data = (ForwardA_E == 2'b01) ? ALU_Result_M :  // <NEW>
                       (ForwardA_E == 2'b10) ? Result_W :      // <NEW>
                       Read_Data1_E;                            // <NEW>

//! Forwarding MUX for ALU Source B (before ALU_Src mux)    // <NEW>
assign ForwardB_Data = (ForwardB_E == 2'b01) ? ALU_Result_M :  // <NEW>
                       (ForwardB_E == 2'b10) ? Result_W :      // <NEW>
                       Read_Data2_E;                            // <NEW>

assign SrcA = ForwardA_Data;                                // <EDIT>
assign SrcB = ALU_Src_E ? Imm_Ext_E : ForwardB_Data;

ALU alu (
    .Src1_In(SrcA),
    .Src2_In(SrcB),
    .ALU_Control_In(ALU_Control_E),
    .ALU_Result_Out(ALU_Result_E)
);

Imm_Adder Imm_Adder (
  .Iadder_Src_In(Iadder_Src_E),
  .PC_In(PC_E),
  .Src_Data1_In(ForwardA_Data),                             // <EDIT>
  .Imm_Data_In(Imm_Ext_E),
  .Added_Data_Out(Imm_Added_E)
);

//! Branch Decision Logic
Branch_Predictor  branch_unit (
  .Src_Data1_In(ForwardA_Data),                             // <EDIT>
  .Src_Data2_In(ForwardB_Data),                             // <EDIT>
  .bgeu_bltu_bge_blt_bne_beq_jalr_jal(Branch_Cond_E),
  .Branch_Taken_Out(Branch_Taken_E)
);

//! Execute to Memory Pipeline Register
Reg_E_M reg_e_m (
  .Clk_In(Clk_In),
  .Rst_In(Rst_In),
  .PC_Plus4_In(PC_Plus4_E),
  .ALU_Result_In(ALU_Result_E),
  .Read_Data2_In(Read_Data2_E),
  .Imm_Ext_In(Imm_Ext_E),
  .Added_Data_In(Imm_Added_E),
  .Func3_In(Func3_E),
  .Reg_WrEn_In(Reg_WrEn_E),
  .Result_Src_In(Result_Src_E),
  .DM_WrEn_In(DM_WrEn_E),
  .Load_Unsigned_In(Load_Unsigned_E),
  .Load_Size_In(Load_Size_E),
  .Des_Addr_In(Des_Addr_E),

  .PC_Plus4_Out(PC_Plus4_M),
  .ALU_Result_Out(ALU_Result_M),
  .Read_Data2_Out(Read_Data2_M),
  .Imm_Ext_Out(Imm_Ext_M),
  .Added_Data_Out(Imm_Added_M),
  .Func3_Out(Func3_M),
  .Reg_WrEn_Out(Reg_WrEn_M),
  .Result_Src_Out(Result_Src_M),
  .DM_WrEn_Out(DM_WrEn_M),
  .Load_Unsigned_Out(Load_Unsigned_M),
  .Load_Size_Out(Load_Size_M),
  .Des_Addr_Out(Des_Addr_M)
);

//! Data Memory Address Assignment
assign DM_Addr_Out   = DM_Addr_M;   //! Address to memory
assign DM_Data_Out   = DM_WrData_M;   //! Data to write
assign DM_WrEn_Out   = DM_Wr_Req_M;      //! Write enable signal
assign DM_Mask_Out   = DM_Mask_M;   //! Byte-enable mask
assign Data_M    = DM_Data_In; //! Data to write to memory

Store_Unit store_unit (
      .DM_WrEn_In(DM_WrEn_M),
      .Func3_In(Func3_M),
      .Added_Data_In(Imm_Added_M),
      .Src_Data2_In(Read_Data2_M),
      .DM_WrMask_Out(DM_Mask_M),
      .DM_WrData_Out(DM_WrData_M),
      .DM_Addr_Out(DM_Addr_M),
      .DM_WrEn_Out(DM_Wr_Req_M)
  );
//! Memory Load Data Processing
Load_Unit load_unit (
  .Read_Data_In(Data_M),
  .iadder_out_1to0_in(ALU_Result_M[1:0]),
  .Load_Size_In(Load_Size_M),
  .Load_Unsigned_In(Load_Unsigned_M),
  .Loaded_Data_Out(Loaded_Data_M)
);

//! Memory to Write Back Pipeline Register
Reg_M_W reg_m_w (
  .Clk_In(Clk_In),
  .Rst_In(Rst_In),
  .PC_Plus4_In(PC_Plus4_M),
  .ALU_Result_In(ALU_Result_M),
  .Loaded_Data_In(Loaded_Data_M),
  .Imm_Ext_In(Imm_Ext_M),
  .Added_Data_In(Imm_Added_M),
  .Reg_WrEn_In(Reg_WrEn_M),
  .Result_Src_In(Result_Src_M),
  .Des_Addr_In(Des_Addr_M),

  .PC_Plus4_Out(PC_Plus4_W),
  .ALU_Result_Out(ALU_Result_W),
  .Loaded_Data_Out(Loaded_Data_W),
  .Imm_Ext_Out(Imm_Ext_W),
  .Added_Data_Out(Imm_Added_W),
  .Reg_WrEn_Out(Reg_WrEn_W),
  .Result_Src_Out(Result_Src_W),
  .Des_Addr_Out(Des_Addr_W)
);

//! Result Mux: Select data to be written back to register file

  WB_Unit wb_unit (
      .Result_Src_In(Result_Src_W),
      .Imm_Data_In(Imm_Ext_W),
      .ALU_Result_In(ALU_Result_W),
      .Loaded_Data_In(Loaded_Data_W),
      .Imm_Added_In(Imm_Added_W),
      .PC_Plus4_In(PC_Plus4_W),
      .Result_Out(Result_W)
  );

//! Hazard Detection Unit                                  
Hazard_Unit hazard_unit (                                 
  .Src_Addr1_D_In(Src_Addr1_D),                             
  .Src_Addr2_D_In(Src_Addr2_D),

  .Des_Addr_E_In(Des_Addr_E),                                
  .Reg_WrEn_E_In(Reg_WrEn_E),                                
  .Result_Src_E_In(Result_Src_E),
  .Src_Addr1_E_In(Src_Addr1_E),
  .Src_Addr2_E_In(Src_Addr2_E),

  .Des_Addr_M_In(Des_Addr_M),                                
  .Reg_WrEn_M_In(Reg_WrEn_M),

  .Des_Addr_W_In(Des_Addr_W),                                
  .Reg_WrEn_W_In(Reg_WrEn_W),

  .Branch_Taken_E_In(Branch_Taken_E), 
                         
  .Stall_F_Out(Stall_F),                                      
  .Stall_D_Out(Stall_D),                                      
  .Flush_D_Out(Flush_D),                                      
  .Flush_E_Out(Flush_E),                                
  .ForwardA_E_Out(ForwardA_E),                                
  .ForwardB_E_Out(ForwardB_E)                                       
);                                                        


endmodule
