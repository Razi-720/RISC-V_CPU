//! @brief Instruction Decoder Unit
//! @details
//! - Decodes the instruction fields (Opcode, Func3, Func7) and generates control signals.
//! - Supports R, I, S, B, U, J-type instruction formats.
//! - Outputs control signals for:
//!   - Register write enable
//!   - Immediate type selection
//!   - ALU and adder source selection
//!   - ALU operation selection
//!   - Data memory write enable
//!   - Branch type encoding
//!   - Load type handling
//!   - Result selection (ALU, memory, PC-relative, etc.)

module Decoder (
    input [6:0] Opcode,                          //! 7-bit opcode field of the instruction
    input [2:0] Func3,                           //! 3-bit funct3 field of the instruction
    input Func7,                                 //! 1-bit MSB of funct7 (used for distinguishing shift/sub operations)
    output reg Reg_WrEn_Out,                     //! Enables write-back to register file
    output reg [2:0] Imm_Type_Out,               //! Immediate format type (I, S, B, U, J)
    output reg Iadder_Src_Out,                   //! Selects source for instruction adder (PC or register)
    output reg ALU_Src_Out,                      //! Selects ALU operand source (register or immediate)
    output reg [3:0] ALU_Control_Out,            //! Control signal specifying ALU operation
    output reg DM_WrEn_Out,                      //! Enables data memory write
    output reg [7:0] bgeu_bltu_bge_blt_bne_beq_jalr_jal, //! Encodes branch or jump type
    output reg Load_Unsigned_Out,                //! Indicates if load is unsigned
    output reg [1:0] Load_Size_Out,              //! Specifies load data size (byte, halfword, word)
    output reg [2:0] Result_Src_Out              //! Selects the source of result to write back (ALU, memory, PC+imm, etc.)
);


    // wire [6:0] Opcode = Instruction_In[6:0];
    // wire [2:0] Func3 = Instruction_In[14:12];
    // wire Func7 = Instruction_In[30];
    /* verilator lint_off CASEINCOMPLETE */
    always @(*) begin
        // Default values
        Reg_WrEn_Out = 1'b0;
        Imm_Type_Out = 3'b000;
        Iadder_Src_Out = 1'b0;
        ALU_Src_Out = 1'b0;
        ALU_Control_Out = 4'b0000;
        DM_WrEn_Out = 1'b0;
        bgeu_bltu_bge_blt_bne_beq_jalr_jal = 8'b0;
        Load_Unsigned_Out = 1'b0;
        Load_Size_Out = 2'b00;
        Result_Src_Out = 3'b000;

        case (Opcode)
            // R-type instructions
            7'b0110011: begin
                Reg_WrEn_Out = 1'b1;
                ALU_Src_Out = 1'b0;
                Result_Src_Out = 3'b001; // ALU result
                
                case ({Func7, Func3})
                    4'b0000: ALU_Control_Out = 4'b0000; // ADD
                    4'b1000: ALU_Control_Out = 4'b1000; // SUB
                    4'b0001: ALU_Control_Out = 4'b0001; // SLL
                    4'b0010: ALU_Control_Out = 4'b0010; // SLT
                    4'b0011: ALU_Control_Out = 4'b0011; // SLTU
                    4'b0100: ALU_Control_Out = 4'b0100; // XOR
                    4'b0101: ALU_Control_Out = 4'b0101; // SRL
                    4'b1101: ALU_Control_Out = 4'b1101; // SRA
                    4'b0110: ALU_Control_Out = 4'b0110; // OR
                    4'b0111: ALU_Control_Out = 4'b0111; // AND
                    default: ALU_Control_Out = 4'b0000;
                endcase
            end
            
            // I-type instructions
            7'b0010011: begin
                Reg_WrEn_Out = 1'b1;
                ALU_Src_Out = 1'b1;
                Imm_Type_Out = 3'b001; // I-type
                Result_Src_Out = 3'b001; // ALU result
                
                case (Func3)
                    3'b000: ALU_Control_Out = 4'b0000; // ADDI
                    3'b001: ALU_Control_Out = 4'b0001; // SLLI
                    3'b010: ALU_Control_Out = 4'b0010; // SLTI
                    3'b011: ALU_Control_Out = 4'b0011; // SLTIU
                    3'b100: ALU_Control_Out = 4'b0100; // XORI
                    3'b101: ALU_Control_Out = (Func7 ? 4'b1101 : 4'b0101); // SRLI/SRAI
                    3'b110: ALU_Control_Out = 4'b0110; // ORI
                    3'b111: ALU_Control_Out = 4'b0111; // ANDI
                endcase
            end
            
            // Load instructions
            7'b0000011: begin
                Reg_WrEn_Out = 1'b1;
                ALU_Src_Out = 1'b1;
                Imm_Type_Out = 3'b001; // I-type
                Iadder_Src_Out = 1'b1;
                Result_Src_Out = 3'b101; // Load data
                Load_Size_Out = Func3[1:0];
                Load_Unsigned_Out = Func3[2];
                ALU_Control_Out = 4'b0000; // ADD for address calculation
            end
            
            // Store instructions
            7'b0100011: begin
                DM_WrEn_Out = 1'b1;
                ALU_Src_Out = 1'b1;
                Imm_Type_Out = 3'b010; // S-type
                Iadder_Src_Out = 1'b1;
                ALU_Control_Out = 4'b0000; // ADD for address calculation
            end
            
            // Branch instructions
            7'b1100011: begin
                Imm_Type_Out = 3'b011; // B-type
                case (Func3)
                    3'b000: bgeu_bltu_bge_blt_bne_beq_jalr_jal = 8'b00000100; // BEQ
                    3'b001: bgeu_bltu_bge_blt_bne_beq_jalr_jal = 8'b00001000; // BNE
                    3'b100: bgeu_bltu_bge_blt_bne_beq_jalr_jal = 8'b00010000; // BLT
                    3'b101: bgeu_bltu_bge_blt_bne_beq_jalr_jal = 8'b00100000; // BGE
                    3'b110: bgeu_bltu_bge_blt_bne_beq_jalr_jal = 8'b01000000; // BLTU
                    3'b111: bgeu_bltu_bge_blt_bne_beq_jalr_jal = 8'b10000000; // BGEU
                endcase
            end
            
            // JAL
            7'b1101111: begin
                Reg_WrEn_Out = 1'b1;
                Imm_Type_Out = 3'b101; // J-type
                Result_Src_Out = 3'b100; // PC+4
                bgeu_bltu_bge_blt_bne_beq_jalr_jal = 8'b00000001; // JAL
            end
            
            // JALR
            7'b1100111: begin
                Reg_WrEn_Out = 1'b1;
                Imm_Type_Out = 3'b001; // I-type
                Iadder_Src_Out = 1'b1;
                Result_Src_Out = 3'b100; // PC+4
                bgeu_bltu_bge_blt_bne_beq_jalr_jal = 8'b00000010; // JALR
            end
            
            // LUI
            7'b0110111: begin
                Reg_WrEn_Out = 1'b1;
                Imm_Type_Out = 3'b100; // U-type
                Result_Src_Out = 3'b010; // Immediate
            end
            
            // AUIPC
            7'b0010111: begin
                Reg_WrEn_Out = 1'b1;
                Imm_Type_Out = 3'b100; // U-type
                Result_Src_Out = 3'b011; // PC + immediate
            end
        endcase
    end
    /* verilator lint_on CASEINCOMPLETE */
endmodule
