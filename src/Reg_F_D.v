// --------------------------------------------------------------------------------------------------
// Register Block Between Fetch and Decode
// --------------------------------------------------------------------------------------------------

module Reg_F_D(
	input Clk_In,
	//input en,
	input Rst_In,
	input Stall_In,
	input Flush_In,
	input [31:0] Instr_In,
	input [31:0] PC_In,
	input [31:0] PC_Plus4_In,
	output reg [31:0] Instr_Out,
	output reg [31:0] PC_Out,
	output reg [31:0] PC_Plus4_Out
);
	always @ (posedge Clk_In) begin
		if (Rst_In || Flush_In) begin
			Instr_Out <= 32'h0000_0000;
			PC_Out <= 32'h0000_0000;
			PC_Plus4_Out <= 32'h0000_0000;
		end 
		else if (Stall_In) begin
			// Maintain current values on stall
			Instr_Out <= Instr_Out;
			PC_Out <= PC_Out; 
			PC_Plus4_Out <= PC_Plus4_Out;
		end
		else begin
			Instr_Out <= Instr_In;
			PC_Out <= PC_In; 
			PC_Plus4_Out <= PC_Plus4_In;
		end
	end
endmodule
