/* verilator lint_off WIDTHTRUNC */
/* verilator lint_off UNUSEDSIGNAL */
module DMemory #(parameter MEM_FILE = "",
                parameter SIZE = 1024)(
   input             Clk_In,
   input      [31:0] DM_Addr_In,  // address to be read
   output reg [31:0] DM_RData_Out, // data read from memory
   input   	     DM_WrEn_In, // goes high when processor wants to read
   input      [31:0] DM_WData_In, // data to be written
   input      [3:0]  DM_Mask_In	// masks for writing the 4 bytes (1=write byte)
);

   reg [31:0] MEM [0:SIZE-1]; // 1536 4-bytes words = 6 Kb of RAM in total
    integer i;

   initial begin
    for (i=0; i<SIZE; i=i+1) begin
        MEM[i] = 'h0;
    end
    if (MEM_FILE!=0) begin
        $readmemh(MEM_FILE,MEM);
    end 
   end

   wire [29:0] word_addr = DM_Addr_In[31:2];
   
   always @(posedge Clk_In) begin
      if(DM_Mask_In[0]) MEM[word_addr][ 7:0 ] <= DM_WData_In[ 7:0 ];
      if(DM_Mask_In[1]) MEM[word_addr][15:8 ] <= DM_WData_In[15:8 ];
      if(DM_Mask_In[2]) MEM[word_addr][23:16] <= DM_WData_In[23:16];
      if(DM_Mask_In[3]) MEM[word_addr][31:24] <= DM_WData_In[31:24];	 
   end

   always @(posedge Clk_In) begin
      if(DM_WrEn_In) begin
         DM_RData_Out <= MEM[word_addr];
      end
   end

endmodule
/* verilator lint_on UNUSEDSIGNAL */
/* verilator lint_on WIDTHTRUNC */
