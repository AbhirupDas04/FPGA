// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __chacha_hw_dmul_64rcU__HH__
#define __chacha_hw_dmul_64rcU__HH__
#include "ACMP_dmul.h"
#include <systemc>

template<
    int ID,
    int NUM_STAGE,
    int din0_WIDTH,
    int din1_WIDTH,
    int dout_WIDTH>
SC_MODULE(chacha_hw_dmul_64rcU) {
    sc_core::sc_in_clk clk;
    sc_core::sc_in<sc_dt::sc_logic> reset;
    sc_core::sc_in<sc_dt::sc_logic> ce;
    sc_core::sc_in< sc_dt::sc_lv<din0_WIDTH> >   din0;
    sc_core::sc_in< sc_dt::sc_lv<din1_WIDTH> >   din1;
    sc_core::sc_out< sc_dt::sc_lv<dout_WIDTH> >   dout;



    ACMP_dmul<ID, 6, din0_WIDTH, din1_WIDTH, dout_WIDTH> ACMP_dmul_U;

    SC_CTOR(chacha_hw_dmul_64rcU):  ACMP_dmul_U ("ACMP_dmul_U") {
        ACMP_dmul_U.clk(clk);
        ACMP_dmul_U.reset(reset);
        ACMP_dmul_U.ce(ce);
        ACMP_dmul_U.din0(din0);
        ACMP_dmul_U.din1(din1);
        ACMP_dmul_U.dout(dout);

    }

};

#endif //
