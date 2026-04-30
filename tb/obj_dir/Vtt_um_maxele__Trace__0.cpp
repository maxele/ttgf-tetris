// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtt_um_maxele__Syms.h"


void Vtt_um_maxele___024root__trace_chg_0_sub_0(Vtt_um_maxele___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtt_um_maxele___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_maxele___024root__trace_chg_0\n"); );
    // Body
    Vtt_um_maxele___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtt_um_maxele___024root*>(voidSelf);
    Vtt_um_maxele__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtt_um_maxele___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtt_um_maxele___024root__trace_chg_0_sub_0(Vtt_um_maxele___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_maxele___024root__trace_chg_0_sub_0\n"); );
    Vtt_um_maxele__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgSData(oldp+0,(vlSelfRef.tt_um_maxele__DOT__x_p),10);
        bufp->chgSData(oldp+1,(vlSelfRef.tt_um_maxele__DOT__x_n),10);
        bufp->chgSData(oldp+2,(vlSelfRef.tt_um_maxele__DOT__y_p),10);
        bufp->chgSData(oldp+3,(vlSelfRef.tt_um_maxele__DOT__y_n),10);
        bufp->chgBit(oldp+4,(vlSelfRef.tt_um_maxele__DOT__sync_n));
        bufp->chgCData(oldp+5,(vlSelfRef.tt_um_maxele__DOT__r_n),2);
        bufp->chgCData(oldp+6,(vlSelfRef.tt_um_maxele__DOT__g_n),2);
        bufp->chgCData(oldp+7,(vlSelfRef.tt_um_maxele__DOT__b_n),2);
        bufp->chgSData(oldp+8,(vlSelfRef.tt_um_maxele__DOT__matrix_p[0]),10);
        bufp->chgSData(oldp+9,(vlSelfRef.tt_um_maxele__DOT__matrix_p[1]),10);
        bufp->chgSData(oldp+10,(vlSelfRef.tt_um_maxele__DOT__matrix_p[2]),10);
        bufp->chgSData(oldp+11,(vlSelfRef.tt_um_maxele__DOT__matrix_p[3]),10);
        bufp->chgSData(oldp+12,(vlSelfRef.tt_um_maxele__DOT__matrix_p[4]),10);
        bufp->chgSData(oldp+13,(vlSelfRef.tt_um_maxele__DOT__matrix_p[5]),10);
        bufp->chgSData(oldp+14,(vlSelfRef.tt_um_maxele__DOT__matrix_p[6]),10);
        bufp->chgSData(oldp+15,(vlSelfRef.tt_um_maxele__DOT__matrix_p[7]),10);
        bufp->chgSData(oldp+16,(vlSelfRef.tt_um_maxele__DOT__matrix_p[8]),10);
        bufp->chgSData(oldp+17,(vlSelfRef.tt_um_maxele__DOT__matrix_p[9]),10);
        bufp->chgSData(oldp+18,(vlSelfRef.tt_um_maxele__DOT__matrix_p[10]),10);
        bufp->chgSData(oldp+19,(vlSelfRef.tt_um_maxele__DOT__matrix_p[11]),10);
        bufp->chgSData(oldp+20,(vlSelfRef.tt_um_maxele__DOT__matrix_p[12]),10);
        bufp->chgSData(oldp+21,(vlSelfRef.tt_um_maxele__DOT__matrix_p[13]),10);
        bufp->chgSData(oldp+22,(vlSelfRef.tt_um_maxele__DOT__matrix_p[14]),10);
        bufp->chgSData(oldp+23,(vlSelfRef.tt_um_maxele__DOT__matrix_p[15]),10);
        bufp->chgSData(oldp+24,(vlSelfRef.tt_um_maxele__DOT__matrix_p[16]),10);
        bufp->chgSData(oldp+25,(vlSelfRef.tt_um_maxele__DOT__matrix_p[17]),10);
        bufp->chgSData(oldp+26,(vlSelfRef.tt_um_maxele__DOT__matrix_p[18]),10);
        bufp->chgSData(oldp+27,(vlSelfRef.tt_um_maxele__DOT__matrix_p[19]),10);
        bufp->chgSData(oldp+28,(vlSelfRef.tt_um_maxele__DOT__matrix_n[0]),10);
        bufp->chgSData(oldp+29,(vlSelfRef.tt_um_maxele__DOT__matrix_n[1]),10);
        bufp->chgSData(oldp+30,(vlSelfRef.tt_um_maxele__DOT__matrix_n[2]),10);
        bufp->chgSData(oldp+31,(vlSelfRef.tt_um_maxele__DOT__matrix_n[3]),10);
        bufp->chgSData(oldp+32,(vlSelfRef.tt_um_maxele__DOT__matrix_n[4]),10);
        bufp->chgSData(oldp+33,(vlSelfRef.tt_um_maxele__DOT__matrix_n[5]),10);
        bufp->chgSData(oldp+34,(vlSelfRef.tt_um_maxele__DOT__matrix_n[6]),10);
        bufp->chgSData(oldp+35,(vlSelfRef.tt_um_maxele__DOT__matrix_n[7]),10);
        bufp->chgSData(oldp+36,(vlSelfRef.tt_um_maxele__DOT__matrix_n[8]),10);
        bufp->chgSData(oldp+37,(vlSelfRef.tt_um_maxele__DOT__matrix_n[9]),10);
        bufp->chgSData(oldp+38,(vlSelfRef.tt_um_maxele__DOT__matrix_n[10]),10);
        bufp->chgSData(oldp+39,(vlSelfRef.tt_um_maxele__DOT__matrix_n[11]),10);
        bufp->chgSData(oldp+40,(vlSelfRef.tt_um_maxele__DOT__matrix_n[12]),10);
        bufp->chgSData(oldp+41,(vlSelfRef.tt_um_maxele__DOT__matrix_n[13]),10);
        bufp->chgSData(oldp+42,(vlSelfRef.tt_um_maxele__DOT__matrix_n[14]),10);
        bufp->chgSData(oldp+43,(vlSelfRef.tt_um_maxele__DOT__matrix_n[15]),10);
        bufp->chgSData(oldp+44,(vlSelfRef.tt_um_maxele__DOT__matrix_n[16]),10);
        bufp->chgSData(oldp+45,(vlSelfRef.tt_um_maxele__DOT__matrix_n[17]),10);
        bufp->chgSData(oldp+46,(vlSelfRef.tt_um_maxele__DOT__matrix_n[18]),10);
        bufp->chgSData(oldp+47,(vlSelfRef.tt_um_maxele__DOT__matrix_n[19]),10);
        bufp->chgCData(oldp+48,(vlSelfRef.tt_um_maxele__DOT__active_p[0]),4);
        bufp->chgCData(oldp+49,(vlSelfRef.tt_um_maxele__DOT__active_p[1]),4);
        bufp->chgCData(oldp+50,(vlSelfRef.tt_um_maxele__DOT__active_p[2]),4);
        bufp->chgCData(oldp+51,(vlSelfRef.tt_um_maxele__DOT__active_p[3]),4);
        bufp->chgCData(oldp+52,(vlSelfRef.tt_um_maxele__DOT__active_n[0]),4);
        bufp->chgCData(oldp+53,(vlSelfRef.tt_um_maxele__DOT__active_n[1]),4);
        bufp->chgCData(oldp+54,(vlSelfRef.tt_um_maxele__DOT__active_n[2]),4);
        bufp->chgCData(oldp+55,(vlSelfRef.tt_um_maxele__DOT__active_n[3]),4);
        bufp->chgCData(oldp+56,(vlSelfRef.tt_um_maxele__DOT__ax_p),4);
        bufp->chgCData(oldp+57,(vlSelfRef.tt_um_maxele__DOT__ay_p),5);
        bufp->chgCData(oldp+58,(vlSelfRef.tt_um_maxele__DOT__ay_n),5);
        bufp->chgCData(oldp+59,(vlSelfRef.tt_um_maxele__DOT__input_buffer_p),8);
        bufp->chgIData(oldp+60,(vlSelfRef.tt_um_maxele__DOT__lx),28);
        bufp->chgIData(oldp+61,(vlSelfRef.tt_um_maxele__DOT__ly),28);
        bufp->chgCData(oldp+62,(vlSelfRef.tt_um_maxele__DOT__frames_n),6);
        bufp->chgCData(oldp+63,(vlSelfRef.tt_um_maxele__DOT__frames_p),6);
        bufp->chgBit(oldp+64,(vlSelfRef.tt_um_maxele__DOT__state_p));
        bufp->chgBit(oldp+65,(vlSelfRef.tt_um_maxele__DOT__state_n));
    }
    bufp->chgCData(oldp+66,(vlSelfRef.ui_in),8);
    bufp->chgCData(oldp+67,(vlSelfRef.uo_out),8);
    bufp->chgCData(oldp+68,(vlSelfRef.uio_in),8);
    bufp->chgCData(oldp+69,(vlSelfRef.uio_out),8);
    bufp->chgCData(oldp+70,(vlSelfRef.uio_oe),8);
    bufp->chgBit(oldp+71,(vlSelfRef.ena));
    bufp->chgBit(oldp+72,(vlSelfRef.clk));
    bufp->chgBit(oldp+73,(vlSelfRef.rst_n));
    bufp->chgCData(oldp+74,(vlSelfRef.tt_um_maxele__DOT__ax_n),4);
    bufp->chgCData(oldp+75,(vlSelfRef.tt_um_maxele__DOT__input_buffer_n),8);
}

void Vtt_um_maxele___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_maxele___024root__trace_cleanup\n"); );
    // Body
    Vtt_um_maxele___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtt_um_maxele___024root*>(voidSelf);
    Vtt_um_maxele__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
