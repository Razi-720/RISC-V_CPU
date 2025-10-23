//! @brief Write-Back Unit for RISC-V Pipeline
//! - Selects the final value to write back to the register file.
//! - Supports multiple sources including ALU, immediate, PC-relative, and memory data.
//! - Driven by `Result_Src_In` control signal from the control unit.

module WB_Unit(
    input [2:0] Result_Src_In,       //! Write-back source selector (from control unit)
    input [31:0] Imm_Data_In,        //! Immediate value (for LUI)
    input [31:0] ALU_Result_In,      //! Result from ALU
    input [31:0] Loaded_Data_In,     //! Data loaded from memory
    input [31:0] Imm_Added_In,       //! Result of PC + Imm (for AUIPC)
    input [31:0] PC_Plus4_In,        //! PC + 4 (used in JAL/JALR)
    output reg [31:0] Result_Out     //! Final result to be written to register file
);

    // Result selection based on control signal
    always @(*) begin
        case (Result_Src_In)
            3'b001: Result_Out = ALU_Result_In;     // ALU result
            3'b010: Result_Out = Imm_Data_In;       // LUI
            3'b011: Result_Out = Imm_Added_In;      // AUIPC
            3'b100: Result_Out = PC_Plus4_In;       // JAL/JALR
            3'b101: Result_Out = Loaded_Data_In;    // Memory load
            default: Result_Out = ALU_Result_In;    // Default fallback
        endcase
    end

endmodule
