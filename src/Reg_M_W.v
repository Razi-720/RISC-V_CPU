module Reg_M_W (
	input 	 	Clk_In,
	input 		Rst_In,
	input			Reg_WrEn_In,
	input [2:0]		Result_Src_In,
	input [31:0]   	ALU_Result_In,
	input [31:0]	Loaded_Data_In,
	input [31:0]    Added_Data_In,
	input [31:0]	PC_Plus4_In,
	input [31:0]	Imm_Ext_In,
	input [4:0] 	Des_Addr_In,
	
	output reg [4:0] 	Des_Addr_Out,
	output reg [31:0]	Imm_Ext_Out,
	output reg	  		Reg_WrEn_Out,
	output reg [2:0]  	Result_Src_Out,
	output reg [31:0] 	ALU_Result_Out,
	output reg [31:0] 	Loaded_Data_Out,
	output reg [31:0]   Added_Data_Out,
	output reg [31:0] 	PC_Plus4_Out
);
	always @(posedge Clk_In) begin
		if(Rst_In) begin
			Reg_WrEn_Out <= 1'b0;
			Result_Src_Out <= 3'b0;
			ALU_Result_Out  <= 32'b0;
			Loaded_Data_Out <= 32'b0;
			Added_Data_Out <= 32'b0;
			PC_Plus4_Out <= 32'b0;
			Imm_Ext_Out <= 32'b0;
			Des_Addr_Out <= 5'b0;
		end
		else begin
			Reg_WrEn_Out <= Reg_WrEn_In;
			Result_Src_Out <= Result_Src_In;
			ALU_Result_Out <= ALU_Result_In;
			Loaded_Data_Out <= Loaded_Data_In;
			Added_Data_Out <= Added_Data_In;
			PC_Plus4_Out <= PC_Plus4_In;
			Imm_Ext_Out <= Imm_Ext_In;
			Des_Addr_Out <= Des_Addr_In;
		end
	end
		
endmodule
