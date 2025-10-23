`include "../pulp_axi/src/axi_sim_mem.sv"
`include "RV32I_AXI_Lite_Wrapper.sv"
module RV32I_SoC (
    input         Clk_In,
    input         Rst_In
);

// AXI signals for Instruction Memory
wire        axi_imem_arvalid;
wire        axi_imem_arready;
wire [31:0] axi_imem_araddr;  
wire        axi_imem_rvalid;
wire        axi_imem_rready;
wire [31:0] axi_imem_rdata;
wire [1:0]  axi_imem_rresp;
// AXI signals for Data Memory
wire        axi_dmem_arvalid;
wire        axi_dmem_arready;
wire [31:0] axi_dmem_araddr;  
wire        axi_dmem_rvalid;
wire        axi_dmem_rready;
wire [31:0] axi_dmem_rdata;
wire [1:0]  axi_dmem_rresp;
wire        axi_dmem_awvalid;
wire        axi_dmem_awready;
wire [31:0] axi_dmem_awaddr;  
wire        axi_dmem_wvalid;
wire        axi_dmem_wready;
wire [31:0] axi_dmem_wdata;
wire [3:0]  axi_dmem_wstrb;
wire        axi_dmem_bvalid;
wire        axi_dmem_bready;
wire [1:0]  axi_dmem_bresp;

// Instruction Memory (read-only)
axi_sim_mem_intf #(
  .ADDR_WIDTH (32),
  .DATA_WIDTH (32),
  .MEM_SIZE   (32'h00010000),  // 64 KB
  .INIT_FILE  ("program.hex")  // preload with program
) instr_mem (
  .clk        (Clk_In),
  .rst_n      (Rst_In),

  // AXI Read connected
  .ar_valid   (axi_imem_arvalid),
  .ar_ready   (axi_imem_arready),
  .ar_addr    (axi_imem_araddr),

  .r_valid    (axi_imem_rvalid),
  .r_ready    (axi_imem_rready),
  .r_data     (axi_imem_rdata),
  .r_resp     (axi_imem_rresp),

  // AXI Write tied off
  .aw_valid   (1'b0),
  .aw_addr    ('0),
  .w_valid    (1'b0),
  .w_data     ('0),
  .w_strb     ('0),
  .b_ready    (1'b0)
);

// Data Memory (read/write)
axi_sim_mem_intf #(
  .ADDR_WIDTH (32),
  .DATA_WIDTH (32),
  .MEM_SIZE   (32'h00010000)   // 64 KB
) data_mem (
  .clk        (clk),
  .rst_n      (rst_n),

  // Full AXI Slave connection
  .ar_valid   (axi_dmem_arvalid),
  .ar_ready   (axi_dmem_arready),
  .ar_addr    (axi_dmem_araddr),

  .r_valid    (axi_dmem_rvalid),
  .r_ready    (axi_dmem_rready),
  .r_data     (axi_dmem_rdata),
  .r_resp     (axi_dmem_rresp),

  .aw_valid   (axi_dmem_awvalid),
  .aw_ready   (axi_dmem_awready),
  .aw_addr    (axi_dmem_awaddr),

  .w_valid    (axi_dmem_wvalid),
  .w_ready    (axi_dmem_wready),
  .w_data     (axi_dmem_wdata),
  .w_strb     (axi_dmem_wstrb),

  .b_valid    (axi_dmem_bvalid),
  .b_ready    (axi_dmem_bready),
  .b_resp     (axi_dmem_bresp)
);

// AXI Wrapper

RV32I_AXI_Lite_Wrapper axi_wrapper (
    .Clk_In(Clk_In),
    .Rst_In(Rst_In),

    // Instruction Memory AXI Interface
    .instr_axi_arvalid (instr_axi_arvalid),
    .instr_axi_arready (instr_axi_arready),
    .instr_axi_araddr  (instr_axi_araddr),

    .instr_axi_rvalid  (instr_axi_rvalid),
    .instr_axi_rready  (instr_axi_rready),
    .instr_axi_rdata   (instr_axi_rdata),
    .instr_axi_rresp   (instr_axi_rresp),

    // Data Memory AXI Interface
    .data_axi_arvalid  (data_axi_arvalid),
    .data_axi_arready  (data_axi_arready),
    .data_axi_araddr   (data_axi_araddr),

    .data_axi_rvalid   (data_axi_rvalid),
    .data_axi_rready   (data_axi_rready),
    .data_axi_rdata    (data_axi_rdata),
    .data_axi_rresp    (data_axi_rresp),

    .data_axi_awvalid  (data_axi_awvalid),
    .data_axi_awready  (data_axi_awready),
    .data_axi_awaddr   (data_axi_awaddr),

    .data_axi_wvalid   (data_axi_wvalid),
    .data_axi_wready   (data_axi_wready),
    .data_axi_wdata    (data_axi_wdata),
    .data_axi_wstrb    (data_axi_wstrb),

    .data_axi_bvalid   (data_axi_bvalid),
    .data_axi_bready   (data_axi_bready),
    .data_axi_bresp    (data_axi_bresp),

    // CPU Core Instruction Memory Interface
    .Instr_Addr_Out(instr_addr),     // From Instr_Addr_Out
    .Instruction_In(instruction),  // To Instruction_In

    // CPU Core Data Memory Interface
    .DM_Addr_Out(dm_addr),        // From DM_Addr_Out
    .DM_Data_Out(dm_data_in),     // From DM_Data_Out
    .DM_Mask_Out(dm_mask),         // From DM_Mask_Out
    .DM_WrEn_Out(dm_wren),               // From DM_WrEn_Out
    .DM_Data_In(dm_data_out)       // To dm_data
);

endmodule
