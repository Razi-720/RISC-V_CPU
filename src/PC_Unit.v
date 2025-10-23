//! @brief Program Counter (PC) Unit
//! - Holds and updates the current PC value.
//! - Supports branching via `Branch_Taken_In`.
//! - On reset, PC is cleared to zero.
//! - Computes PC + 4 for sequential instruction fetches.

module PC_Unit(
  input Clk_In,                   //! Clock input
  input Rst_In,                   //! Synchronous reset
  input Stall_In,                 //! Flush signal (not used in this module)
  input Branch_Taken_In,         //! Branch control: 1 = take branch to Target_PC_In, 0 = PC + 4
  input [31:0] Target_PC_In,     //! Target address for branch/jump
  output reg [31:0] PC_Out,      //! Current program counter
  output [31:0] PC_Plus4_Out     //! PC + 4 output
);

  reg [31:0] Temp_PC_Out;

  // Compute PC + 4
  assign PC_Plus4_Out = PC_Out + 4;

  // Sequential PC update on rising edge
  always @(posedge Clk_In) begin
      if (Rst_In) begin
          PC_Out <= 32'h00000000;
      end
      else if (Stall_In) begin
          PC_Out <= PC_Out; //! Maintain current PC value on stall
      end
      else begin
          PC_Out <= Temp_PC_Out;
      end
  end

  // Combinational logic for next PC decision
  always @(*) begin
      if (Branch_Taken_In)
          Temp_PC_Out = Target_PC_In;
      else
          Temp_PC_Out = PC_Plus4_Out;
  end

endmodule
