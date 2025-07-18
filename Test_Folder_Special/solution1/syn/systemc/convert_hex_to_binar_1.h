// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _convert_hex_to_binar_1_HH_
#define _convert_hex_to_binar_1_HH_

#include "systemc.h"
#include "AESL_pkg.h"


namespace ap_rtl {

struct convert_hex_to_binar_1 : public sc_module {
    // Port declarations 10
    sc_out< sc_logic > ap_ready;
    sc_in< sc_lv<8> > p_read;
    sc_in< sc_lv<8> > p_read1;
    sc_in< sc_lv<8> > p_read2;
    sc_in< sc_lv<8> > p_read3;
    sc_in< sc_lv<8> > p_read4;
    sc_out< sc_lv<8> > ap_return_0;
    sc_out< sc_lv<8> > ap_return_1;
    sc_out< sc_lv<8> > ap_return_2;
    sc_out< sc_lv<8> > ap_return_3;


    // Module declarations
    convert_hex_to_binar_1(sc_module_name name);
    SC_HAS_PROCESS(convert_hex_to_binar_1);

    ~convert_hex_to_binar_1();

    sc_trace_file* mVcdFile;

    sc_signal< sc_lv<1> > ap_phi_mux_write_flag3_15_phi_fu_85_p30;
    sc_signal< sc_lv<1> > icmp_ln94_fu_330_p2;
    sc_signal< sc_lv<1> > icmp_ln95_fu_336_p2;
    sc_signal< sc_lv<1> > icmp_ln96_fu_342_p2;
    sc_signal< sc_lv<1> > icmp_ln97_fu_348_p2;
    sc_signal< sc_lv<1> > icmp_ln98_fu_354_p2;
    sc_signal< sc_lv<1> > icmp_ln99_fu_360_p2;
    sc_signal< sc_lv<1> > icmp_ln100_fu_366_p2;
    sc_signal< sc_lv<1> > icmp_ln101_fu_372_p2;
    sc_signal< sc_lv<1> > icmp_ln102_fu_378_p2;
    sc_signal< sc_lv<1> > icmp_ln103_fu_384_p2;
    sc_signal< sc_lv<1> > icmp_ln104_fu_390_p2;
    sc_signal< sc_lv<1> > icmp_ln105_fu_396_p2;
    sc_signal< sc_lv<1> > icmp_ln106_fu_402_p2;
    sc_signal< sc_lv<1> > icmp_ln107_fu_408_p2;
    sc_signal< sc_lv<1> > or_ln108_fu_426_p2;
    sc_signal< sc_lv<5> > ap_phi_mux_bin_1_15_phi_fu_134_p30;
    sc_signal< sc_lv<5> > ap_phi_mux_bin_0_15_phi_fu_184_p30;
    sc_signal< sc_lv<5> > ap_phi_mux_bin_2_15_phi_fu_234_p30;
    sc_signal< sc_lv<5> > ap_phi_mux_bin_3_15_phi_fu_284_p30;
    sc_signal< sc_lv<5> > select_ln108_fu_433_p3;
    sc_signal< sc_lv<1> > icmp_ln108_fu_414_p2;
    sc_signal< sc_lv<1> > icmp_ln109_fu_420_p2;
    sc_signal< sc_lv<6> > sext_ln111_fu_442_p1;
    sc_signal< sc_lv<6> > sext_ln111_1_fu_446_p1;
    sc_signal< sc_lv<6> > sext_ln111_2_fu_450_p1;
    sc_signal< sc_lv<6> > sext_ln111_3_fu_454_p1;
    sc_signal< sc_lv<8> > zext_ln111_1_fu_462_p1;
    sc_signal< sc_lv<8> > zext_ln111_fu_458_p1;
    sc_signal< sc_lv<8> > zext_ln111_2_fu_466_p1;
    sc_signal< sc_lv<8> > zext_ln111_3_fu_470_p1;
    sc_signal< sc_lv<8> > select_ln111_fu_474_p3;
    sc_signal< sc_lv<8> > select_ln111_1_fu_482_p3;
    sc_signal< sc_lv<8> > select_ln111_2_fu_490_p3;
    sc_signal< sc_lv<8> > select_ln111_3_fu_498_p3;
    static const sc_logic ap_const_logic_1;
    static const sc_lv<1> ap_const_lv1_1;
    static const bool ap_const_boolean_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<5> ap_const_lv5_10;
    static const sc_lv<5> ap_const_lv5_11;
    static const sc_lv<8> ap_const_lv8_30;
    static const sc_lv<8> ap_const_lv8_31;
    static const sc_lv<8> ap_const_lv8_32;
    static const sc_lv<8> ap_const_lv8_33;
    static const sc_lv<8> ap_const_lv8_34;
    static const sc_lv<8> ap_const_lv8_35;
    static const sc_lv<8> ap_const_lv8_36;
    static const sc_lv<8> ap_const_lv8_37;
    static const sc_lv<8> ap_const_lv8_38;
    static const sc_lv<8> ap_const_lv8_39;
    static const sc_lv<8> ap_const_lv8_61;
    static const sc_lv<8> ap_const_lv8_62;
    static const sc_lv<8> ap_const_lv8_63;
    static const sc_lv<8> ap_const_lv8_64;
    static const sc_lv<8> ap_const_lv8_65;
    static const sc_lv<8> ap_const_lv8_66;
    static const sc_logic ap_const_logic_0;
    // Thread declarations
    void thread_ap_phi_mux_bin_0_15_phi_fu_184_p30();
    void thread_ap_phi_mux_bin_1_15_phi_fu_134_p30();
    void thread_ap_phi_mux_bin_2_15_phi_fu_234_p30();
    void thread_ap_phi_mux_bin_3_15_phi_fu_284_p30();
    void thread_ap_phi_mux_write_flag3_15_phi_fu_85_p30();
    void thread_ap_ready();
    void thread_ap_return_0();
    void thread_ap_return_1();
    void thread_ap_return_2();
    void thread_ap_return_3();
    void thread_icmp_ln100_fu_366_p2();
    void thread_icmp_ln101_fu_372_p2();
    void thread_icmp_ln102_fu_378_p2();
    void thread_icmp_ln103_fu_384_p2();
    void thread_icmp_ln104_fu_390_p2();
    void thread_icmp_ln105_fu_396_p2();
    void thread_icmp_ln106_fu_402_p2();
    void thread_icmp_ln107_fu_408_p2();
    void thread_icmp_ln108_fu_414_p2();
    void thread_icmp_ln109_fu_420_p2();
    void thread_icmp_ln94_fu_330_p2();
    void thread_icmp_ln95_fu_336_p2();
    void thread_icmp_ln96_fu_342_p2();
    void thread_icmp_ln97_fu_348_p2();
    void thread_icmp_ln98_fu_354_p2();
    void thread_icmp_ln99_fu_360_p2();
    void thread_or_ln108_fu_426_p2();
    void thread_select_ln108_fu_433_p3();
    void thread_select_ln111_1_fu_482_p3();
    void thread_select_ln111_2_fu_490_p3();
    void thread_select_ln111_3_fu_498_p3();
    void thread_select_ln111_fu_474_p3();
    void thread_sext_ln111_1_fu_446_p1();
    void thread_sext_ln111_2_fu_450_p1();
    void thread_sext_ln111_3_fu_454_p1();
    void thread_sext_ln111_fu_442_p1();
    void thread_zext_ln111_1_fu_462_p1();
    void thread_zext_ln111_2_fu_466_p1();
    void thread_zext_ln111_3_fu_470_p1();
    void thread_zext_ln111_fu_458_p1();
};

}

using namespace ap_rtl;

#endif
