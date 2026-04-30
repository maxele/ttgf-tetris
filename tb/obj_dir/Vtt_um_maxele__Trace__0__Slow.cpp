// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtt_um_maxele__Syms.h"


VL_ATTR_COLD void Vtt_um_maxele___024root__trace_init_sub__TOP__0(Vtt_um_maxele___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_maxele___024root__trace_init_sub__TOP__0\n"); );
    Vtt_um_maxele__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+66,0,"ui_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+67,0,"uo_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"uio_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+69,0,"uio_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+70,0,"uio_oe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+71,0,"ena",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tt_um_maxele", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+66,0,"ui_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+67,0,"uo_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"uio_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+69,0,"uio_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+70,0,"uio_oe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+71,0,"ena",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+0,0,"x_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+1,0,"x_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+2,0,"y_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+3,0,"y_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+4,0,"sync_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"r_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+6,0,"g_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+7,0,"b_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("matrix_p", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 20; ++i) {
        tracep->declBus(c+8+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 9,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("matrix_n", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 20; ++i) {
        tracep->declBus(c+28+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 9,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("active_p", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+48+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("active_n", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+52+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+56,0,"ax_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+74,0,"ax_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+57,0,"ay_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+58,0,"ay_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+59,0,"input_buffer_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+75,0,"input_buffer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+60,0,"lx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+61,0,"ly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+62,0,"frames_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+63,0,"frames_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+64,0,"state_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+65,0,"state_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtt_um_maxele___024root__trace_init_top(Vtt_um_maxele___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_maxele___024root__trace_init_top\n"); );
    Vtt_um_maxele__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtt_um_maxele___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtt_um_maxele___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtt_um_maxele___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtt_um_maxele___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtt_um_maxele___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtt_um_maxele___024root__trace_register(Vtt_um_maxele___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_maxele___024root__trace_register\n"); );
    Vtt_um_maxele__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtt_um_maxele___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtt_um_maxele___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtt_um_maxele___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtt_um_maxele___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtt_um_maxele___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_maxele___024root__trace_const_0\n"); );
    // Body
    Vtt_um_maxele___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtt_um_maxele___024root*>(voidSelf);
    Vtt_um_maxele__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vtt_um_maxele___024root__trace_full_0_sub_0(Vtt_um_maxele___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtt_um_maxele___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_maxele___024root__trace_full_0\n"); );
    // Body
    Vtt_um_maxele___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtt_um_maxele___024root*>(voidSelf);
    Vtt_um_maxele__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtt_um_maxele___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtt_um_maxele___024root__trace_full_0_sub_0(Vtt_um_maxele___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_maxele___024root__trace_full_0_sub_0\n"); );
    Vtt_um_maxele__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullSData(oldp+0,(vlSelfRef.tt_um_maxele__DOT__x_p),10);
    bufp->fullSData(oldp+1,(vlSelfRef.tt_um_maxele__DOT__x_n),10);
    bufp->fullSData(oldp+2,(vlSelfRef.tt_um_maxele__DOT__y_p),10);
    bufp->fullSData(oldp+3,(vlSelfRef.tt_um_maxele__DOT__y_n),10);
    bufp->fullBit(oldp+4,(vlSelfRef.tt_um_maxele__DOT__sync_n));
    bufp->fullCData(oldp+5,(vlSelfRef.tt_um_maxele__DOT__r_n),2);
    bufp->fullCData(oldp+6,(vlSelfRef.tt_um_maxele__DOT__g_n),2);
    bufp->fullCData(oldp+7,(vlSelfRef.tt_um_maxele__DOT__b_n),2);
    bufp->fullSData(oldp+8,(vlSelfRef.tt_um_maxele__DOT__matrix_p[0]),10);
    bufp->fullSData(oldp+9,(vlSelfRef.tt_um_maxele__DOT__matrix_p[1]),10);
    bufp->fullSData(oldp+10,(vlSelfRef.tt_um_maxele__DOT__matrix_p[2]),10);
    bufp->fullSData(oldp+11,(vlSelfRef.tt_um_maxele__DOT__matrix_p[3]),10);
    bufp->fullSData(oldp+12,(vlSelfRef.tt_um_maxele__DOT__matrix_p[4]),10);
    bufp->fullSData(oldp+13,(vlSelfRef.tt_um_maxele__DOT__matrix_p[5]),10);
    bufp->fullSData(oldp+14,(vlSelfRef.tt_um_maxele__DOT__matrix_p[6]),10);
    bufp->fullSData(oldp+15,(vlSelfRef.tt_um_maxele__DOT__matrix_p[7]),10);
    bufp->fullSData(oldp+16,(vlSelfRef.tt_um_maxele__DOT__matrix_p[8]),10);
    bufp->fullSData(oldp+17,(vlSelfRef.tt_um_maxele__DOT__matrix_p[9]),10);
    bufp->fullSData(oldp+18,(vlSelfRef.tt_um_maxele__DOT__matrix_p[10]),10);
    bufp->fullSData(oldp+19,(vlSelfRef.tt_um_maxele__DOT__matrix_p[11]),10);
    bufp->fullSData(oldp+20,(vlSelfRef.tt_um_maxele__DOT__matrix_p[12]),10);
    bufp->fullSData(oldp+21,(vlSelfRef.tt_um_maxele__DOT__matrix_p[13]),10);
    bufp->fullSData(oldp+22,(vlSelfRef.tt_um_maxele__DOT__matrix_p[14]),10);
    bufp->fullSData(oldp+23,(vlSelfRef.tt_um_maxele__DOT__matrix_p[15]),10);
    bufp->fullSData(oldp+24,(vlSelfRef.tt_um_maxele__DOT__matrix_p[16]),10);
    bufp->fullSData(oldp+25,(vlSelfRef.tt_um_maxele__DOT__matrix_p[17]),10);
    bufp->fullSData(oldp+26,(vlSelfRef.tt_um_maxele__DOT__matrix_p[18]),10);
    bufp->fullSData(oldp+27,(vlSelfRef.tt_um_maxele__DOT__matrix_p[19]),10);
    bufp->fullSData(oldp+28,(vlSelfRef.tt_um_maxele__DOT__matrix_n[0]),10);
    bufp->fullSData(oldp+29,(vlSelfRef.tt_um_maxele__DOT__matrix_n[1]),10);
    bufp->fullSData(oldp+30,(vlSelfRef.tt_um_maxele__DOT__matrix_n[2]),10);
    bufp->fullSData(oldp+31,(vlSelfRef.tt_um_maxele__DOT__matrix_n[3]),10);
    bufp->fullSData(oldp+32,(vlSelfRef.tt_um_maxele__DOT__matrix_n[4]),10);
    bufp->fullSData(oldp+33,(vlSelfRef.tt_um_maxele__DOT__matrix_n[5]),10);
    bufp->fullSData(oldp+34,(vlSelfRef.tt_um_maxele__DOT__matrix_n[6]),10);
    bufp->fullSData(oldp+35,(vlSelfRef.tt_um_maxele__DOT__matrix_n[7]),10);
    bufp->fullSData(oldp+36,(vlSelfRef.tt_um_maxele__DOT__matrix_n[8]),10);
    bufp->fullSData(oldp+37,(vlSelfRef.tt_um_maxele__DOT__matrix_n[9]),10);
    bufp->fullSData(oldp+38,(vlSelfRef.tt_um_maxele__DOT__matrix_n[10]),10);
    bufp->fullSData(oldp+39,(vlSelfRef.tt_um_maxele__DOT__matrix_n[11]),10);
    bufp->fullSData(oldp+40,(vlSelfRef.tt_um_maxele__DOT__matrix_n[12]),10);
    bufp->fullSData(oldp+41,(vlSelfRef.tt_um_maxele__DOT__matrix_n[13]),10);
    bufp->fullSData(oldp+42,(vlSelfRef.tt_um_maxele__DOT__matrix_n[14]),10);
    bufp->fullSData(oldp+43,(vlSelfRef.tt_um_maxele__DOT__matrix_n[15]),10);
    bufp->fullSData(oldp+44,(vlSelfRef.tt_um_maxele__DOT__matrix_n[16]),10);
    bufp->fullSData(oldp+45,(vlSelfRef.tt_um_maxele__DOT__matrix_n[17]),10);
    bufp->fullSData(oldp+46,(vlSelfRef.tt_um_maxele__DOT__matrix_n[18]),10);
    bufp->fullSData(oldp+47,(vlSelfRef.tt_um_maxele__DOT__matrix_n[19]),10);
    bufp->fullCData(oldp+48,(vlSelfRef.tt_um_maxele__DOT__active_p[0]),4);
    bufp->fullCData(oldp+49,(vlSelfRef.tt_um_maxele__DOT__active_p[1]),4);
    bufp->fullCData(oldp+50,(vlSelfRef.tt_um_maxele__DOT__active_p[2]),4);
    bufp->fullCData(oldp+51,(vlSelfRef.tt_um_maxele__DOT__active_p[3]),4);
    bufp->fullCData(oldp+52,(vlSelfRef.tt_um_maxele__DOT__active_n[0]),4);
    bufp->fullCData(oldp+53,(vlSelfRef.tt_um_maxele__DOT__active_n[1]),4);
    bufp->fullCData(oldp+54,(vlSelfRef.tt_um_maxele__DOT__active_n[2]),4);
    bufp->fullCData(oldp+55,(vlSelfRef.tt_um_maxele__DOT__active_n[3]),4);
    bufp->fullCData(oldp+56,(vlSelfRef.tt_um_maxele__DOT__ax_p),4);
    bufp->fullCData(oldp+57,(vlSelfRef.tt_um_maxele__DOT__ay_p),5);
    bufp->fullCData(oldp+58,(vlSelfRef.tt_um_maxele__DOT__ay_n),5);
    bufp->fullCData(oldp+59,(vlSelfRef.tt_um_maxele__DOT__input_buffer_p),8);
    bufp->fullIData(oldp+60,(vlSelfRef.tt_um_maxele__DOT__lx),28);
    bufp->fullIData(oldp+61,(vlSelfRef.tt_um_maxele__DOT__ly),28);
    bufp->fullCData(oldp+62,(vlSelfRef.tt_um_maxele__DOT__frames_n),6);
    bufp->fullCData(oldp+63,(vlSelfRef.tt_um_maxele__DOT__frames_p),6);
    bufp->fullBit(oldp+64,(vlSelfRef.tt_um_maxele__DOT__state_p));
    bufp->fullBit(oldp+65,(vlSelfRef.tt_um_maxele__DOT__state_n));
    bufp->fullCData(oldp+66,(vlSelfRef.ui_in),8);
    bufp->fullCData(oldp+67,(vlSelfRef.uo_out),8);
    bufp->fullCData(oldp+68,(vlSelfRef.uio_in),8);
    bufp->fullCData(oldp+69,(vlSelfRef.uio_out),8);
    bufp->fullCData(oldp+70,(vlSelfRef.uio_oe),8);
    bufp->fullBit(oldp+71,(vlSelfRef.ena));
    bufp->fullBit(oldp+72,(vlSelfRef.clk));
    bufp->fullBit(oldp+73,(vlSelfRef.rst_n));
    bufp->fullCData(oldp+74,(vlSelfRef.tt_um_maxele__DOT__ax_n),4);
    bufp->fullCData(oldp+75,(vlSelfRef.tt_um_maxele__DOT__input_buffer_n),8);
}
