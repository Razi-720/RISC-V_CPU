//! @brief Store Unit for Memory Writes
//! @details
//! - Generates byte-enable mask (`DM_WrMask_Out`) and properly aligned write data (`DM_WrData_Out`) based on store type.
//! - Handles SB (Store Byte), SH (Store Halfword), and SW (Store Word).
//! - Calculates store alignment and enables masked writing to memory.

module Store_Unit(
    input DM_WrEn_In,               //! Write enable signal from control unit
    input [1:0] Func3_In,           //! Store instruction type (SB=00, SH=01, SW=10)
    input [31:0] Added_Data_In,     //! Effective address from base + offset
    input [31:0] Src_Data2_In,      //! Data to write to memory
    output reg [3:0] DM_WrMask_Out, //! Byte-enable mask for memory write
    output reg [31:0] DM_WrData_Out,//! Formatted data for memory write
    output [31:0] DM_Addr_Out,      //! Memory address for the write
    output DM_WrEn_Out              //! Final memory write enable
);

    // Pass-through address and write enable
    assign DM_Addr_Out = Added_Data_In;
    assign DM_WrEn_Out = DM_WrEn_In;

    // Store data formatting and write mask generation
    always @(*) begin
        case (Func3_In)
            2'b00: begin // SB - Store Byte
                DM_WrData_Out = {4{Src_Data2_In[7:0]}}; // replicate byte
                case (Added_Data_In[1:0])
                    2'b00: DM_WrMask_Out = 4'b0001;
                    2'b01: DM_WrMask_Out = 4'b0010;
                    2'b10: DM_WrMask_Out = 4'b0100;
                    2'b11: DM_WrMask_Out = 4'b1000;
                endcase
            end
            2'b01: begin // SH - Store Halfword
                DM_WrData_Out = {2{Src_Data2_In[15:0]}}; // replicate halfword
                DM_WrMask_Out = Added_Data_In[1] ? 4'b1100 : 4'b0011;
            end
            2'b10: begin // SW - Store Word
                DM_WrData_Out = Src_Data2_In;
                DM_WrMask_Out = 4'b1111;
            end
            default: begin // Invalid
                DM_WrData_Out = Src_Data2_In;
                DM_WrMask_Out = 4'b0000;
            end
        endcase
    end

endmodule
