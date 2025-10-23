/* verilator lint_off WIDTHTRUNC */
/* verilator lint_off UNUSEDSIGNAL */
module IMemory #(parameter MEM_FILE = "",
                parameter SIZE = 1024)(
   input             Clk_In,
   input      [31:0] IM_Addr_In,  // address to be read
   output reg [31:0] IM_Instr_Out
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

   wire [29:0] word_addr = IM_Addr_In[31:2];
    always @(posedge Clk_In) begin
        IM_Instr_Out <= MEM[word_addr];
    end

endmodule
/* verilator lint_on UNUSEDSIGNAL */
/* verilator lint_on WIDTHTRUNC */
