// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__Clk_In__0 = vlSelfRef.Clk_In;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/foss/designs/CPU/RV32I_Piplined/tests/../src/Pip_RV32I.v", 19, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge Clk_In)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge Clk_In)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->Clk_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8406025475601390425ull);
    vlSelf->Rst_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6952162910819723513ull);
    vlSelf->Instruction_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17133256555698136915ull);
    vlSelf->Instr_Addr_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8834379243939929759ull);
    vlSelf->DM_Data_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7348860953044037298ull);
    vlSelf->DM_Addr_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1610178306935926161ull);
    vlSelf->DM_Data_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6969173549205632485ull);
    vlSelf->DM_Mask_Out = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7933977736814365416ull);
    vlSelf->DM_WrEn_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7501094533404083931ull);
    vlSelf->Pip_RV32I__DOT__Clk_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7657640473031761609ull);
    vlSelf->Pip_RV32I__DOT__Rst_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3905187128678228173ull);
    vlSelf->Pip_RV32I__DOT__Instruction_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 810010407982411198ull);
    vlSelf->Pip_RV32I__DOT__Instr_Addr_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7123777682296863629ull);
    vlSelf->Pip_RV32I__DOT__DM_Data_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8323081316983490912ull);
    vlSelf->Pip_RV32I__DOT__DM_Addr_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11407748126527102930ull);
    vlSelf->Pip_RV32I__DOT__DM_Data_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 525013795066634966ull);
    vlSelf->Pip_RV32I__DOT__DM_Mask_Out = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2309897679581402247ull);
    vlSelf->Pip_RV32I__DOT__DM_WrEn_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15393168926496909122ull);
    vlSelf->Pip_RV32I__DOT__PC_F = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10955948195874348008ull);
    vlSelf->Pip_RV32I__DOT__PC_Plus4_F = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6063695833869205658ull);
    vlSelf->Pip_RV32I__DOT__Instruction_F = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14895809779708318089ull);
    vlSelf->Pip_RV32I__DOT__PC_D = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6649791953555531673ull);
    vlSelf->Pip_RV32I__DOT__PC_Plus4_D = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7071403635286101570ull);
    vlSelf->Pip_RV32I__DOT__Instruction_D = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13652821139734289133ull);
    vlSelf->Pip_RV32I__DOT__Opcode_D = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 17457555290315501804ull);
    vlSelf->Pip_RV32I__DOT__Func3_D = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 347124788237295432ull);
    vlSelf->Pip_RV32I__DOT__Func7_D = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9197524683328198120ull);
    vlSelf->Pip_RV32I__DOT__Src_Addr1_D = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2911730666924683443ull);
    vlSelf->Pip_RV32I__DOT__Src_Addr2_D = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13265614869669771616ull);
    vlSelf->Pip_RV32I__DOT__Des_Addr_D = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7430678453365283371ull);
    vlSelf->Pip_RV32I__DOT__Immediate_D = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6180962565281413835ull);
    vlSelf->Pip_RV32I__DOT__Imm_Ext_D = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1612316623029852319ull);
    vlSelf->Pip_RV32I__DOT__Reg_WrEn_D = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9572119630360145064ull);
    vlSelf->Pip_RV32I__DOT__Result_Src_D = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4690672873962546376ull);
    vlSelf->Pip_RV32I__DOT__Imm_Type_D = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15603797445767256613ull);
    vlSelf->Pip_RV32I__DOT__Iadder_Src_D = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6925671618974946033ull);
    vlSelf->Pip_RV32I__DOT__ALU_Src_D = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 242480959870947297ull);
    vlSelf->Pip_RV32I__DOT__ALU_Control_D = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4259385330549648188ull);
    vlSelf->Pip_RV32I__DOT__DM_WrEn_D = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7133763744314680734ull);
    vlSelf->Pip_RV32I__DOT__Branch_Cond_D = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8594643165904668908ull);
    vlSelf->Pip_RV32I__DOT__Load_Unsigned_D = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5046527501018007861ull);
    vlSelf->Pip_RV32I__DOT__Load_Size_D = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2197269268840486664ull);
    vlSelf->Pip_RV32I__DOT__PC_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1078885864615938554ull);
    vlSelf->Pip_RV32I__DOT__PC_Plus4_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6160156415559896474ull);
    vlSelf->Pip_RV32I__DOT__Func3_E = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16977312785539640185ull);
    vlSelf->Pip_RV32I__DOT__Reg_WrEn_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11344202744362343619ull);
    vlSelf->Pip_RV32I__DOT__Result_Src_E = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18359317985352571018ull);
    vlSelf->Pip_RV32I__DOT__Iadder_Src_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1070070163505757482ull);
    vlSelf->Pip_RV32I__DOT__ALU_Src_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7834603551002563808ull);
    vlSelf->Pip_RV32I__DOT__ALU_Control_E = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7214216943940218234ull);
    vlSelf->Pip_RV32I__DOT__DM_WrEn_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8090664054885284879ull);
    vlSelf->Pip_RV32I__DOT__Branch_Cond_E = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15078127663783558390ull);
    vlSelf->Pip_RV32I__DOT__Load_Unsigned_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3422996161752328929ull);
    vlSelf->Pip_RV32I__DOT__Load_Size_E = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18158474452580094527ull);
    vlSelf->Pip_RV32I__DOT__Read_Data1_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10460645737879817366ull);
    vlSelf->Pip_RV32I__DOT__Read_Data2_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9164831909654087348ull);
    vlSelf->Pip_RV32I__DOT__Imm_Ext_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5333157535452846162ull);
    vlSelf->Pip_RV32I__DOT__ALU_Result_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3307937355322289617ull);
    vlSelf->Pip_RV32I__DOT__Imm_Added_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5967841353137672628ull);
    vlSelf->Pip_RV32I__DOT__Des_Addr_E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15583527154967202938ull);
    vlSelf->Pip_RV32I__DOT__Branch_Taken_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15075882940358621473ull);
    vlSelf->Pip_RV32I__DOT__PC_Plus4_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2389961306883159398ull);
    vlSelf->Pip_RV32I__DOT__ALU_Result_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15384969846772459168ull);
    vlSelf->Pip_RV32I__DOT__Read_Data2_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16893490085034477092ull);
    vlSelf->Pip_RV32I__DOT__Reg_WrEn_M = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5514058962419774530ull);
    vlSelf->Pip_RV32I__DOT__Func3_M = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16719528989801579976ull);
    vlSelf->Pip_RV32I__DOT__Result_Src_M = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1024257140546678456ull);
    vlSelf->Pip_RV32I__DOT__Load_Size_M = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15168669484047383752ull);
    vlSelf->Pip_RV32I__DOT__Load_Unsigned_M = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12933837310953553494ull);
    vlSelf->Pip_RV32I__DOT__Loaded_Data_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1659255828893452722ull);
    vlSelf->Pip_RV32I__DOT__DM_WrData_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9709557641150056252ull);
    vlSelf->Pip_RV32I__DOT__DM_Addr_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1364739334427926034ull);
    vlSelf->Pip_RV32I__DOT__DM_Wr_Req_M = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15157670464562017047ull);
    vlSelf->Pip_RV32I__DOT__DM_Mask_M = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6482611264398647592ull);
    vlSelf->Pip_RV32I__DOT__DM_WrEn_M = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10086098360460539760ull);
    vlSelf->Pip_RV32I__DOT__Imm_Ext_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2147134168239333154ull);
    vlSelf->Pip_RV32I__DOT__Imm_Added_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15115224015125303314ull);
    vlSelf->Pip_RV32I__DOT__Des_Addr_M = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3803660964762628469ull);
    vlSelf->Pip_RV32I__DOT__Data_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2285679697536623354ull);
    vlSelf->Pip_RV32I__DOT__PC_Plus4_W = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12924701827074105174ull);
    vlSelf->Pip_RV32I__DOT__ALU_Result_W = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6418469312872301967ull);
    vlSelf->Pip_RV32I__DOT__Loaded_Data_W = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16382424687403323751ull);
    vlSelf->Pip_RV32I__DOT__Imm_Ext_W = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8574239041689958693ull);
    vlSelf->Pip_RV32I__DOT__Imm_Added_W = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1005912722067160077ull);
    vlSelf->Pip_RV32I__DOT__Result_W = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10065019112321077901ull);
    vlSelf->Pip_RV32I__DOT__Reg_WrEn_W = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15949727977209420624ull);
    vlSelf->Pip_RV32I__DOT__Result_Src_W = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2991762034106345666ull);
    vlSelf->Pip_RV32I__DOT__Des_Addr_W = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3651124452884582620ull);
    vlSelf->Pip_RV32I__DOT__Stall_F = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5581184506840334209ull);
    vlSelf->Pip_RV32I__DOT__Stall_D = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8973254498598549650ull);
    vlSelf->Pip_RV32I__DOT__Flush_D = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11477650220248212053ull);
    vlSelf->Pip_RV32I__DOT__Flush_E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1414325812738483585ull);
    vlSelf->Pip_RV32I__DOT__ForwardA_E = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14463931465868249730ull);
    vlSelf->Pip_RV32I__DOT__ForwardB_E = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13369137329755275882ull);
    vlSelf->Pip_RV32I__DOT__Src_Addr1_E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16569369799350908914ull);
    vlSelf->Pip_RV32I__DOT__Src_Addr2_E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9427744415047594214ull);
    vlSelf->Pip_RV32I__DOT__ForwardA_Data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8210062583619858273ull);
    vlSelf->Pip_RV32I__DOT__ForwardB_Data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9899119212565177786ull);
    vlSelf->Pip_RV32I__DOT__SrcA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12422843952931801439ull);
    vlSelf->Pip_RV32I__DOT__SrcB = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12249306399629768128ull);
    vlSelf->Pip_RV32I__DOT__pc_unit__DOT__Clk_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 640272370001497067ull);
    vlSelf->Pip_RV32I__DOT__pc_unit__DOT__Rst_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6578574818246325287ull);
    vlSelf->Pip_RV32I__DOT__pc_unit__DOT__Stall_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12107866325256770446ull);
    vlSelf->Pip_RV32I__DOT__pc_unit__DOT__Branch_Taken_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7956005754211665009ull);
    vlSelf->Pip_RV32I__DOT__pc_unit__DOT__Target_PC_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8959883960051658515ull);
    vlSelf->Pip_RV32I__DOT__pc_unit__DOT__PC_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2888541690652486346ull);
    vlSelf->Pip_RV32I__DOT__pc_unit__DOT__PC_Plus4_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 311330553313827839ull);
    vlSelf->Pip_RV32I__DOT__pc_unit__DOT__Temp_PC_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1300147514321909717ull);
    vlSelf->Pip_RV32I__DOT__reg_f_d__DOT__Clk_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16589121189453214964ull);
    vlSelf->Pip_RV32I__DOT__reg_f_d__DOT__Rst_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14323008629173445980ull);
    vlSelf->Pip_RV32I__DOT__reg_f_d__DOT__Stall_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14071985414824331993ull);
    vlSelf->Pip_RV32I__DOT__reg_f_d__DOT__Flush_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3781214064418695844ull);
    vlSelf->Pip_RV32I__DOT__reg_f_d__DOT__Instr_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7158925523164312026ull);
    vlSelf->Pip_RV32I__DOT__reg_f_d__DOT__PC_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11581095571785785458ull);
    vlSelf->Pip_RV32I__DOT__reg_f_d__DOT__PC_Plus4_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 315983923107211555ull);
    vlSelf->Pip_RV32I__DOT__reg_f_d__DOT__Instr_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10204899161396326864ull);
    vlSelf->Pip_RV32I__DOT__reg_f_d__DOT__PC_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10648961766758598572ull);
    vlSelf->Pip_RV32I__DOT__reg_f_d__DOT__PC_Plus4_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7120822374874834267ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__Opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 11349799172321156114ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__Func3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17927399353775991614ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__Func7 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 821950042343232371ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__Reg_WrEn_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8331492233648413568ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__Imm_Type_Out = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11227653195012066079ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__Iadder_Src_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209233595427694903ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__ALU_Src_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9573280342164438169ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__ALU_Control_Out = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9593491430622651492ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__DM_WrEn_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2095243161028053709ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16887136501894274930ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__Load_Unsigned_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10629078466860208000ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__Load_Size_Out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8828251106702284702ull);
    vlSelf->Pip_RV32I__DOT__decoder__DOT__Result_Src_Out = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13849617301671092197ull);
    vlSelf->Pip_RV32I__DOT__reg_file__DOT__Clk_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6283112708485892883ull);
    vlSelf->Pip_RV32I__DOT__reg_file__DOT__Rst_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 371671776141445066ull);
    vlSelf->Pip_RV32I__DOT__reg_file__DOT__WrEn_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10265263097269828186ull);
    vlSelf->Pip_RV32I__DOT__reg_file__DOT__Src_Addr1_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5535852151148450474ull);
    vlSelf->Pip_RV32I__DOT__reg_file__DOT__Src_Addr2_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14967002653160667678ull);
    vlSelf->Pip_RV32I__DOT__reg_file__DOT__Des_Addr_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8525078570541955526ull);
    vlSelf->Pip_RV32I__DOT__reg_file__DOT__Des_Data_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1933908661127697729ull);
    vlSelf->Pip_RV32I__DOT__reg_file__DOT__Src_Data1_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5695099270876400183ull);
    vlSelf->Pip_RV32I__DOT__reg_file__DOT__Src_Data2_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12313662888743375334ull);
    vlSelf->Pip_RV32I__DOT__reg_file__DOT__Temp_Src_Data1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 809624678520803982ull);
    vlSelf->Pip_RV32I__DOT__reg_file__DOT__Temp_Src_Data2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6585737466372087955ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->Pip_RV32I__DOT__reg_file__DOT__register[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 450413560629699834ull);
    }
    vlSelf->Pip_RV32I__DOT__reg_file__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16050510246618212281ull);
    vlSelf->Pip_RV32I__DOT__imm_extend__DOT__Instr_In = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 2626748241161853268ull);
    vlSelf->Pip_RV32I__DOT__imm_extend__DOT__Imm_Type_In = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10696417977547631375ull);
    vlSelf->Pip_RV32I__DOT__imm_extend__DOT__Imm_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8619349549906560105ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Clk_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6493721587805963445ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Rst_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10018104430761282315ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Flush_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7258357944249550803ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Reg_WrEn_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9427719195815099632ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Result_Src_In = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12448189889166157343ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__DM_WrEn_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9935422063299260160ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Iadder_Src_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14746707565233268510ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Load_Size_In = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7501815460916822068ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Load_Unsigned_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15464148047584242019ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_In = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12699350276346079784ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__ALU_Src_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16962323254343533317ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__PC_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7351840605707022003ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Func3_In = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14304039043316201654ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_In = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12124012330345080320ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Imm_Ext_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9877337280377839108ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__PC_Plus4_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 150018090919303412ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 110560941855370734ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr1_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6023277920208833874ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr2_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1485386877339631922ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr1_Out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14513554179188310615ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Src_Addr2_Out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14648268141919254772ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Des_Addr_Out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12592091531271208038ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Reg_WrEn_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13342846506342711019ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Result_Src_Out = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5753029430783394759ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__DM_WrEn_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9219089476365446650ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Iadder_Src_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16977440191055822376ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Load_Size_Out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17295096807189769576ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Load_Unsigned_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8304335746440250374ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__ALU_Control_Out = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1859730206135746223ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__ALU_Src_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1846245947834225597ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__PC_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11339486683941155674ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Func3_Out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12264690702042814825ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Branch_Cond_Out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12106211203480201538ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__Imm_Ext_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 107845444928028982ull);
    vlSelf->Pip_RV32I__DOT__reg_d_e__DOT__PC_Plus4_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12114953102867663513ull);
    vlSelf->Pip_RV32I__DOT__alu__DOT__Src1_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13664117836622602201ull);
    vlSelf->Pip_RV32I__DOT__alu__DOT__Src2_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14226090299530087763ull);
    vlSelf->Pip_RV32I__DOT__alu__DOT__ALU_Control_In = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15989643104272407327ull);
    vlSelf->Pip_RV32I__DOT__alu__DOT__ALU_Result_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8404285662353435090ull);
    vlSelf->Pip_RV32I__DOT__alu__DOT__signed_src1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9166031824814104090ull);
    vlSelf->Pip_RV32I__DOT__alu__DOT__signed_src2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10457685229671639615ull);
    vlSelf->Pip_RV32I__DOT__Imm_Adder__DOT__Iadder_Src_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14246286559682731578ull);
    vlSelf->Pip_RV32I__DOT__Imm_Adder__DOT__PC_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1666055267354103614ull);
    vlSelf->Pip_RV32I__DOT__Imm_Adder__DOT__Src_Data1_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17860480795788019180ull);
    vlSelf->Pip_RV32I__DOT__Imm_Adder__DOT__Imm_Data_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14249165916696411756ull);
    vlSelf->Pip_RV32I__DOT__Imm_Adder__DOT__Added_Data_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14796603997157504336ull);
    vlSelf->Pip_RV32I__DOT__Imm_Adder__DOT__temp_adder_src = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2597326206315890790ull);
    vlSelf->Pip_RV32I__DOT__branch_unit__DOT__Src_Data1_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5804437789588182572ull);
    vlSelf->Pip_RV32I__DOT__branch_unit__DOT__Src_Data2_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4308223641019876927ull);
    vlSelf->Pip_RV32I__DOT__branch_unit__DOT__bgeu_bltu_bge_blt_bne_beq_jalr_jal = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9818403076015223620ull);
    vlSelf->Pip_RV32I__DOT__branch_unit__DOT__Branch_Taken_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13471286676493551824ull);
    vlSelf->Pip_RV32I__DOT__branch_unit__DOT__equal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6412319379783290353ull);
    vlSelf->Pip_RV32I__DOT__branch_unit__DOT__not_equal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2752931349732126047ull);
    vlSelf->Pip_RV32I__DOT__branch_unit__DOT__less_than = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15380628970230751528ull);
    vlSelf->Pip_RV32I__DOT__branch_unit__DOT__greater_equal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16878692508593956372ull);
    vlSelf->Pip_RV32I__DOT__branch_unit__DOT__less_than_unsigned = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13461080973773184192ull);
    vlSelf->Pip_RV32I__DOT__branch_unit__DOT__greater_equal_unsigned = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1363958674509629498ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Clk_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9884257281431489609ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Rst_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8709078512593432109ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Reg_WrEn_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17534591975912912674ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Result_Src_In = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6812592324032319102ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_In = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8681004428869756929ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3588446669797719499ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2533571396383439858ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Func3_In = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 697791411328956688ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18381326692442497286ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Read_Data2_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14793720345869357059ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17520783580037368879ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__PC_Plus4_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10028867364950136522ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Imm_Ext_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6742116544972496521ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17759287470570735993ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Des_Addr_Out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7200663876324709982ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Imm_Ext_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8204611519828015383ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Reg_WrEn_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13524249022868292110ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Result_Src_Out = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11064551237259033912ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Load_Size_Out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10270227207979975069ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Load_Unsigned_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9814489185556701786ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__DM_WrEn_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4560688798793771796ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Func3_Out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5857587461692003916ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__ALU_Result_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17701102544531610929ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Read_Data2_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9399146067291884513ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__Added_Data_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1799056662764893732ull);
    vlSelf->Pip_RV32I__DOT__reg_e_m__DOT__PC_Plus4_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8342326101271698631ull);
    vlSelf->Pip_RV32I__DOT__store_unit__DOT__DM_WrEn_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3822744342997369640ull);
    vlSelf->Pip_RV32I__DOT__store_unit__DOT__Func3_In = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3626561906134739863ull);
    vlSelf->Pip_RV32I__DOT__store_unit__DOT__Added_Data_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9652552614685069584ull);
    vlSelf->Pip_RV32I__DOT__store_unit__DOT__Src_Data2_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18099775673331656994ull);
    vlSelf->Pip_RV32I__DOT__store_unit__DOT__DM_WrMask_Out = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6141173819256224453ull);
    vlSelf->Pip_RV32I__DOT__store_unit__DOT__DM_WrData_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3802970865926152220ull);
    vlSelf->Pip_RV32I__DOT__store_unit__DOT__DM_Addr_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14326227237313580949ull);
    vlSelf->Pip_RV32I__DOT__store_unit__DOT__DM_WrEn_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16598557627109193009ull);
    vlSelf->Pip_RV32I__DOT__load_unit__DOT__Read_Data_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5296112648565552541ull);
    vlSelf->Pip_RV32I__DOT__load_unit__DOT__iadder_out_1to0_in = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18392137752300343619ull);
    vlSelf->Pip_RV32I__DOT__load_unit__DOT__Load_Size_In = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2952928614568845142ull);
    vlSelf->Pip_RV32I__DOT__load_unit__DOT__Load_Unsigned_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11986903981161323432ull);
    vlSelf->Pip_RV32I__DOT__load_unit__DOT__Loaded_Data_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14558189071496244684ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Clk_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12757018786947117899ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Rst_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6071885389748441093ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Reg_WrEn_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14399032842542386856ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_In = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9456224507159157883ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__ALU_Result_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9021677612186880206ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Loaded_Data_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 797781928181697227ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Added_Data_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6492597293654303288ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__PC_Plus4_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1672420555580589028ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Imm_Ext_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15320365839188773099ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17791911788205706230ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Des_Addr_Out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15023878432020022667ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Imm_Ext_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17840650366934135881ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Reg_WrEn_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4404368696158860378ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Result_Src_Out = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5152501288462536565ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__ALU_Result_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6788502790390905816ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Loaded_Data_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6660254353726051864ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__Added_Data_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6762775135097438553ull);
    vlSelf->Pip_RV32I__DOT__reg_m_w__DOT__PC_Plus4_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1811067049146143873ull);
    vlSelf->Pip_RV32I__DOT__wb_unit__DOT__Result_Src_In = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11301147598012394487ull);
    vlSelf->Pip_RV32I__DOT__wb_unit__DOT__Imm_Data_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14704066717288650587ull);
    vlSelf->Pip_RV32I__DOT__wb_unit__DOT__ALU_Result_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6451339591214807395ull);
    vlSelf->Pip_RV32I__DOT__wb_unit__DOT__Loaded_Data_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1853361892186778660ull);
    vlSelf->Pip_RV32I__DOT__wb_unit__DOT__Imm_Added_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14767766024791661332ull);
    vlSelf->Pip_RV32I__DOT__wb_unit__DOT__PC_Plus4_In = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11527818241550411704ull);
    vlSelf->Pip_RV32I__DOT__wb_unit__DOT__Result_Out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2765288322636655893ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Src_Addr1_D_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9962993408332420335ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Src_Addr2_D_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17930084751296166141ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Des_Addr_E_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15937815972134858861ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Reg_WrEn_E_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15647624969840651196ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Result_Src_E_In = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3875062540537036663ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Src_Addr1_E_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15104045744950939527ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Src_Addr2_E_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3488262241044950290ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Des_Addr_M_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17748655939509249041ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Reg_WrEn_M_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11623966317621626620ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Des_Addr_W_In = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12643852864016342900ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Reg_WrEn_W_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16369806101080289145ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Branch_Taken_E_In = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7022322950128981892ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Stall_F_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11543180197822958357ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Stall_D_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10710494983949809445ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Flush_D_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11148165789598807516ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__Flush_E_Out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7492854464301853458ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__ForwardA_E_Out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11845966187734868721ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__ForwardB_E_Out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9057759094631810302ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__load_use_hazard = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2465883777498696192ull);
    vlSelf->Pip_RV32I__DOT__hazard_unit__DOT__control_hazard = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12529061277990740234ull);
    vlSelf->__Vtrigprevexpr___TOP__Clk_In__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14517281677145212202ull);
}
