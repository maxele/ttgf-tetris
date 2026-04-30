// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtt_um_maxele.h for the primary calling header

#ifndef VERILATED_VTT_UM_MAXELE___024ROOT_H_
#define VERILATED_VTT_UM_MAXELE___024ROOT_H_  // guard

#include "verilated.h"


class Vtt_um_maxele__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtt_um_maxele___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(ui_in,7,0);
    VL_OUT8(uo_out,7,0);
    VL_IN8(uio_in,7,0);
    VL_OUT8(uio_out,7,0);
    VL_OUT8(uio_oe,7,0);
    VL_IN8(ena,0,0);
    CData/*0:0*/ tt_um_maxele__DOT____Vlvbound_hafe7d927__0;
    CData/*0:0*/ tt_um_maxele__DOT__sync_n;
    CData/*1:0*/ tt_um_maxele__DOT__r_n;
    CData/*1:0*/ tt_um_maxele__DOT__g_n;
    CData/*1:0*/ tt_um_maxele__DOT__b_n;
    CData/*3:0*/ tt_um_maxele__DOT__ax_p;
    CData/*3:0*/ tt_um_maxele__DOT__ax_n;
    CData/*4:0*/ tt_um_maxele__DOT__ay_p;
    CData/*4:0*/ tt_um_maxele__DOT__ay_n;
    CData/*7:0*/ tt_um_maxele__DOT__input_buffer_p;
    CData/*7:0*/ tt_um_maxele__DOT__input_buffer_n;
    CData/*5:0*/ tt_um_maxele__DOT__frames_n;
    CData/*5:0*/ tt_um_maxele__DOT__frames_p;
    CData/*0:0*/ tt_um_maxele__DOT__state_p;
    CData/*0:0*/ tt_um_maxele__DOT__state_n;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    SData/*9:0*/ tt_um_maxele__DOT__x_p;
    SData/*9:0*/ tt_um_maxele__DOT__x_n;
    SData/*9:0*/ tt_um_maxele__DOT__y_p;
    SData/*9:0*/ tt_um_maxele__DOT__y_n;
    IData/*27:0*/ tt_um_maxele__DOT__lx;
    IData/*27:0*/ tt_um_maxele__DOT__ly;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*9:0*/, 20> tt_um_maxele__DOT__matrix_p;
    VlUnpacked<SData/*9:0*/, 20> tt_um_maxele__DOT__matrix_n;
    VlUnpacked<CData/*3:0*/, 4> tt_um_maxele__DOT__active_p;
    VlUnpacked<CData/*3:0*/, 4> tt_um_maxele__DOT__active_n;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtt_um_maxele__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtt_um_maxele___024root(Vtt_um_maxele__Syms* symsp, const char* namep);
    ~Vtt_um_maxele___024root();
    VL_UNCOPYABLE(Vtt_um_maxele___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
