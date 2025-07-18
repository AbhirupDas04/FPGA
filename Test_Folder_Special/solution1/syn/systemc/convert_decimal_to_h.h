// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _convert_decimal_to_h_HH_
#define _convert_decimal_to_h_HH_

#include "systemc.h"
#include "AESL_pkg.h"


namespace ap_rtl {

struct convert_decimal_to_h : public sc_module {
    // Port declarations 15
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<3> > hex_address0;
    sc_out< sc_logic > hex_ce0;
    sc_out< sc_logic > hex_we0;
    sc_out< sc_lv<8> > hex_d0;
    sc_out< sc_lv<3> > hex_address1;
    sc_out< sc_logic > hex_ce1;
    sc_out< sc_logic > hex_we1;
    sc_out< sc_lv<8> > hex_d1;
    sc_in< sc_lv<32> > p_read;


    // Module declarations
    convert_decimal_to_h(sc_module_name name);
    SC_HAS_PROCESS(convert_decimal_to_h);

    ~convert_decimal_to_h();

    sc_trace_file* mVcdFile;

    sc_signal< sc_lv<3> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<32> > quo_0_reg_265;
    sc_signal< sc_lv<4> > i_0_reg_274;
    sc_signal< sc_lv<1> > icmp_ln231_fu_292_p2;
    sc_signal< sc_lv<1> > icmp_ln231_reg_554;
    sc_signal< sc_logic > ap_CS_fsm_pp0_stage0;
    sc_signal< bool > ap_block_state2_pp0_stage0_iter0;
    sc_signal< bool > ap_block_state3_pp0_stage0_iter1;
    sc_signal< bool > ap_block_pp0_stage0_11001;
    sc_signal< sc_lv<4> > i_fu_298_p2;
    sc_signal< sc_lv<4> > i_reg_558;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter0;
    sc_signal< sc_lv<32> > sext_ln233_fu_360_p1;
    sc_signal< sc_lv<32> > rem_fu_376_p2;
    sc_signal< sc_lv<32> > rem_reg_568;
    sc_signal< sc_lv<1> > icmp_ln237_fu_382_p2;
    sc_signal< sc_lv<1> > icmp_ln237_reg_587;
    sc_signal< bool > ap_block_pp0_stage0_subdone;
    sc_signal< sc_logic > ap_condition_pp0_exit_iter0_state2;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter1;
    sc_signal< sc_lv<4> > ap_phi_mux_i_0_phi_fu_278_p4;
    sc_signal< bool > ap_block_pp0_stage0;
    sc_signal< sc_lv<64> > zext_ln237_fu_394_p1;
    sc_signal< sc_lv<64> > zext_ln252_fu_474_p1;
    sc_signal< sc_lv<1> > icmp_ln238_fu_399_p2;
    sc_signal< sc_lv<1> > icmp_ln239_fu_404_p2;
    sc_signal< sc_lv<1> > icmp_ln240_fu_409_p2;
    sc_signal< sc_lv<1> > icmp_ln241_fu_414_p2;
    sc_signal< sc_lv<1> > icmp_ln242_fu_419_p2;
    sc_signal< sc_lv<1> > icmp_ln243_fu_424_p2;
    sc_signal< sc_lv<1> > icmp_ln244_fu_429_p2;
    sc_signal< sc_lv<1> > icmp_ln245_fu_434_p2;
    sc_signal< sc_lv<1> > icmp_ln246_fu_439_p2;
    sc_signal< sc_lv<1> > icmp_ln247_fu_444_p2;
    sc_signal< sc_lv<1> > icmp_ln248_fu_449_p2;
    sc_signal< sc_lv<1> > icmp_ln249_fu_454_p2;
    sc_signal< sc_lv<1> > icmp_ln250_fu_459_p2;
    sc_signal< sc_lv<1> > icmp_ln251_fu_464_p2;
    sc_signal< sc_lv<1> > icmp_ln252_fu_469_p2;
    sc_signal< sc_lv<64> > zext_ln251_fu_479_p1;
    sc_signal< sc_lv<64> > zext_ln250_fu_484_p1;
    sc_signal< sc_lv<64> > zext_ln249_fu_489_p1;
    sc_signal< sc_lv<64> > zext_ln248_fu_494_p1;
    sc_signal< sc_lv<64> > zext_ln247_fu_499_p1;
    sc_signal< sc_lv<64> > zext_ln246_fu_504_p1;
    sc_signal< sc_lv<64> > zext_ln245_fu_509_p1;
    sc_signal< sc_lv<64> > zext_ln244_fu_514_p1;
    sc_signal< sc_lv<64> > zext_ln243_fu_519_p1;
    sc_signal< sc_lv<64> > zext_ln242_fu_524_p1;
    sc_signal< sc_lv<64> > zext_ln241_fu_529_p1;
    sc_signal< sc_lv<64> > zext_ln240_fu_534_p1;
    sc_signal< sc_lv<64> > zext_ln239_fu_539_p1;
    sc_signal< sc_lv<64> > zext_ln238_fu_544_p1;
    sc_signal< sc_lv<32> > sub_ln233_fu_312_p2;
    sc_signal< sc_lv<28> > tmp_s_fu_318_p4;
    sc_signal< sc_lv<29> > zext_ln233_fu_328_p1;
    sc_signal< sc_lv<28> > tmp_5_fu_338_p4;
    sc_signal< sc_lv<1> > tmp_12_fu_304_p3;
    sc_signal< sc_lv<29> > sub_ln233_1_fu_332_p2;
    sc_signal< sc_lv<29> > zext_ln233_1_fu_348_p1;
    sc_signal< sc_lv<29> > a_fu_352_p3;
    sc_signal< sc_lv<28> > trunc_ln234_fu_364_p1;
    sc_signal< sc_lv<32> > c_fu_368_p3;
    sc_signal< sc_lv<4> > sub_ln237_fu_388_p2;
    sc_signal< sc_lv<4> > grp_fu_286_p2;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<3> > ap_NS_fsm;
    sc_signal< sc_logic > ap_idle_pp0;
    sc_signal< sc_logic > ap_enable_pp0;
    sc_signal< bool > ap_condition_524;
    sc_signal< bool > ap_condition_527;
    sc_signal< bool > ap_condition_530;
    sc_signal< bool > ap_condition_533;
    sc_signal< bool > ap_condition_536;
    sc_signal< bool > ap_condition_539;
    sc_signal< bool > ap_condition_542;
    sc_signal< bool > ap_condition_545;
    sc_signal< bool > ap_condition_548;
    sc_signal< bool > ap_condition_551;
    sc_signal< bool > ap_condition_554;
    sc_signal< bool > ap_condition_557;
    sc_signal< bool > ap_condition_560;
    sc_signal< bool > ap_condition_510;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<3> ap_ST_fsm_state1;
    static const sc_lv<3> ap_ST_fsm_pp0_stage0;
    static const sc_lv<3> ap_ST_fsm_state4;
    static const bool ap_const_boolean_1;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const bool ap_const_boolean_0;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<8> ap_const_lv8_30;
    static const sc_lv<8> ap_const_lv8_66;
    static const sc_lv<8> ap_const_lv8_65;
    static const sc_lv<8> ap_const_lv8_64;
    static const sc_lv<8> ap_const_lv8_63;
    static const sc_lv<8> ap_const_lv8_62;
    static const sc_lv<8> ap_const_lv8_61;
    static const sc_lv<8> ap_const_lv8_39;
    static const sc_lv<8> ap_const_lv8_38;
    static const sc_lv<8> ap_const_lv8_37;
    static const sc_lv<8> ap_const_lv8_36;
    static const sc_lv<8> ap_const_lv8_35;
    static const sc_lv<8> ap_const_lv8_34;
    static const sc_lv<8> ap_const_lv8_33;
    static const sc_lv<8> ap_const_lv8_32;
    static const sc_lv<8> ap_const_lv8_31;
    static const sc_lv<4> ap_const_lv4_7;
    static const sc_lv<4> ap_const_lv4_8;
    static const sc_lv<4> ap_const_lv4_1;
    static const sc_lv<32> ap_const_lv32_1F;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<29> ap_const_lv29_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<32> ap_const_lv32_F;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_a_fu_352_p3();
    void thread_ap_CS_fsm_pp0_stage0();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state4();
    void thread_ap_block_pp0_stage0();
    void thread_ap_block_pp0_stage0_11001();
    void thread_ap_block_pp0_stage0_subdone();
    void thread_ap_block_state2_pp0_stage0_iter0();
    void thread_ap_block_state3_pp0_stage0_iter1();
    void thread_ap_condition_510();
    void thread_ap_condition_524();
    void thread_ap_condition_527();
    void thread_ap_condition_530();
    void thread_ap_condition_533();
    void thread_ap_condition_536();
    void thread_ap_condition_539();
    void thread_ap_condition_542();
    void thread_ap_condition_545();
    void thread_ap_condition_548();
    void thread_ap_condition_551();
    void thread_ap_condition_554();
    void thread_ap_condition_557();
    void thread_ap_condition_560();
    void thread_ap_condition_pp0_exit_iter0_state2();
    void thread_ap_done();
    void thread_ap_enable_pp0();
    void thread_ap_idle();
    void thread_ap_idle_pp0();
    void thread_ap_phi_mux_i_0_phi_fu_278_p4();
    void thread_ap_ready();
    void thread_c_fu_368_p3();
    void thread_grp_fu_286_p2();
    void thread_hex_address0();
    void thread_hex_address1();
    void thread_hex_ce0();
    void thread_hex_ce1();
    void thread_hex_d0();
    void thread_hex_d1();
    void thread_hex_we0();
    void thread_hex_we1();
    void thread_i_fu_298_p2();
    void thread_icmp_ln231_fu_292_p2();
    void thread_icmp_ln237_fu_382_p2();
    void thread_icmp_ln238_fu_399_p2();
    void thread_icmp_ln239_fu_404_p2();
    void thread_icmp_ln240_fu_409_p2();
    void thread_icmp_ln241_fu_414_p2();
    void thread_icmp_ln242_fu_419_p2();
    void thread_icmp_ln243_fu_424_p2();
    void thread_icmp_ln244_fu_429_p2();
    void thread_icmp_ln245_fu_434_p2();
    void thread_icmp_ln246_fu_439_p2();
    void thread_icmp_ln247_fu_444_p2();
    void thread_icmp_ln248_fu_449_p2();
    void thread_icmp_ln249_fu_454_p2();
    void thread_icmp_ln250_fu_459_p2();
    void thread_icmp_ln251_fu_464_p2();
    void thread_icmp_ln252_fu_469_p2();
    void thread_rem_fu_376_p2();
    void thread_sext_ln233_fu_360_p1();
    void thread_sub_ln233_1_fu_332_p2();
    void thread_sub_ln233_fu_312_p2();
    void thread_sub_ln237_fu_388_p2();
    void thread_tmp_12_fu_304_p3();
    void thread_tmp_5_fu_338_p4();
    void thread_tmp_s_fu_318_p4();
    void thread_trunc_ln234_fu_364_p1();
    void thread_zext_ln233_1_fu_348_p1();
    void thread_zext_ln233_fu_328_p1();
    void thread_zext_ln237_fu_394_p1();
    void thread_zext_ln238_fu_544_p1();
    void thread_zext_ln239_fu_539_p1();
    void thread_zext_ln240_fu_534_p1();
    void thread_zext_ln241_fu_529_p1();
    void thread_zext_ln242_fu_524_p1();
    void thread_zext_ln243_fu_519_p1();
    void thread_zext_ln244_fu_514_p1();
    void thread_zext_ln245_fu_509_p1();
    void thread_zext_ln246_fu_504_p1();
    void thread_zext_ln247_fu_499_p1();
    void thread_zext_ln248_fu_494_p1();
    void thread_zext_ln249_fu_489_p1();
    void thread_zext_ln250_fu_484_p1();
    void thread_zext_ln251_fu_479_p1();
    void thread_zext_ln252_fu_474_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
