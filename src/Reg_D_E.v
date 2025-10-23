module Reg_D_E (
	input        Clk_In,
	input 	     Rst_In,
	input 	     Flush_In,
	input 	     Reg_WrEn_In,
	input [2:0]  Result_Src_In,
	input 	     DM_WrEn_In,
	input 		 Iadder_Src_In,
	input [1:0]	 Load_Size_In,
	input		 Load_Unsigned_In,
	input [3:0]  ALU_Control_In,
	input  	     ALU_Src_In,
	// input [31:0] Read_Data1_In,
	// input [31:0] Read_Data2_In,
	input [31:0] PC_In,
	input [1:0] Func3_In,
	input [7:0] Branch_Cond_In,
	//input [4:0]  Read_addr1_in,
	//input [4:0]  Read_addr2_in,
	input [31:0] Imm_Ext_In,
	input [31:0] PC_Plus4_In,
	input [4:0] Des_Addr_In,
	input [4:0] Src_Addr1_In,
	input [4:0] Src_Addr2_In,
	
	output reg [4:0] Src_Addr1_Out,
	output reg [4:0] Src_Addr2_Out,
	output reg [4:0] Des_Addr_Out,
	output reg   	  Reg_WrEn_Out,
	output reg [2:0]  Result_Src_Out,
	output reg   	  DM_WrEn_Out,
	output reg   	  Iadder_Src_Out,
	output reg [1:0]  Load_Size_Out,
	output reg	 	  Load_Unsigned_Out,
	output reg [3:0]  ALU_Control_Out,
	output reg 	  	  ALU_Src_Out,
	// output reg [31:0] Read_Data1_Out,
	// output reg [31:0] Read_Data2_Out,
	output reg [31:0] PC_Out,
	output reg [1:0] Func3_Out,
	output reg [7:0] Branch_Cond_Out,
	//output reg [4:0]  Read_addr1_out,
	//output reg [4:0]  Read_addr2_out,
	output reg [31:0] Imm_Ext_Out,
	output reg [31:0] PC_Plus4_Out
);

	always @(posedge Clk_In) begin
		if(Rst_In || Flush_In) begin
			Reg_WrEn_Out <= 1'b0;
			Result_Src_Out <= 3'b0;
			DM_WrEn_Out <= 1'b0;
			Iadder_Src_Out <= 1'b0;
			Load_Size_Out <= 2'b0;
			Load_Unsigned_Out <= 1'b0;
			ALU_Control_Out  <= 4'b0;
            ALU_Src_Out <= 1'b0;
			// Read_Data1_Out <= 32'b0;
			// Read_Data2_Out <= 32'b0;
            PC_Out <= 32'b0;
			Func3_Out <= 2'b0;
			Branch_Cond_Out <= 8'b0;
			//Read_addr1_out <= 5'b0;
			//Read_addr2_out <= 5'b0;
			Imm_Ext_Out <= 32'b0;
			PC_Plus4_Out <= 32'b0;
			Des_Addr_Out <= 5'b0;
			Src_Addr1_Out <= 5'b0;
			Src_Addr2_Out <= 5'b0;
		end
		else begin
			Reg_WrEn_Out <= Reg_WrEn_In;
			Result_Src_Out <= Result_Src_In;
			DM_WrEn_Out <= DM_WrEn_In;
			Iadder_Src_Out <= Iadder_Src_In;
			Load_Size_Out <= Load_Size_In;
			Load_Unsigned_Out <= Load_Unsigned_In;
			ALU_Control_Out  <= ALU_Control_In;
            ALU_Src_Out <= ALU_Src_In;
			// Read_Data1_Out  <= Read_Data1_In;
			// Read_Data2_Out  <= Read_Data2_In;
            PC_Out  <= PC_In;
			Func3_Out <= Func3_In;
			Branch_Cond_Out <= Branch_Cond_In;
			//Read_addr1_out <= Read_addr1_in;
			//Read_addr2_out <= Read_addr2_in;
			Imm_Ext_Out <= Imm_Ext_In;
			PC_Plus4_Out  <= PC_Plus4_In;
			Des_Addr_Out <= Des_Addr_In;
			Src_Addr1_Out <= Src_Addr1_In;
			Src_Addr2_Out <= Src_Addr2_In;
		end
			
	end

endmodule
