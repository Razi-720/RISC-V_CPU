// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.Pip_RV32I__DOT__Instruction_In = vlSelfRef.Instruction_In;
    vlSelfRef.Pip_RV32I__DOT__DM_Data_In = vlSelfRef.DM_Data_In;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Func3_In 
        = (3U & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                 >> 0xcU));
    vlSelfRef.Pip_RV32I__DOT__load_unit__DOT__iadder_out_1to0_in 
        = (3U & (vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out 
                 >> 0U));
    vlSelfRef.Instr_Addr_Out = vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Out;
    vlSelfRef.Pip_RV32I__DOT__Instr_Addr_Out = vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Out;
    vlSelfRef.Pip_RV32I__DOT__Instruction_D = vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out;
    vlSelfRef.Pip_RV32I__DOT__ALU_Src_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Src_Out;
    vlSelfRef.DM_Addr_Out = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_Addr_Out = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_Addr_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_Addr_Out 
        = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out;
    vlSelfRef.DM_WrEn_Out = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_WrEn_Out = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_Wr_Req_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrEn_Out 
        = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__Instruction_F = vlSelfRef.Instruction_In;
    vlSelfRef.Pip_RV32I__DOT__PC_F = vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Out;
    vlSelfRef.Pip_RV32I__DOT__Immediate_D = (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                             >> 7U);
    vlSelfRef.Pip_RV32I__DOT__ALU_Control_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out;
    vlSelfRef.Pip_RV32I__DOT__Iadder_Src_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Iadder_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_Out;
    vlSelfRef.Pip_RV32I__DOT__Branch_Cond_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out;
    vlSelfRef.Pip_RV32I__DOT__Data_M = vlSelfRef.DM_Data_In;
    vlSelfRef.Pip_RV32I__DOT__Load_Size_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_Out;
    vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out;
    vlSelfRef.Pip_RV32I__DOT__ALU_Result_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out;
    vlSelfRef.Pip_RV32I__DOT__Result_Src_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Ext_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Imm_Ext_Out;
    vlSelfRef.Pip_RV32I__DOT__ALU_Result_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__ALU_Result_Out;
    vlSelfRef.Pip_RV32I__DOT__Loaded_Data_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Loaded_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Added_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Added_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_Plus4_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__PC_Plus4_Out;
    vlSelfRef.Pip_RV32I__DOT__Src_Addr1_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr1_Out;
    vlSelfRef.Pip_RV32I__DOT__Src_Addr2_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr2_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_WrEn_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_D = vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_Plus4_D = vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Plus4_Out;
    vlSelfRef.Pip_RV32I__DOT__Load_Size_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Load_Size_Out;
    vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Load_Unsigned_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_WrEn_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__Func3_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Func3_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_Plus4_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_Plus4_Out;
    vlSelfRef.Pip_RV32I__DOT__Result_Src_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Result_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_Plus4_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__PC_Plus4_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Ext_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Imm_Ext_Out;
    vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Reg_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__Des_Addr_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Ext_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Imm_Ext_Out;
    vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Reg_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__Result_Src_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Result_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__Des_Addr_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_Out;
    vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Reg_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__Des_Addr_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out;
    vlSelfRef.Pip_RV32I__DOT__Loaded_Data_M = ((0U 
                                                == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_Out))
                                                ? (
                                                   (2U 
                                                    & vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out)
                                                    ? 
                                                   ((1U 
                                                     & vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out)
                                                     ? 
                                                    ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out)
                                                      ? 
                                                     VL_SHIFTR_III(32,32,32, vlSelfRef.DM_Data_In, 0x18U)
                                                      : 
                                                     (((- (IData)(
                                                                  (vlSelfRef.DM_Data_In 
                                                                   >> 0x1fU))) 
                                                       << 8U) 
                                                      | (vlSelfRef.DM_Data_In 
                                                         >> 0x18U)))
                                                     : 
                                                    ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out)
                                                      ? 
                                                     (0xffU 
                                                      & (vlSelfRef.DM_Data_In 
                                                         >> 0x10U))
                                                      : 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelfRef.DM_Data_In 
                                                                      >> 0x17U)))) 
                                                       << 8U) 
                                                      | (0xffU 
                                                         & (vlSelfRef.DM_Data_In 
                                                            >> 0x10U)))))
                                                    : 
                                                   ((1U 
                                                     & vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out)
                                                     ? 
                                                    ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out)
                                                      ? 
                                                     (0xffU 
                                                      & (vlSelfRef.DM_Data_In 
                                                         >> 8U))
                                                      : 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelfRef.DM_Data_In 
                                                                      >> 0xfU)))) 
                                                       << 8U) 
                                                      | (0xffU 
                                                         & (vlSelfRef.DM_Data_In 
                                                            >> 8U))))
                                                     : 
                                                    ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out)
                                                      ? 
                                                     (0xffU 
                                                      & vlSelfRef.DM_Data_In)
                                                      : 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelfRef.DM_Data_In 
                                                                      >> 7U)))) 
                                                       << 8U) 
                                                      | (0xffU 
                                                         & vlSelfRef.DM_Data_In)))))
                                                : (
                                                   (1U 
                                                    == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_Out))
                                                    ? 
                                                   ((2U 
                                                     & vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out)
                                                     ? 
                                                    ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out)
                                                      ? 
                                                     VL_SHIFTR_III(32,32,32, vlSelfRef.DM_Data_In, 0x10U)
                                                      : 
                                                     (((- (IData)(
                                                                  (vlSelfRef.DM_Data_In 
                                                                   >> 0x1fU))) 
                                                       << 0x10U) 
                                                      | (vlSelfRef.DM_Data_In 
                                                         >> 0x10U)))
                                                     : 
                                                    ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out)
                                                      ? 
                                                     (0xffffU 
                                                      & vlSelfRef.DM_Data_In)
                                                      : 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelfRef.DM_Data_In 
                                                                      >> 0xfU)))) 
                                                       << 0x10U) 
                                                      | (0xffffU 
                                                         & vlSelfRef.DM_Data_In))))
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_Out))
                                                     ? vlSelfRef.DM_Data_In
                                                     : 0U)));
    vlSelfRef.Pip_RV32I__DOT__PC_Plus4_F = ((IData)(4U) 
                                            + vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Out);
    vlSelfRef.Pip_RV32I__DOT__Func7_D = (1U & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                               >> 0x1eU));
    vlSelfRef.Pip_RV32I__DOT__Des_Addr_D = (0x1fU & 
                                            (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                             >> 7U));
    vlSelfRef.Pip_RV32I__DOT__Read_Data2_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Read_Data2_Out;
    vlSelfRef.Pip_RV32I__DOT__Clk_In = vlSelfRef.Clk_In;
    vlSelfRef.Pip_RV32I__DOT__Rst_In = vlSelfRef.Rst_In;
    vlSelfRef.Pip_RV32I__DOT__Imm_Added_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__Func3_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Func3_Out;
    vlSelfRef.Pip_RV32I__DOT__Func3_D = (7U & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                               >> 0xcU));
    vlSelfRef.Pip_RV32I__DOT__Opcode_D = (0x7fU & vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out);
    vlSelfRef.Pip_RV32I__DOT__ForwardB_E = (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Reg_WrEn_Out) 
                                             & (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr2_Out) 
                                                 == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out)) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out))))
                                             ? 1U : 
                                            (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Reg_WrEn_Out) 
                                              & (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr2_Out) 
                                                  == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out)) 
                                                 & (0U 
                                                    != (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out))))
                                              ? 2U : 0U));
    vlSelfRef.Pip_RV32I__DOT__ForwardA_E = (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Reg_WrEn_Out) 
                                             & (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr1_Out) 
                                                 == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out)) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out))))
                                             ? 1U : 
                                            (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Reg_WrEn_Out) 
                                              & (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr1_Out) 
                                                  == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out)) 
                                                 & (0U 
                                                    != (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out))))
                                              ? 2U : 0U));
    vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D = (0x1fU 
                                             & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                >> 0x14U));
    vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D = (0x1fU 
                                             & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                >> 0xfU));
    vlSelfRef.Pip_RV32I__DOT__Result_W = ((4U & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out))
                                           ? ((2U & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out))
                                               ? vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__ALU_Result_Out
                                               : ((1U 
                                                   & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out))
                                                   ? vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Loaded_Data_Out
                                                   : vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__PC_Plus4_Out))
                                           : ((2U & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out))
                                                   ? vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Added_Data_Out
                                                   : vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Imm_Ext_Out)
                                               : vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__ALU_Result_Out));
    vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_In 
        = vlSelfRef.Pip_RV32I__DOT__Instruction_F;
    vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_In = vlSelfRef.Pip_RV32I__DOT__PC_F;
    vlSelfRef.Pip_RV32I__DOT__imm_extend__DOT__Instr_In 
        = vlSelfRef.Pip_RV32I__DOT__Immediate_D;
    vlSelfRef.Pip_RV32I__DOT__alu__DOT__ALU_Control_In 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Control_E;
    vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__Iadder_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__Iadder_Src_E;
    vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__PC_In 
        = vlSelfRef.Pip_RV32I__DOT__PC_E;
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal 
        = vlSelfRef.Pip_RV32I__DOT__Branch_Cond_E;
    vlSelfRef.Pip_RV32I__DOT__load_unit__DOT__Read_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Data_M;
    vlSelfRef.Pip_RV32I__DOT__load_unit__DOT__Load_Size_In 
        = vlSelfRef.Pip_RV32I__DOT__Load_Size_M;
    vlSelfRef.Pip_RV32I__DOT__load_unit__DOT__Load_Unsigned_In 
        = vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_M;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__ALU_Result_In 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Result_M;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__Result_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__Result_Src_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__Imm_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__ALU_Result_In 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Result_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__Loaded_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Loaded_Data_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__Imm_Added_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Added_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__PC_Plus4_In 
        = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_W;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Src_Addr1_E_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr1_E;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Src_Addr2_E_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr2_E;
    vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__DM_WrEn_M;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_In = vlSelfRef.Pip_RV32I__DOT__PC_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_Plus4_In 
        = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_D;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_In 
        = vlSelfRef.Pip_RV32I__DOT__Load_Size_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_In 
        = vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__DM_WrEn_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Func3_In 
        = vlSelfRef.Pip_RV32I__DOT__Func3_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__PC_Plus4_In 
        = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_E;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__Result_Src_M;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__PC_Plus4_In 
        = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_M;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Imm_Ext_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_M;
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_W;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Reg_WrEn_W_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_W;
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Des_Addr_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_W;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Des_Addr_W_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_W;
    vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__Imm_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Imm_Ext_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Reg_WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_E;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Reg_WrEn_E_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Result_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__Result_Src_E;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Result_Src_E_In 
        = vlSelfRef.Pip_RV32I__DOT__Result_Src_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_E;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Des_Addr_E_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_E;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Reg_WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_M;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Reg_WrEn_M_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_M;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_M;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Des_Addr_M_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_M;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Loaded_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Loaded_Data_M;
    vlSelfRef.Pip_RV32I__DOT__load_unit__DOT__Loaded_Data_Out 
        = vlSelfRef.Pip_RV32I__DOT__Loaded_Data_M;
    vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Plus4_In 
        = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_F;
    vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Plus4_Out 
        = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_F;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Func7 = vlSelfRef.Pip_RV32I__DOT__Func7_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_D;
    vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__Src_Data2_In 
        = vlSelfRef.Pip_RV32I__DOT__Read_Data2_M;
    vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Clk_In 
        = vlSelfRef.Pip_RV32I__DOT__Clk_In;
    vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Clk_In 
        = vlSelfRef.Pip_RV32I__DOT__Clk_In;
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Clk_In 
        = vlSelfRef.Pip_RV32I__DOT__Clk_In;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Clk_In 
        = vlSelfRef.Pip_RV32I__DOT__Clk_In;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Clk_In 
        = vlSelfRef.Pip_RV32I__DOT__Clk_In;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Clk_In 
        = vlSelfRef.Pip_RV32I__DOT__Clk_In;
    vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Rst_In 
        = vlSelfRef.Pip_RV32I__DOT__Rst_In;
    vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Rst_In 
        = vlSelfRef.Pip_RV32I__DOT__Rst_In;
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Rst_In 
        = vlSelfRef.Pip_RV32I__DOT__Rst_In;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Rst_In 
        = vlSelfRef.Pip_RV32I__DOT__Rst_In;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Rst_In 
        = vlSelfRef.Pip_RV32I__DOT__Rst_In;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Rst_In 
        = vlSelfRef.Pip_RV32I__DOT__Rst_In;
    vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__Added_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Added_M;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Added_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Added_M;
    vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__Func3_In 
        = vlSelfRef.Pip_RV32I__DOT__Func3_M;
    if ((0U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_M))) {
        vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out 
            = ((vlSelfRef.Pip_RV32I__DOT__Read_Data2_M 
                << 0x18U) | ((0xff0000U & (vlSelfRef.Pip_RV32I__DOT__Read_Data2_M 
                                           << 0x10U)) 
                             | ((0xff00U & (vlSelfRef.Pip_RV32I__DOT__Read_Data2_M 
                                            << 8U)) 
                                | (0xffU & vlSelfRef.Pip_RV32I__DOT__Read_Data2_M))));
        vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out 
            = ((2U & vlSelfRef.Pip_RV32I__DOT__Imm_Added_M)
                ? ((1U & vlSelfRef.Pip_RV32I__DOT__Imm_Added_M)
                    ? 8U : 4U) : ((1U & vlSelfRef.Pip_RV32I__DOT__Imm_Added_M)
                                   ? 2U : 1U));
    } else if ((1U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_M))) {
        vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out 
            = ((vlSelfRef.Pip_RV32I__DOT__Read_Data2_M 
                << 0x10U) | (0xffffU & vlSelfRef.Pip_RV32I__DOT__Read_Data2_M));
        vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out 
            = ((2U & vlSelfRef.Pip_RV32I__DOT__Imm_Added_M)
                ? 0xcU : 3U);
    } else {
        vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out 
            = vlSelfRef.Pip_RV32I__DOT__Read_Data2_M;
        vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out 
            = ((2U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_M))
                ? 0xfU : 0U);
    }
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Func3 = vlSelfRef.Pip_RV32I__DOT__Func3_D;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Opcode 
        = vlSelfRef.Pip_RV32I__DOT__Opcode_D;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__DM_WrEn_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Iadder_Src_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Load_Size_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Load_Unsigned_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out = 0U;
    if (((((((((0x33U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D)) 
               | (0x13U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) 
              | (3U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) 
             | (0x23U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) 
            | (0x63U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) 
           | (0x6fU == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) 
          | (0x67U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) 
         | (0x37U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D)))) {
        if ((0x33U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out = 0U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out 
                = ((IData)(vlSelfRef.Pip_RV32I__DOT__Func7_D)
                    ? ((4U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                        ? ((2U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                            ? 0U : ((1U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                     ? 0xdU : 0U)) : 
                       ((2U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                         ? 0U : ((1U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                  ? 0U : 8U))) : ((4U 
                                                   & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                     ? 7U
                                                     : 6U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                     ? 5U
                                                     : 4U))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                     ? 3U
                                                     : 2U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                     ? 1U
                                                     : 0U))));
        } else if ((0x13U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out 
                = ((4U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                    ? ((2U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                        ? ((1U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                            ? 7U : 6U) : ((1U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                           ? ((IData)(vlSelfRef.Pip_RV32I__DOT__Func7_D)
                                               ? 0xdU
                                               : 5U)
                                           : 4U)) : 
                   ((2U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                     ? ((1U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                         ? 3U : 2U) : ((1U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                        ? 1U : 0U)));
        } else if ((3U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out = 5U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out = 0U;
        } else {
            if ((0x23U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                if ((0x63U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out 
                        = ((0x6fU == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                            ? 4U : ((0x67U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                                     ? 4U : 2U));
                    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = 1U;
                }
            }
            if ((0x23U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out = 1U;
                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out = 0U;
            }
        }
        if ((0x33U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
            if ((0x13U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                if ((3U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                    if ((0x23U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                        vlSelfRef.Pip_RV32I__DOT__decoder__DOT__DM_WrEn_Out = 1U;
                    }
                    if ((0x23U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                        if ((0x63U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                            if ((0U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))) {
                                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 4U;
                            } else if ((1U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))) {
                                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 8U;
                            } else if ((4U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))) {
                                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 0x10U;
                            } else if ((5U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))) {
                                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 0x20U;
                            } else if ((6U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))) {
                                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 0x40U;
                            } else if ((7U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))) {
                                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 0x80U;
                            }
                        } else if ((0x6fU == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 1U;
                        } else if ((0x67U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 2U;
                        }
                    }
                }
                if ((3U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Iadder_Src_Out = 1U;
                    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Load_Size_Out 
                        = (3U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D));
                    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Load_Unsigned_Out 
                        = (1U & ((IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D) 
                                 >> 2U));
                } else if ((0x23U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Iadder_Src_Out = 1U;
                } else if ((0x63U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                    if ((0x6fU != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                        if ((0x67U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Iadder_Src_Out = 1U;
                        }
                    }
                }
            }
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out 
                = ((0x13U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                    ? 1U : ((3U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                             ? 1U : ((0x23U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                                      ? 2U : ((0x63U 
                                               == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                                               ? 3U
                                               : ((0x6fU 
                                                   == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                                                   ? 5U
                                                   : 
                                                  ((0x67U 
                                                    == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                                                    ? 1U
                                                    : 4U))))));
        }
    } else if ((0x17U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
        vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out = 3U;
        vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = 1U;
        vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out = 4U;
    }
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__ForwardB_E_Out 
        = vlSelfRef.Pip_RV32I__DOT__ForwardB_E;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__ForwardA_E_Out 
        = vlSelfRef.Pip_RV32I__DOT__ForwardA_E;
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Src_Addr2_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr2_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Src_Addr2_D_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D;
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Src_Addr1_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr1_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Src_Addr1_D_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D;
    vlSelfRef.Pip_RV32I__DOT__Stall_F = ((5U == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Result_Src_Out)) 
                                         & ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Reg_WrEn_Out) 
                                            & ((0U 
                                                != (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_Out)) 
                                               & (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_Out) 
                                                   == (IData)(vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D)) 
                                                  | ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_Out) 
                                                     == (IData)(vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D))))));
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Des_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Result_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__Result_Out 
        = vlSelfRef.Pip_RV32I__DOT__Result_W;
    vlSelfRef.Pip_RV32I__DOT__Read_Data2_E = (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out) 
                                               == (IData)(vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D))
                                               ? vlSelfRef.Pip_RV32I__DOT__Result_W
                                               : vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Temp_Src_Data2);
    vlSelfRef.Pip_RV32I__DOT__Read_Data1_E = (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out) 
                                               == (IData)(vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D))
                                               ? vlSelfRef.Pip_RV32I__DOT__Result_W
                                               : vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Temp_Src_Data1);
    vlSelfRef.DM_Data_Out = vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_Data_Out = vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_WrData_M = vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out;
    vlSelfRef.DM_Mask_Out = vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_Mask_Out = vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_Mask_M = vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out;
    vlSelfRef.Pip_RV32I__DOT__Result_Src_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_WrEn_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__ALU_Src_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__Iadder_Src_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Iadder_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__Load_Size_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Load_Size_Out;
    vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Load_Unsigned_Out;
    vlSelfRef.Pip_RV32I__DOT__Branch_Cond_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal;
    vlSelfRef.Pip_RV32I__DOT__ALU_Control_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Type_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Ext_D = ((4U & (IData)(vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out))
                                            ? ((2U 
                                                & (IData)(vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                                 >> 0x1fU))) 
                                                     << 0x14U) 
                                                    | (((0xff000U 
                                                         & vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out) 
                                                        | (0x800U 
                                                           & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                              >> 9U))) 
                                                       | (0x7feU 
                                                          & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                             >> 0x14U))))
                                                    : 
                                                   (0xfffff000U 
                                                    & vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out)))
                                            : ((2U 
                                                & (IData)(vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | ((0x800U 
                                                        & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                                >> 7U)))))
                                                    : 
                                                   (((- (IData)(
                                                                (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | ((0xfe0U 
                                                        & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                           >> 0x14U)) 
                                                       | (IData)(vlSelfRef.Pip_RV32I__DOT__Des_Addr_D))))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                       >> 0x14U))
                                                    : 0U)));
    vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Stall_In 
        = vlSelfRef.Pip_RV32I__DOT__Stall_F;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Stall_F_Out 
        = vlSelfRef.Pip_RV32I__DOT__Stall_F;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Stall_D_Out 
        = vlSelfRef.Pip_RV32I__DOT__Stall_F;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__load_use_hazard 
        = vlSelfRef.Pip_RV32I__DOT__Stall_F;
    vlSelfRef.Pip_RV32I__DOT__Stall_D = vlSelfRef.Pip_RV32I__DOT__Stall_F;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Read_Data2_In 
        = vlSelfRef.Pip_RV32I__DOT__Read_Data2_E;
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Src_Data2_Out 
        = vlSelfRef.Pip_RV32I__DOT__Read_Data2_E;
    vlSelfRef.Pip_RV32I__DOT__ForwardB_Data = ((1U 
                                                == (IData)(vlSelfRef.Pip_RV32I__DOT__ForwardB_E))
                                                ? vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelfRef.Pip_RV32I__DOT__ForwardB_E))
                                                    ? vlSelfRef.Pip_RV32I__DOT__Result_W
                                                    : vlSelfRef.Pip_RV32I__DOT__Read_Data2_E));
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Src_Data1_Out 
        = vlSelfRef.Pip_RV32I__DOT__Read_Data1_E;
    vlSelfRef.Pip_RV32I__DOT__ForwardA_Data = ((1U 
                                                == (IData)(vlSelfRef.Pip_RV32I__DOT__ForwardA_E))
                                                ? vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelfRef.Pip_RV32I__DOT__ForwardA_E))
                                                    ? vlSelfRef.Pip_RV32I__DOT__Result_W
                                                    : vlSelfRef.Pip_RV32I__DOT__Read_Data1_E));
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Result_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__Result_Src_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Reg_WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__DM_WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__DM_WrEn_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Src_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Iadder_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__Iadder_Src_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Load_Size_In 
        = vlSelfRef.Pip_RV32I__DOT__Load_Size_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Load_Unsigned_In 
        = vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_In 
        = vlSelfRef.Pip_RV32I__DOT__Branch_Cond_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_In 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Control_D;
    vlSelfRef.Pip_RV32I__DOT__imm_extend__DOT__Imm_Type_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Type_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Imm_Ext_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_D;
    vlSelfRef.Pip_RV32I__DOT__imm_extend__DOT__Imm_Out 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_D;
    vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Stall_In 
        = vlSelfRef.Pip_RV32I__DOT__Stall_D;
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__Src_Data2_In 
        = vlSelfRef.Pip_RV32I__DOT__ForwardB_Data;
    vlSelfRef.Pip_RV32I__DOT__SrcB = ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Src_Out)
                                       ? vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Imm_Ext_Out
                                       : vlSelfRef.Pip_RV32I__DOT__ForwardB_Data);
    vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__Src_Data1_In 
        = vlSelfRef.Pip_RV32I__DOT__ForwardA_Data;
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__Src_Data1_In 
        = vlSelfRef.Pip_RV32I__DOT__ForwardA_Data;
    vlSelfRef.Pip_RV32I__DOT__alu__DOT__signed_src1 
        = vlSelfRef.Pip_RV32I__DOT__ForwardA_Data;
    vlSelfRef.Pip_RV32I__DOT__SrcA = vlSelfRef.Pip_RV32I__DOT__ForwardA_Data;
    vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__temp_adder_src 
        = ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Iadder_Src_Out)
            ? vlSelfRef.Pip_RV32I__DOT__ForwardA_Data
            : vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_Out);
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__equal 
        = (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
           == vlSelfRef.Pip_RV32I__DOT__ForwardB_Data);
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__less_than 
        = VL_LTS_III(32, vlSelfRef.Pip_RV32I__DOT__ForwardA_Data, vlSelfRef.Pip_RV32I__DOT__ForwardB_Data);
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__less_than_unsigned 
        = (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
           < vlSelfRef.Pip_RV32I__DOT__ForwardB_Data);
    vlSelfRef.Pip_RV32I__DOT__alu__DOT__Src2_In = vlSelfRef.Pip_RV32I__DOT__SrcB;
    vlSelfRef.Pip_RV32I__DOT__alu__DOT__signed_src2 
        = vlSelfRef.Pip_RV32I__DOT__SrcB;
    vlSelfRef.Pip_RV32I__DOT__ALU_Result_E = ((8U & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                               ? ((4U 
                                                   & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlSelfRef.Pip_RV32I__DOT__ForwardA_Data, 
                                                                   (0x1fU 
                                                                    & vlSelfRef.Pip_RV32I__DOT__SrcB))
                                                     : 0U))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     - vlSelfRef.Pip_RV32I__DOT__SrcB))))
                                               : ((4U 
                                                   & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                     ? 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     & vlSelfRef.Pip_RV32I__DOT__SrcB)
                                                     : 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     | vlSelfRef.Pip_RV32I__DOT__SrcB))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                     ? 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     >> 
                                                     (0x1fU 
                                                      & vlSelfRef.Pip_RV32I__DOT__SrcB))
                                                     : 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     ^ vlSelfRef.Pip_RV32I__DOT__SrcB)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                     ? 
                                                    ((vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                      < vlSelfRef.Pip_RV32I__DOT__SrcB)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    (VL_LTS_III(32, vlSelfRef.Pip_RV32I__DOT__ForwardA_Data, vlSelfRef.Pip_RV32I__DOT__SrcB)
                                                      ? 1U
                                                      : 0U))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                     ? 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     << 
                                                     (0x1fU 
                                                      & vlSelfRef.Pip_RV32I__DOT__SrcB))
                                                     : 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     + vlSelfRef.Pip_RV32I__DOT__SrcB)))));
    vlSelfRef.Pip_RV32I__DOT__alu__DOT__Src1_In = vlSelfRef.Pip_RV32I__DOT__SrcA;
    vlSelfRef.Pip_RV32I__DOT__Imm_Added_E = (vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__temp_adder_src 
                                             + vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Imm_Ext_Out);
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__not_equal 
        = (1U & (~ (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__equal)));
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__greater_equal 
        = (1U & (~ (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__less_than)));
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__greater_equal_unsigned 
        = (1U & (~ (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__less_than_unsigned)));
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_In 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Result_E;
    vlSelfRef.Pip_RV32I__DOT__alu__DOT__ALU_Result_Out 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Result_E;
    vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Target_PC_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Added_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Added_E;
    vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__Added_Data_Out 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Added_E;
    vlSelfRef.Pip_RV32I__DOT__Branch_Taken_E = ((((1U 
                                                   == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                  | (2U 
                                                     == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))) 
                                                 | (((4U 
                                                      == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                     | (8U 
                                                        == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))) 
                                                    | ((0x10U 
                                                        == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                       | ((0x20U 
                                                           == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                          | ((0x40U 
                                                              == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                             | (0x80U 
                                                                == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))))))) 
                                                & ((1U 
                                                    == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                   | ((2U 
                                                       == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                      | ((4U 
                                                          == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))
                                                          ? (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__equal)
                                                          : 
                                                         ((8U 
                                                           == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))
                                                           ? (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__not_equal)
                                                           : 
                                                          ((0x10U 
                                                            == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))
                                                            ? (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__less_than)
                                                            : 
                                                           ((0x20U 
                                                             == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))
                                                             ? (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__greater_equal)
                                                             : 
                                                            ((0x40U 
                                                              == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))
                                                              ? (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__less_than_unsigned)
                                                              : (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__greater_equal_unsigned)))))))));
    if (vlSelfRef.Pip_RV32I__DOT__Branch_Taken_E) {
        vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Branch_Taken_In = 1U;
        vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Branch_Taken_E_In = 1U;
        vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__Branch_Taken_Out = 1U;
        vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Flush_D_Out = 1U;
        vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__control_hazard = 1U;
        vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Temp_PC_Out 
            = vlSelfRef.Pip_RV32I__DOT__Imm_Added_E;
        vlSelfRef.Pip_RV32I__DOT__Flush_D = 1U;
    } else {
        vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Branch_Taken_In = 0U;
        vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Branch_Taken_E_In = 0U;
        vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__Branch_Taken_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Flush_D_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__control_hazard = 0U;
        vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Temp_PC_Out 
            = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_F;
        vlSelfRef.Pip_RV32I__DOT__Flush_D = 0U;
    }
    vlSelfRef.Pip_RV32I__DOT__Flush_E = ((IData)(vlSelfRef.Pip_RV32I__DOT__Branch_Taken_E) 
                                         | (IData)(vlSelfRef.Pip_RV32I__DOT__Stall_F));
    vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Flush_In 
        = vlSelfRef.Pip_RV32I__DOT__Flush_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Flush_In 
        = vlSelfRef.Pip_RV32I__DOT__Flush_E;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Flush_E_Out 
        = vlSelfRef.Pip_RV32I__DOT__Flush_E;
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out;
    __Vdly__Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out = 0;
    CData/*0:0*/ __VdlySet__Pip_RV32I__DOT__reg_file__DOT__register__v0;
    __VdlySet__Pip_RV32I__DOT__reg_file__DOT__register__v0 = 0;
    CData/*0:0*/ __VdlySet__Pip_RV32I__DOT__reg_file__DOT__register__v32;
    __VdlySet__Pip_RV32I__DOT__reg_file__DOT__register__v32 = 0;
    IData/*31:0*/ __VdlyVal__Pip_RV32I__DOT__reg_file__DOT__register__v33;
    __VdlyVal__Pip_RV32I__DOT__reg_file__DOT__register__v33 = 0;
    CData/*4:0*/ __VdlyDim0__Pip_RV32I__DOT__reg_file__DOT__register__v33;
    __VdlyDim0__Pip_RV32I__DOT__reg_file__DOT__register__v33 = 0;
    // Body
    __VdlySet__Pip_RV32I__DOT__reg_file__DOT__register__v0 = 0U;
    __VdlySet__Pip_RV32I__DOT__reg_file__DOT__register__v32 = 0U;
    __Vdly__Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
        = vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out;
    if (vlSelfRef.Rst_In) {
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 1U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 2U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 3U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 4U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 5U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 6U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 7U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 8U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 9U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0xaU;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0xbU;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0xcU;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0xdU;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0xeU;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0xfU;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x10U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x11U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x12U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x13U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x14U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x15U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x16U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x17U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x18U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x19U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x1aU;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x1bU;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x1cU;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x1dU;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x1eU;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x1fU;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__i = 0x20U;
        vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Out = 0U;
        __VdlySet__Pip_RV32I__DOT__reg_file__DOT__register__v0 = 1U;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__PC_Plus4_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Result_Src_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Imm_Ext_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Func3_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Read_Data2_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__ALU_Result_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__PC_Plus4_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Imm_Ext_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Loaded_Data_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Added_Data_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out = 0U;
    } else {
        vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Out 
            = ((IData)(vlSelfRef.Pip_RV32I__DOT__Stall_F)
                ? vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Out
                : vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Temp_PC_Out);
        if (((IData)(vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_W) 
             & (0U != (IData)(vlSelfRef.Pip_RV32I__DOT__Des_Addr_W)))) {
            __VdlySet__Pip_RV32I__DOT__reg_file__DOT__register__v32 = 1U;
            __VdlyVal__Pip_RV32I__DOT__reg_file__DOT__register__v33 
                = vlSelfRef.Pip_RV32I__DOT__Result_W;
            __VdlyDim0__Pip_RV32I__DOT__reg_file__DOT__register__v33 
                = vlSelfRef.Pip_RV32I__DOT__Des_Addr_W;
        }
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__PC_Plus4_Out 
            = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_E;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Result_Src_Out 
            = vlSelfRef.Pip_RV32I__DOT__Result_Src_E;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Imm_Ext_Out 
            = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_E;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_Out 
            = vlSelfRef.Pip_RV32I__DOT__Load_Size_E;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Func3_Out 
            = vlSelfRef.Pip_RV32I__DOT__Func3_E;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out 
            = vlSelfRef.Pip_RV32I__DOT__Imm_Added_E;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Read_Data2_Out 
            = vlSelfRef.Pip_RV32I__DOT__Read_Data2_E;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out 
            = vlSelfRef.Pip_RV32I__DOT__ALU_Result_E;
        vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out 
            = vlSelfRef.Pip_RV32I__DOT__Des_Addr_E;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out 
            = vlSelfRef.Pip_RV32I__DOT__Result_Src_M;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__ALU_Result_Out 
            = vlSelfRef.Pip_RV32I__DOT__ALU_Result_M;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__PC_Plus4_Out 
            = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_M;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Imm_Ext_Out 
            = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_M;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Loaded_Data_Out 
            = vlSelfRef.Pip_RV32I__DOT__Loaded_Data_M;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Added_Data_Out 
            = vlSelfRef.Pip_RV32I__DOT__Imm_Added_M;
        vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out 
            = vlSelfRef.Pip_RV32I__DOT__Des_Addr_M;
    }
    if (((IData)(vlSelfRef.Rst_In) | (IData)(vlSelfRef.Pip_RV32I__DOT__Flush_D))) {
        vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Plus4_Out = 0U;
        __Vdly__Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out = 0U;
    } else if (vlSelfRef.Pip_RV32I__DOT__Stall_D) {
        vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Out 
            = vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Out;
        vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Plus4_Out 
            = vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Plus4_Out;
        __Vdly__Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
            = vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out;
    } else {
        vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Out 
            = vlSelfRef.Pip_RV32I__DOT__PC_F;
        vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Plus4_Out 
            = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_F;
        __Vdly__Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
            = vlSelfRef.Pip_RV32I__DOT__Instruction_F;
    }
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out 
        = ((1U & (~ (IData)(vlSelfRef.Rst_In))) && (IData)(vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_E));
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_Out 
        = ((1U & (~ (IData)(vlSelfRef.Rst_In))) && (IData)(vlSelfRef.Pip_RV32I__DOT__DM_WrEn_E));
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Load_Unsigned_Out 
        = ((1U & (~ ((IData)(vlSelfRef.Rst_In) | (IData)(vlSelfRef.Pip_RV32I__DOT__Flush_E)))) 
           && (IData)(vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_D));
    if (((IData)(vlSelfRef.Rst_In) | (IData)(vlSelfRef.Pip_RV32I__DOT__Flush_E))) {
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Load_Size_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_Plus4_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Result_Src_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Imm_Ext_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Func3_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr2_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr1_Out = 0U;
    } else {
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Load_Size_Out 
            = vlSelfRef.Pip_RV32I__DOT__Load_Size_D;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_Plus4_Out 
            = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_D;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out 
            = vlSelfRef.Pip_RV32I__DOT__ALU_Control_D;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_Out 
            = vlSelfRef.Pip_RV32I__DOT__PC_D;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Result_Src_Out 
            = vlSelfRef.Pip_RV32I__DOT__Result_Src_D;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_Out 
            = vlSelfRef.Pip_RV32I__DOT__Des_Addr_D;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out 
            = vlSelfRef.Pip_RV32I__DOT__Branch_Cond_D;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Imm_Ext_Out 
            = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_D;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Func3_Out 
            = (3U & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                     >> 0xcU));
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr2_Out 
            = vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D;
        vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr1_Out 
            = vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D;
    }
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__DM_WrEn_Out 
        = ((1U & (~ ((IData)(vlSelfRef.Rst_In) | (IData)(vlSelfRef.Pip_RV32I__DOT__Flush_E)))) 
           && (IData)(vlSelfRef.Pip_RV32I__DOT__DM_WrEn_D));
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Src_Out 
        = ((1U & (~ ((IData)(vlSelfRef.Rst_In) | (IData)(vlSelfRef.Pip_RV32I__DOT__Flush_E)))) 
           && (IData)(vlSelfRef.Pip_RV32I__DOT__ALU_Src_D));
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Iadder_Src_Out 
        = ((1U & (~ ((IData)(vlSelfRef.Rst_In) | (IData)(vlSelfRef.Pip_RV32I__DOT__Flush_E)))) 
           && (IData)(vlSelfRef.Pip_RV32I__DOT__Iadder_Src_D));
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Reg_WrEn_Out 
        = ((1U & (~ ((IData)(vlSelfRef.Rst_In) | (IData)(vlSelfRef.Pip_RV32I__DOT__Flush_E)))) 
           && (IData)(vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_D));
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Temp_Src_Data2 
        = vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register
        [vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D];
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Temp_Src_Data1 
        = vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register
        [vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D];
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Reg_WrEn_Out 
        = ((1U & (~ (IData)(vlSelfRef.Rst_In))) && (IData)(vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_E));
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Reg_WrEn_Out 
        = ((1U & (~ (IData)(vlSelfRef.Rst_In))) && (IData)(vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_M));
    if (__VdlySet__Pip_RV32I__DOT__reg_file__DOT__register__v0) {
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[1U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[2U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[3U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[4U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[5U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[6U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[7U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[8U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[9U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0xaU] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0xbU] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0xcU] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0xdU] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0xeU] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0xfU] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x10U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x11U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x12U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x13U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x14U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x15U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x16U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x17U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x18U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x19U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x1aU] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x1bU] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x1cU] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x1dU] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x1eU] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0x1fU] = 0U;
    }
    if (__VdlySet__Pip_RV32I__DOT__reg_file__DOT__register__v32) {
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[0U] = 0U;
        vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__register[__VdlyDim0__Pip_RV32I__DOT__reg_file__DOT__register__v33] 
            = __VdlyVal__Pip_RV32I__DOT__reg_file__DOT__register__v33;
    }
    vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
        = __Vdly__Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_D = vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_Plus4_D = vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Plus4_Out;
    vlSelfRef.Instr_Addr_Out = vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Out;
    vlSelfRef.Pip_RV32I__DOT__Instr_Addr_Out = vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_F = vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_Plus4_F = ((IData)(4U) 
                                            + vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Out);
    vlSelfRef.Pip_RV32I__DOT__PC_Plus4_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__PC_Plus4_Out;
    vlSelfRef.Pip_RV32I__DOT__Result_Src_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Result_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Ext_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Imm_Ext_Out;
    vlSelfRef.Pip_RV32I__DOT__Load_Size_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_Out;
    vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out;
    vlSelfRef.DM_WrEn_Out = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_WrEn_Out = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_Wr_Req_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrEn_Out 
        = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_WrEn_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Load_Unsigned_Out;
    vlSelfRef.Pip_RV32I__DOT__Load_Size_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Load_Size_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_WrEn_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_Plus4_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_Plus4_Out;
    vlSelfRef.Pip_RV32I__DOT__Func3_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Func3_Out;
    vlSelfRef.Pip_RV32I__DOT__ALU_Control_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out;
    vlSelfRef.DM_Addr_Out = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_Addr_Out = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_Addr_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_Addr_Out 
        = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Added_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__ALU_Src_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_Out;
    vlSelfRef.Pip_RV32I__DOT__Iadder_Src_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Iadder_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__Result_Src_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Result_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Reg_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__Des_Addr_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_Out;
    vlSelfRef.Pip_RV32I__DOT__Branch_Cond_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Ext_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Imm_Ext_Out;
    vlSelfRef.Pip_RV32I__DOT__Read_Data2_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Read_Data2_Out;
    vlSelfRef.Pip_RV32I__DOT__Func3_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Func3_Out;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Func3_In 
        = (3U & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                 >> 0xcU));
    vlSelfRef.Pip_RV32I__DOT__Instruction_D = vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out;
    vlSelfRef.Pip_RV32I__DOT__Immediate_D = (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                             >> 7U);
    vlSelfRef.Pip_RV32I__DOT__Func7_D = (1U & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                               >> 0x1eU));
    vlSelfRef.Pip_RV32I__DOT__Des_Addr_D = (0x1fU & 
                                            (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                             >> 7U));
    vlSelfRef.Pip_RV32I__DOT__Func3_D = (7U & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                               >> 0xcU));
    vlSelfRef.Pip_RV32I__DOT__Opcode_D = (0x7fU & vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out);
    vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D = (0x1fU 
                                             & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                >> 0x14U));
    vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D = (0x1fU 
                                             & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                >> 0xfU));
    vlSelfRef.Pip_RV32I__DOT__Src_Addr2_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr2_Out;
    vlSelfRef.Pip_RV32I__DOT__Src_Addr1_E = vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr1_Out;
    vlSelfRef.Pip_RV32I__DOT__load_unit__DOT__iadder_out_1to0_in 
        = (3U & (vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out 
                 >> 0U));
    vlSelfRef.Pip_RV32I__DOT__ALU_Result_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out;
    vlSelfRef.Pip_RV32I__DOT__Loaded_Data_M = ((0U 
                                                == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_Out))
                                                ? (
                                                   (2U 
                                                    & vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out)
                                                    ? 
                                                   ((1U 
                                                     & vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out)
                                                     ? 
                                                    ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out)
                                                      ? 
                                                     VL_SHIFTR_III(32,32,32, vlSelfRef.DM_Data_In, 0x18U)
                                                      : 
                                                     (((- (IData)(
                                                                  (vlSelfRef.DM_Data_In 
                                                                   >> 0x1fU))) 
                                                       << 8U) 
                                                      | (vlSelfRef.DM_Data_In 
                                                         >> 0x18U)))
                                                     : 
                                                    ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out)
                                                      ? 
                                                     (0xffU 
                                                      & (vlSelfRef.DM_Data_In 
                                                         >> 0x10U))
                                                      : 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelfRef.DM_Data_In 
                                                                      >> 0x17U)))) 
                                                       << 8U) 
                                                      | (0xffU 
                                                         & (vlSelfRef.DM_Data_In 
                                                            >> 0x10U)))))
                                                    : 
                                                   ((1U 
                                                     & vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out)
                                                     ? 
                                                    ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out)
                                                      ? 
                                                     (0xffU 
                                                      & (vlSelfRef.DM_Data_In 
                                                         >> 8U))
                                                      : 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelfRef.DM_Data_In 
                                                                      >> 0xfU)))) 
                                                       << 8U) 
                                                      | (0xffU 
                                                         & (vlSelfRef.DM_Data_In 
                                                            >> 8U))))
                                                     : 
                                                    ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out)
                                                      ? 
                                                     (0xffU 
                                                      & vlSelfRef.DM_Data_In)
                                                      : 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelfRef.DM_Data_In 
                                                                      >> 7U)))) 
                                                       << 8U) 
                                                      | (0xffU 
                                                         & vlSelfRef.DM_Data_In)))))
                                                : (
                                                   (1U 
                                                    == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_Out))
                                                    ? 
                                                   ((2U 
                                                     & vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out)
                                                     ? 
                                                    ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out)
                                                      ? 
                                                     VL_SHIFTR_III(32,32,32, vlSelfRef.DM_Data_In, 0x10U)
                                                      : 
                                                     (((- (IData)(
                                                                  (vlSelfRef.DM_Data_In 
                                                                   >> 0x1fU))) 
                                                       << 0x10U) 
                                                      | (vlSelfRef.DM_Data_In 
                                                         >> 0x10U)))
                                                     : 
                                                    ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out)
                                                      ? 
                                                     (0xffffU 
                                                      & vlSelfRef.DM_Data_In)
                                                      : 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelfRef.DM_Data_In 
                                                                      >> 0xfU)))) 
                                                       << 0x10U) 
                                                      | (0xffffU 
                                                         & vlSelfRef.DM_Data_In))))
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_Out))
                                                     ? vlSelfRef.DM_Data_In
                                                     : 0U)));
    vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Reg_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__Des_Addr_M = vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out;
    vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Reg_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__Result_Src_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__ALU_Result_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__ALU_Result_Out;
    vlSelfRef.Pip_RV32I__DOT__PC_Plus4_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__PC_Plus4_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Ext_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Imm_Ext_Out;
    vlSelfRef.Pip_RV32I__DOT__Loaded_Data_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Loaded_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Added_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Added_Data_Out;
    vlSelfRef.Pip_RV32I__DOT__Result_W = ((4U & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out))
                                           ? ((2U & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out))
                                               ? vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__ALU_Result_Out
                                               : ((1U 
                                                   & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out))
                                                   ? vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Loaded_Data_Out
                                                   : vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__PC_Plus4_Out))
                                           : ((2U & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out))
                                                   ? vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Added_Data_Out
                                                   : vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Imm_Ext_Out)
                                               : vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__ALU_Result_Out));
    vlSelfRef.Pip_RV32I__DOT__Des_Addr_W = vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out;
    vlSelfRef.Pip_RV32I__DOT__ForwardB_E = (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Reg_WrEn_Out) 
                                             & (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr2_Out) 
                                                 == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out)) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out))))
                                             ? 1U : 
                                            (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Reg_WrEn_Out) 
                                              & (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr2_Out) 
                                                  == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out)) 
                                                 & (0U 
                                                    != (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out))))
                                              ? 2U : 0U));
    vlSelfRef.Pip_RV32I__DOT__ForwardA_E = (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Reg_WrEn_Out) 
                                             & (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr1_Out) 
                                                 == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out)) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out))))
                                             ? 1U : 
                                            (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Reg_WrEn_Out) 
                                              & (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr1_Out) 
                                                  == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out)) 
                                                 & (0U 
                                                    != (IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out))))
                                              ? 2U : 0U));
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_In = vlSelfRef.Pip_RV32I__DOT__PC_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_Plus4_In 
        = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_D;
    vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_In = vlSelfRef.Pip_RV32I__DOT__PC_F;
    vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__PC_Plus4_In 
        = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_F;
    vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__PC_Plus4_Out 
        = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_F;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__PC_Plus4_In 
        = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_M;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__Result_Src_M;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Imm_Ext_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_M;
    vlSelfRef.Pip_RV32I__DOT__load_unit__DOT__Load_Size_In 
        = vlSelfRef.Pip_RV32I__DOT__Load_Size_M;
    vlSelfRef.Pip_RV32I__DOT__load_unit__DOT__Load_Unsigned_In 
        = vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_M;
    vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__DM_WrEn_M;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_In 
        = vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_In 
        = vlSelfRef.Pip_RV32I__DOT__Load_Size_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__DM_WrEn_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__PC_Plus4_In 
        = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_E;
    vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__Func3_In 
        = vlSelfRef.Pip_RV32I__DOT__Func3_M;
    vlSelfRef.Pip_RV32I__DOT__alu__DOT__ALU_Control_In 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Control_E;
    vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__Added_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Added_M;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Added_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Added_M;
    if ((0U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_M))) {
        vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out 
            = ((2U & vlSelfRef.Pip_RV32I__DOT__Imm_Added_M)
                ? ((1U & vlSelfRef.Pip_RV32I__DOT__Imm_Added_M)
                    ? 8U : 4U) : ((1U & vlSelfRef.Pip_RV32I__DOT__Imm_Added_M)
                                   ? 2U : 1U));
        vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out 
            = ((vlSelfRef.Pip_RV32I__DOT__Read_Data2_M 
                << 0x18U) | ((0xff0000U & (vlSelfRef.Pip_RV32I__DOT__Read_Data2_M 
                                           << 0x10U)) 
                             | ((0xff00U & (vlSelfRef.Pip_RV32I__DOT__Read_Data2_M 
                                            << 8U)) 
                                | (0xffU & vlSelfRef.Pip_RV32I__DOT__Read_Data2_M))));
    } else if ((1U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_M))) {
        vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out 
            = ((2U & vlSelfRef.Pip_RV32I__DOT__Imm_Added_M)
                ? 0xcU : 3U);
        vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out 
            = ((vlSelfRef.Pip_RV32I__DOT__Read_Data2_M 
                << 0x10U) | (0xffffU & vlSelfRef.Pip_RV32I__DOT__Read_Data2_M));
    } else {
        vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out 
            = ((2U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_M))
                ? 0xfU : 0U);
        vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out 
            = vlSelfRef.Pip_RV32I__DOT__Read_Data2_M;
    }
    vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__PC_In 
        = vlSelfRef.Pip_RV32I__DOT__PC_E;
    vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__Iadder_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__Iadder_Src_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Result_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__Result_Src_E;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Result_Src_E_In 
        = vlSelfRef.Pip_RV32I__DOT__Result_Src_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Reg_WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_E;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Reg_WrEn_E_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_E;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Des_Addr_E_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_E;
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal 
        = vlSelfRef.Pip_RV32I__DOT__Branch_Cond_E;
    vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__Imm_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Imm_Ext_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_E;
    vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__Src_Data2_In 
        = vlSelfRef.Pip_RV32I__DOT__Read_Data2_M;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Func3_In 
        = vlSelfRef.Pip_RV32I__DOT__Func3_E;
    vlSelfRef.Pip_RV32I__DOT__imm_extend__DOT__Instr_In 
        = vlSelfRef.Pip_RV32I__DOT__Immediate_D;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Func7 = vlSelfRef.Pip_RV32I__DOT__Func7_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_D;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Func3 = vlSelfRef.Pip_RV32I__DOT__Func3_D;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Opcode 
        = vlSelfRef.Pip_RV32I__DOT__Opcode_D;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__DM_WrEn_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Iadder_Src_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Load_Size_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Load_Unsigned_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out = 0U;
    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out = 0U;
    if (((((((((0x33U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D)) 
               | (0x13U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) 
              | (3U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) 
             | (0x23U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) 
            | (0x63U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) 
           | (0x6fU == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) 
          | (0x67U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) 
         | (0x37U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D)))) {
        if ((0x33U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out = 0U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out 
                = ((IData)(vlSelfRef.Pip_RV32I__DOT__Func7_D)
                    ? ((4U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                        ? ((2U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                            ? 0U : ((1U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                     ? 0xdU : 0U)) : 
                       ((2U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                         ? 0U : ((1U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                  ? 0U : 8U))) : ((4U 
                                                   & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                     ? 7U
                                                     : 6U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                     ? 5U
                                                     : 4U))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                     ? 3U
                                                     : 2U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                                     ? 1U
                                                     : 0U))));
        } else if ((0x13U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out 
                = ((4U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                    ? ((2U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                        ? ((1U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                            ? 7U : 6U) : ((1U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                           ? ((IData)(vlSelfRef.Pip_RV32I__DOT__Func7_D)
                                               ? 0xdU
                                               : 5U)
                                           : 4U)) : 
                   ((2U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                     ? ((1U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                         ? 3U : 2U) : ((1U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))
                                        ? 1U : 0U)));
        } else if ((3U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out = 5U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out = 1U;
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out = 0U;
        } else {
            if ((0x23U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                if ((0x63U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out 
                        = ((0x6fU == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                            ? 4U : ((0x67U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                                     ? 4U : 2U));
                    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = 1U;
                }
            }
            if ((0x23U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out = 1U;
                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out = 0U;
            }
        }
        if ((0x33U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
            if ((0x13U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                if ((3U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                    if ((0x23U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                        vlSelfRef.Pip_RV32I__DOT__decoder__DOT__DM_WrEn_Out = 1U;
                    }
                    if ((0x23U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                        if ((0x63U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                            if ((0U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))) {
                                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 4U;
                            } else if ((1U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))) {
                                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 8U;
                            } else if ((4U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))) {
                                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 0x10U;
                            } else if ((5U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))) {
                                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 0x20U;
                            } else if ((6U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))) {
                                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 0x40U;
                            } else if ((7U == (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D))) {
                                vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 0x80U;
                            }
                        } else if ((0x6fU == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 1U;
                        } else if ((0x67U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = 2U;
                        }
                    }
                }
                if ((3U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Iadder_Src_Out = 1U;
                    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Load_Size_Out 
                        = (3U & (IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D));
                    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Load_Unsigned_Out 
                        = (1U & ((IData)(vlSelfRef.Pip_RV32I__DOT__Func3_D) 
                                 >> 2U));
                } else if ((0x23U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                    vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Iadder_Src_Out = 1U;
                } else if ((0x63U != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                    if ((0x6fU != (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                        if ((0x67U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
                            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Iadder_Src_Out = 1U;
                        }
                    }
                }
            }
            vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out 
                = ((0x13U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                    ? 1U : ((3U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                             ? 1U : ((0x23U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                                      ? 2U : ((0x63U 
                                               == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                                               ? 3U
                                               : ((0x6fU 
                                                   == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                                                   ? 5U
                                                   : 
                                                  ((0x67U 
                                                    == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))
                                                    ? 1U
                                                    : 4U))))));
        }
    } else if ((0x17U == (IData)(vlSelfRef.Pip_RV32I__DOT__Opcode_D))) {
        vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out = 3U;
        vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = 1U;
        vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out = 4U;
    }
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Src_Addr2_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr2_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Src_Addr2_D_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D;
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Src_Addr1_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr1_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Src_Addr1_D_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D;
    vlSelfRef.Pip_RV32I__DOT__Stall_F = ((5U == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Result_Src_Out)) 
                                         & ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Reg_WrEn_Out) 
                                            & ((0U 
                                                != (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_Out)) 
                                               & (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_Out) 
                                                   == (IData)(vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D)) 
                                                  | ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_Out) 
                                                     == (IData)(vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D))))));
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Src_Addr2_E_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr2_E;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Src_Addr1_E_In 
        = vlSelfRef.Pip_RV32I__DOT__Src_Addr1_E;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__ALU_Result_In 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Result_M;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Loaded_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Loaded_Data_M;
    vlSelfRef.Pip_RV32I__DOT__load_unit__DOT__Loaded_Data_Out 
        = vlSelfRef.Pip_RV32I__DOT__Loaded_Data_M;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Reg_WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_M;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Reg_WrEn_M_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_M;
    vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_M;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Des_Addr_M_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_M;
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_W;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Reg_WrEn_W_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__Result_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__Result_Src_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__ALU_Result_In 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Result_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__PC_Plus4_In 
        = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__Imm_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__Loaded_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Loaded_Data_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__Imm_Added_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Added_W;
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Des_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Result_W;
    vlSelfRef.Pip_RV32I__DOT__wb_unit__DOT__Result_Out 
        = vlSelfRef.Pip_RV32I__DOT__Result_W;
    vlSelfRef.Pip_RV32I__DOT__Read_Data2_E = (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out) 
                                               == (IData)(vlSelfRef.Pip_RV32I__DOT__Src_Addr2_D))
                                               ? vlSelfRef.Pip_RV32I__DOT__Result_W
                                               : vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Temp_Src_Data2);
    vlSelfRef.Pip_RV32I__DOT__Read_Data1_E = (((IData)(vlSelfRef.Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out) 
                                               == (IData)(vlSelfRef.Pip_RV32I__DOT__Src_Addr1_D))
                                               ? vlSelfRef.Pip_RV32I__DOT__Result_W
                                               : vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Temp_Src_Data1);
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Des_Addr_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_W;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Des_Addr_W_In 
        = vlSelfRef.Pip_RV32I__DOT__Des_Addr_W;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__ForwardB_E_Out 
        = vlSelfRef.Pip_RV32I__DOT__ForwardB_E;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__ForwardA_E_Out 
        = vlSelfRef.Pip_RV32I__DOT__ForwardA_E;
    vlSelfRef.DM_Mask_Out = vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_Mask_Out = vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_Mask_M = vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out;
    vlSelfRef.DM_Data_Out = vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_Data_Out = vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_WrData_M = vlSelfRef.Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out;
    vlSelfRef.Pip_RV32I__DOT__Result_Src_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Result_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__DM_WrEn_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__DM_WrEn_Out;
    vlSelfRef.Pip_RV32I__DOT__ALU_Src_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__Iadder_Src_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Iadder_Src_Out;
    vlSelfRef.Pip_RV32I__DOT__Load_Size_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Load_Size_Out;
    vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Load_Unsigned_Out;
    vlSelfRef.Pip_RV32I__DOT__Branch_Cond_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal;
    vlSelfRef.Pip_RV32I__DOT__ALU_Control_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Type_D = vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out;
    vlSelfRef.Pip_RV32I__DOT__Imm_Ext_D = ((4U & (IData)(vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out))
                                            ? ((2U 
                                                & (IData)(vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                                 >> 0x1fU))) 
                                                     << 0x14U) 
                                                    | (((0xff000U 
                                                         & vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out) 
                                                        | (0x800U 
                                                           & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                              >> 9U))) 
                                                       | (0x7feU 
                                                          & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                             >> 0x14U))))
                                                    : 
                                                   (0xfffff000U 
                                                    & vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out)))
                                            : ((2U 
                                                & (IData)(vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | ((0x800U 
                                                        & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                                >> 7U)))))
                                                    : 
                                                   (((- (IData)(
                                                                (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | ((0xfe0U 
                                                        & (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                           >> 0x14U)) 
                                                       | (IData)(vlSelfRef.Pip_RV32I__DOT__Des_Addr_D))))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | (vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out 
                                                       >> 0x14U))
                                                    : 0U)));
    vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Stall_In 
        = vlSelfRef.Pip_RV32I__DOT__Stall_F;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Stall_F_Out 
        = vlSelfRef.Pip_RV32I__DOT__Stall_F;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Stall_D_Out 
        = vlSelfRef.Pip_RV32I__DOT__Stall_F;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__load_use_hazard 
        = vlSelfRef.Pip_RV32I__DOT__Stall_F;
    vlSelfRef.Pip_RV32I__DOT__Stall_D = vlSelfRef.Pip_RV32I__DOT__Stall_F;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Read_Data2_In 
        = vlSelfRef.Pip_RV32I__DOT__Read_Data2_E;
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Src_Data2_Out 
        = vlSelfRef.Pip_RV32I__DOT__Read_Data2_E;
    vlSelfRef.Pip_RV32I__DOT__ForwardB_Data = ((1U 
                                                == (IData)(vlSelfRef.Pip_RV32I__DOT__ForwardB_E))
                                                ? vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelfRef.Pip_RV32I__DOT__ForwardB_E))
                                                    ? vlSelfRef.Pip_RV32I__DOT__Result_W
                                                    : vlSelfRef.Pip_RV32I__DOT__Read_Data2_E));
    vlSelfRef.Pip_RV32I__DOT__reg_file__DOT__Src_Data1_Out 
        = vlSelfRef.Pip_RV32I__DOT__Read_Data1_E;
    vlSelfRef.Pip_RV32I__DOT__ForwardA_Data = ((1U 
                                                == (IData)(vlSelfRef.Pip_RV32I__DOT__ForwardA_E))
                                                ? vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelfRef.Pip_RV32I__DOT__ForwardA_E))
                                                    ? vlSelfRef.Pip_RV32I__DOT__Result_W
                                                    : vlSelfRef.Pip_RV32I__DOT__Read_Data1_E));
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Result_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__Result_Src_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Reg_WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__Reg_WrEn_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__DM_WrEn_In 
        = vlSelfRef.Pip_RV32I__DOT__DM_WrEn_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Src_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Iadder_Src_In 
        = vlSelfRef.Pip_RV32I__DOT__Iadder_Src_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Load_Size_In 
        = vlSelfRef.Pip_RV32I__DOT__Load_Size_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Load_Unsigned_In 
        = vlSelfRef.Pip_RV32I__DOT__Load_Unsigned_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_In 
        = vlSelfRef.Pip_RV32I__DOT__Branch_Cond_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_In 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Control_D;
    vlSelfRef.Pip_RV32I__DOT__imm_extend__DOT__Imm_Type_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Type_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Imm_Ext_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_D;
    vlSelfRef.Pip_RV32I__DOT__imm_extend__DOT__Imm_Out 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Ext_D;
    vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Stall_In 
        = vlSelfRef.Pip_RV32I__DOT__Stall_D;
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__Src_Data2_In 
        = vlSelfRef.Pip_RV32I__DOT__ForwardB_Data;
    vlSelfRef.Pip_RV32I__DOT__SrcB = ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Src_Out)
                                       ? vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Imm_Ext_Out
                                       : vlSelfRef.Pip_RV32I__DOT__ForwardB_Data);
    vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__Src_Data1_In 
        = vlSelfRef.Pip_RV32I__DOT__ForwardA_Data;
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__Src_Data1_In 
        = vlSelfRef.Pip_RV32I__DOT__ForwardA_Data;
    vlSelfRef.Pip_RV32I__DOT__alu__DOT__signed_src1 
        = vlSelfRef.Pip_RV32I__DOT__ForwardA_Data;
    vlSelfRef.Pip_RV32I__DOT__SrcA = vlSelfRef.Pip_RV32I__DOT__ForwardA_Data;
    vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__temp_adder_src 
        = ((IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Iadder_Src_Out)
            ? vlSelfRef.Pip_RV32I__DOT__ForwardA_Data
            : vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__PC_Out);
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__equal 
        = (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
           == vlSelfRef.Pip_RV32I__DOT__ForwardB_Data);
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__less_than 
        = VL_LTS_III(32, vlSelfRef.Pip_RV32I__DOT__ForwardA_Data, vlSelfRef.Pip_RV32I__DOT__ForwardB_Data);
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__less_than_unsigned 
        = (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
           < vlSelfRef.Pip_RV32I__DOT__ForwardB_Data);
    vlSelfRef.Pip_RV32I__DOT__alu__DOT__Src2_In = vlSelfRef.Pip_RV32I__DOT__SrcB;
    vlSelfRef.Pip_RV32I__DOT__alu__DOT__signed_src2 
        = vlSelfRef.Pip_RV32I__DOT__SrcB;
    vlSelfRef.Pip_RV32I__DOT__ALU_Result_E = ((8U & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                               ? ((4U 
                                                   & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlSelfRef.Pip_RV32I__DOT__ForwardA_Data, 
                                                                   (0x1fU 
                                                                    & vlSelfRef.Pip_RV32I__DOT__SrcB))
                                                     : 0U))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     - vlSelfRef.Pip_RV32I__DOT__SrcB))))
                                               : ((4U 
                                                   & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                     ? 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     & vlSelfRef.Pip_RV32I__DOT__SrcB)
                                                     : 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     | vlSelfRef.Pip_RV32I__DOT__SrcB))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                     ? 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     >> 
                                                     (0x1fU 
                                                      & vlSelfRef.Pip_RV32I__DOT__SrcB))
                                                     : 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     ^ vlSelfRef.Pip_RV32I__DOT__SrcB)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                     ? 
                                                    ((vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                      < vlSelfRef.Pip_RV32I__DOT__SrcB)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    (VL_LTS_III(32, vlSelfRef.Pip_RV32I__DOT__ForwardA_Data, vlSelfRef.Pip_RV32I__DOT__SrcB)
                                                      ? 1U
                                                      : 0U))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out))
                                                     ? 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     << 
                                                     (0x1fU 
                                                      & vlSelfRef.Pip_RV32I__DOT__SrcB))
                                                     : 
                                                    (vlSelfRef.Pip_RV32I__DOT__ForwardA_Data 
                                                     + vlSelfRef.Pip_RV32I__DOT__SrcB)))));
    vlSelfRef.Pip_RV32I__DOT__alu__DOT__Src1_In = vlSelfRef.Pip_RV32I__DOT__SrcA;
    vlSelfRef.Pip_RV32I__DOT__Imm_Added_E = (vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__temp_adder_src 
                                             + vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Imm_Ext_Out);
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__not_equal 
        = (1U & (~ (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__equal)));
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__greater_equal 
        = (1U & (~ (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__less_than)));
    vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__greater_equal_unsigned 
        = (1U & (~ (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__less_than_unsigned)));
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_In 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Result_E;
    vlSelfRef.Pip_RV32I__DOT__alu__DOT__ALU_Result_Out 
        = vlSelfRef.Pip_RV32I__DOT__ALU_Result_E;
    vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Target_PC_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Added_E;
    vlSelfRef.Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_In 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Added_E;
    vlSelfRef.Pip_RV32I__DOT__Imm_Adder__DOT__Added_Data_Out 
        = vlSelfRef.Pip_RV32I__DOT__Imm_Added_E;
    vlSelfRef.Pip_RV32I__DOT__Branch_Taken_E = ((((1U 
                                                   == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                  | (2U 
                                                     == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))) 
                                                 | (((4U 
                                                      == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                     | (8U 
                                                        == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))) 
                                                    | ((0x10U 
                                                        == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                       | ((0x20U 
                                                           == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                          | ((0x40U 
                                                              == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                             | (0x80U 
                                                                == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))))))) 
                                                & ((1U 
                                                    == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                   | ((2U 
                                                       == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out)) 
                                                      | ((4U 
                                                          == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))
                                                          ? (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__equal)
                                                          : 
                                                         ((8U 
                                                           == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))
                                                           ? (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__not_equal)
                                                           : 
                                                          ((0x10U 
                                                            == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))
                                                            ? (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__less_than)
                                                            : 
                                                           ((0x20U 
                                                             == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))
                                                             ? (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__greater_equal)
                                                             : 
                                                            ((0x40U 
                                                              == (IData)(vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out))
                                                              ? (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__less_than_unsigned)
                                                              : (IData)(vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__greater_equal_unsigned)))))))));
    if (vlSelfRef.Pip_RV32I__DOT__Branch_Taken_E) {
        vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Branch_Taken_In = 1U;
        vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Branch_Taken_E_In = 1U;
        vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__Branch_Taken_Out = 1U;
        vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Flush_D_Out = 1U;
        vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__control_hazard = 1U;
        vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Temp_PC_Out 
            = vlSelfRef.Pip_RV32I__DOT__Imm_Added_E;
        vlSelfRef.Pip_RV32I__DOT__Flush_D = 1U;
    } else {
        vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Branch_Taken_In = 0U;
        vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Branch_Taken_E_In = 0U;
        vlSelfRef.Pip_RV32I__DOT__branch_unit__DOT__Branch_Taken_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Flush_D_Out = 0U;
        vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__control_hazard = 0U;
        vlSelfRef.Pip_RV32I__DOT__pc_unit__DOT__Temp_PC_Out 
            = vlSelfRef.Pip_RV32I__DOT__PC_Plus4_F;
        vlSelfRef.Pip_RV32I__DOT__Flush_D = 0U;
    }
    vlSelfRef.Pip_RV32I__DOT__Flush_E = ((IData)(vlSelfRef.Pip_RV32I__DOT__Branch_Taken_E) 
                                         | (IData)(vlSelfRef.Pip_RV32I__DOT__Stall_F));
    vlSelfRef.Pip_RV32I__DOT__reg_f_d__DOT__Flush_In 
        = vlSelfRef.Pip_RV32I__DOT__Flush_D;
    vlSelfRef.Pip_RV32I__DOT__reg_d_e__DOT__Flush_In 
        = vlSelfRef.Pip_RV32I__DOT__Flush_E;
    vlSelfRef.Pip_RV32I__DOT__hazard_unit__DOT__Flush_E_Out 
        = vlSelfRef.Pip_RV32I__DOT__Flush_E;
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/foss/designs/CPU/RV32I_Piplined/tests/../src/Pip_RV32I.v", 19, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/foss/designs/CPU/RV32I_Piplined/tests/../src/Pip_RV32I.v", 19, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/foss/designs/CPU/RV32I_Piplined/tests/../src/Pip_RV32I.v", 19, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.Clk_In & 0xfeU)))) {
        Verilated::overWidthError("Clk_In");}
    if (VL_UNLIKELY(((vlSelfRef.Rst_In & 0xfeU)))) {
        Verilated::overWidthError("Rst_In");}
}
#endif  // VL_DEBUG
