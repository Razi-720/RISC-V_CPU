//! Hazard Detection Unit for RV32I Pipeline
//! Detects data hazards, load-use hazards, and control hazards
//! Generates stall and flush signals for pipeline control

module Hazard_Unit(
  //! Decode stage inputs
  input [4:0]  Src_Addr1_D_In,      //! Source register 1 address from decode
  input [4:0]  Src_Addr2_D_In,      //! Source register 2 address from decode
  
  //! Execute stage inputs
  input [4:0]  Des_Addr_E_In,       //! Destination register address from execute
  input        Reg_WrEn_E_In,       //! Register write enable from execute
  input [2:0]  Result_Src_E_In,     //! Result source selector from execute
  input [4:0]  Src_Addr1_E_In,      //! Source register 1 address from decode
  input [4:0]  Src_Addr2_E_In,      //! Source register 2 address from decode
  
  // //! Memory stage inputs
  input [4:0]  Des_Addr_M_In,       //! Destination register address from memory
  input        Reg_WrEn_M_In,       //! Register write enable from memory
  
  // //! Write-back stage inputs
  input [4:0]  Des_Addr_W_In,       //! Destination register address from write-back
  input        Reg_WrEn_W_In,       //! Register write enable from write-back
  
  //! Control hazard input
  input        Branch_Taken_E_In,   //! Branch taken signal from execute
  
  //! Pipeline control outputs
  output       Stall_F_Out,          //! Stall fetch stage
  output       Stall_D_Out,          //! Stall decode stage
  output       Flush_D_Out,          //! Flush decode stage
  output       Flush_E_Out,           //! Flush execute stage
    //! Forwarding control outputs
  output [1:0] ForwardA_E_Out,       //! Forward control for ALU source A
  output [1:0] ForwardB_E_Out       //! Forward control for ALU source B
);

  //! Internal hazard detection signals
  wire load_use_hazard;
  wire control_hazard;

  assign ForwardA_E_Out = 
    //! Forward from EX/MEM stage (highest priority)
    ((Reg_WrEn_M_In && (Des_Addr_M_In == Src_Addr1_E_In)) && (Des_Addr_M_In != 5'b00000)) ? 2'b01 :
    //! Forward from MEM/WB stage (lower priority)
    ((Reg_WrEn_W_In && (Des_Addr_W_In == Src_Addr1_E_In)) && (Des_Addr_W_In != 5'b00000)) ? 2'b10 :
    //! No forwarding needed
    2'b00;
  
  //! Forwarding logic for source B
  //! Same priority scheme as source A
  assign ForwardB_E_Out = 
    //! Forward from EX/MEM stage (highest priority)
    ((Reg_WrEn_M_In && (Des_Addr_M_In == Src_Addr2_E_In)) && (Des_Addr_M_In != 5'b00000)) ? 2'b01 :
    //! Forward from MEM/WB stage (lower priority)
    ((Reg_WrEn_W_In && (Des_Addr_W_In == Src_Addr2_E_In))&& (Des_Addr_W_In != 5'b00000)) ? 2'b10 :
    //! No forwarding needed
    2'b00;
  
  //! Load-use hazard detection
  //! Occurs when current instruction needs data from previous load instruction
  //! Result_Src_E_In == 3'b001 indicates load instruction in execute stage
  assign load_use_hazard = (Result_Src_E_In == 3'b101) && Reg_WrEn_E_In && 
                          (Des_Addr_E_In != 5'b00000) &&
                          ((Des_Addr_E_In == Src_Addr1_D_In) || (Des_Addr_E_In == Src_Addr2_D_In));
  
  //! Control hazard detection
  //! Occurs when branch is taken - need to flush incorrect instructions
  assign control_hazard = Branch_Taken_E_In;

  //! Pipeline control logic
  //! Load-use hazard requires stalling decode and fetch, flushing execute
  assign Stall_F_Out = load_use_hazard;
  assign Stall_D_Out = load_use_hazard;
  
  //! Flush logic
  //! Control hazards flush decode and execute stages
  //! Load-use hazards flush execute stage (insert bubble)
  assign Flush_D_Out = control_hazard;
  assign Flush_E_Out = control_hazard || load_use_hazard;

endmodule
