// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __chacha_hw_dadd_64qcK__HH__
#define __chacha_hw_dadd_64qcK__HH__
#include "ACMP_dadd.h"
#include <systemc>

template<
    int ID,
    int NUM_STAGE,
    int din0_WIDTH,
    int din1_WIDTH,
    int dout_WIDTH>
SC_MODULE(chacha_hw_dadd_64qcK) {
    sc_core::sc_in_clk clk;
    sc_core::sc_in<sc_dt::sc_logic> reset;
    sc_core::sc_in<sc_dt::sc_logic> ce;
    sc_core::sc_in< sc_dt::sc_lv<din0_WIDTH> >   din0;
    sc_core::sc_in< sc_dt::sc_lv<din1_WIDTH> >   din1;
    sc_core::sc_out< sc_dt::sc_lv<dout_WIDTH> >   dout;



    ACMP_dadd<ID, 5, din0_WIDTH, din1_WIDTH, dout_WIDTH> ACMP_dadd_U;

    SC_CTOR(chacha_hw_dadd_64qcK):  ACMP_dadd_U ("ACMP_dadd_U") {
        ACMP_dadd_U.clk(clk);
        ACMP_dadd_U.reset(reset);
        ACMP_dadd_U.ce(ce);
        ACMP_dadd_U.din0(din0);
        ACMP_dadd_U.din1(din1);
        ACMP_dadd_U.dout(dout);

    }

};

#endif //
