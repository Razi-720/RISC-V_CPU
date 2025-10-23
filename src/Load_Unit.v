//! @brief Load Unit
//! @details
//! - Selects and extracts byte, halfword, or word from memory read data.
//! - Handles signed and unsigned load operations.
//! - Supports RISC-V LB, LBU, LH, LHU, and LW instructions.
//! - Uses lower bits of address to determine the sub-word location.
//! - Sign-extends or zero-extends based on `Load_Unsigned_In`.

module Load_Unit(
    input [31:0] Read_Data_In,         //! Raw 32-bit data from memory
    input [1:0] iadder_out_1to0_in,    //! Lower 2 bits of load address (from I-addr) for byte/half selection
    input [1:0] Load_Size_In,          //! 00 = byte, 01 = halfword, 10 = word
    input Load_Unsigned_In,            //! 1 = zero-extend, 0 = sign-extend
    output reg [31:0] Loaded_Data_Out  //! Processed load result
);
    always @(*) begin
        case (Load_Size_In)
            2'b00: begin // LB/LBU
                case (iadder_out_1to0_in)
                    2'b00: Loaded_Data_Out = Load_Unsigned_In ? {24'b0, Read_Data_In[7:0]} : {{24{Read_Data_In[7]}}, Read_Data_In[7:0]};
                    2'b01: Loaded_Data_Out = Load_Unsigned_In ? {24'b0, Read_Data_In[15:8]} : {{24{Read_Data_In[15]}}, Read_Data_In[15:8]};
                    2'b10: Loaded_Data_Out = Load_Unsigned_In ? {24'b0, Read_Data_In[23:16]} : {{24{Read_Data_In[23]}}, Read_Data_In[23:16]};
                    2'b11: Loaded_Data_Out = Load_Unsigned_In ? {24'b0, Read_Data_In[31:24]} : {{24{Read_Data_In[31]}}, Read_Data_In[31:24]};
                endcase
            end
            2'b01: begin // LH/LHU
                if (iadder_out_1to0_in[1]) begin
                    Loaded_Data_Out = Load_Unsigned_In ? {16'b0, Read_Data_In[31:16]} : {{16{Read_Data_In[31]}}, Read_Data_In[31:16]};
                end
                else begin
                    Loaded_Data_Out = Load_Unsigned_In ? {16'b0, Read_Data_In[15:0]} : {{16{Read_Data_In[15]}}, Read_Data_In[15:0]};
                end
            end
            2'b10: begin // LW
                Loaded_Data_Out = Read_Data_In;
            end
            default: begin
                Loaded_Data_Out = 32'b0;
            end
        endcase
    end
endmodule
