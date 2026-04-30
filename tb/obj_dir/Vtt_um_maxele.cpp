// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtt_um_maxele__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtt_um_maxele::Vtt_um_maxele(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtt_um_maxele__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , ui_in{vlSymsp->TOP.ui_in}
    , uo_out{vlSymsp->TOP.uo_out}
    , uio_in{vlSymsp->TOP.uio_in}
    , uio_out{vlSymsp->TOP.uio_out}
    , uio_oe{vlSymsp->TOP.uio_oe}
    , ena{vlSymsp->TOP.ena}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtt_um_maxele::Vtt_um_maxele(const char* _vcname__)
    : Vtt_um_maxele(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtt_um_maxele::~Vtt_um_maxele() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtt_um_maxele___024root___eval_debug_assertions(Vtt_um_maxele___024root* vlSelf);
#endif  // VL_DEBUG
void Vtt_um_maxele___024root___eval_static(Vtt_um_maxele___024root* vlSelf);
void Vtt_um_maxele___024root___eval_initial(Vtt_um_maxele___024root* vlSelf);
void Vtt_um_maxele___024root___eval_settle(Vtt_um_maxele___024root* vlSelf);
void Vtt_um_maxele___024root___eval(Vtt_um_maxele___024root* vlSelf);

void Vtt_um_maxele::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtt_um_maxele::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtt_um_maxele___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtt_um_maxele___024root___eval_static(&(vlSymsp->TOP));
        Vtt_um_maxele___024root___eval_initial(&(vlSymsp->TOP));
        Vtt_um_maxele___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtt_um_maxele___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtt_um_maxele::eventsPending() { return false; }

uint64_t Vtt_um_maxele::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtt_um_maxele::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtt_um_maxele___024root___eval_final(Vtt_um_maxele___024root* vlSelf);

VL_ATTR_COLD void Vtt_um_maxele::final() {
    Vtt_um_maxele___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtt_um_maxele::hierName() const { return vlSymsp->name(); }
const char* Vtt_um_maxele::modelName() const { return "Vtt_um_maxele"; }
unsigned Vtt_um_maxele::threads() const { return 1; }
void Vtt_um_maxele::prepareClone() const { contextp()->prepareClone(); }
void Vtt_um_maxele::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtt_um_maxele::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtt_um_maxele___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtt_um_maxele___024root__trace_init_top(Vtt_um_maxele___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtt_um_maxele___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtt_um_maxele___024root*>(voidSelf);
    Vtt_um_maxele__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vtt_um_maxele___024root__trace_decl_types(tracep);
    Vtt_um_maxele___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtt_um_maxele___024root__trace_register(Vtt_um_maxele___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtt_um_maxele::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtt_um_maxele::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 76);
    Vtt_um_maxele___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
