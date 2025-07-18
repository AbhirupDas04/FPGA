// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module convert_hex_to_binar_1 (
        ap_ready,
        p_read,
        ap_return_0,
        ap_return_1,
        ap_return_2,
        ap_return_3
);


output   ap_ready;
input  [7:0] p_read;
output  [7:0] ap_return_0;
output  [7:0] ap_return_1;
output  [7:0] ap_return_2;
output  [7:0] ap_return_3;

reg   [4:0] ap_phi_mux_bin_1_15_phi_fu_49_p30;
wire   [0:0] icmp_ln94_fu_245_p2;
wire   [0:0] icmp_ln95_fu_251_p2;
wire   [0:0] icmp_ln96_fu_257_p2;
wire   [0:0] icmp_ln97_fu_263_p2;
wire   [0:0] icmp_ln98_fu_269_p2;
wire   [0:0] icmp_ln99_fu_275_p2;
wire   [0:0] icmp_ln100_fu_281_p2;
wire   [0:0] icmp_ln101_fu_287_p2;
wire   [0:0] icmp_ln102_fu_293_p2;
wire   [0:0] icmp_ln103_fu_299_p2;
wire   [0:0] icmp_ln104_fu_305_p2;
wire   [0:0] icmp_ln105_fu_311_p2;
wire   [0:0] icmp_ln106_fu_317_p2;
wire   [0:0] icmp_ln107_fu_323_p2;
reg   [4:0] ap_phi_mux_bin_0_15_phi_fu_99_p30;
reg   [4:0] ap_phi_mux_bin_2_15_phi_fu_149_p30;
reg   [4:0] ap_phi_mux_bin_3_15_phi_fu_199_p30;
wire   [4:0] select_ln108_fu_335_p3;
wire   [0:0] icmp_ln108_fu_329_p2;
wire  signed [5:0] sext_ln111_fu_344_p1;
wire  signed [5:0] sext_ln111_1_fu_348_p1;
wire  signed [5:0] sext_ln111_2_fu_352_p1;
wire  signed [5:0] sext_ln111_3_fu_356_p1;
wire   [7:0] zext_ln111_1_fu_364_p1;
wire   [7:0] zext_ln111_fu_360_p1;
wire   [7:0] zext_ln111_2_fu_368_p1;
wire   [7:0] zext_ln111_3_fu_372_p1;

always @ (*) begin
    if ((((icmp_ln107_fu_323_p2 == 1'd0) & (icmp_ln106_fu_317_p2 == 1'd0) & (icmp_ln105_fu_311_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln106_fu_317_p2 == 1'd0) & (icmp_ln105_fu_311_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln107_fu_323_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln105_fu_311_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln106_fu_317_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln105_fu_311_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)))) begin
        ap_phi_mux_bin_0_15_phi_fu_99_p30 = 5'd17;
    end else if (((icmp_ln94_fu_245_p2 == 1'd1) | ((icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln95_fu_251_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)))) begin
        ap_phi_mux_bin_0_15_phi_fu_99_p30 = 5'd16;
    end else begin
        ap_phi_mux_bin_0_15_phi_fu_99_p30 = 'bx;
    end
end

always @ (*) begin
    if ((((icmp_ln107_fu_323_p2 == 1'd0) & (icmp_ln106_fu_317_p2 == 1'd0) & (icmp_ln105_fu_311_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln106_fu_317_p2 == 1'd0) & (icmp_ln105_fu_311_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln107_fu_323_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln105_fu_311_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln106_fu_317_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)))) begin
        ap_phi_mux_bin_1_15_phi_fu_49_p30 = 5'd17;
    end else if (((icmp_ln94_fu_245_p2 == 1'd1) | ((icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln105_fu_311_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln95_fu_251_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)))) begin
        ap_phi_mux_bin_1_15_phi_fu_49_p30 = 5'd16;
    end else begin
        ap_phi_mux_bin_1_15_phi_fu_49_p30 = 'bx;
    end
end

always @ (*) begin
    if ((((icmp_ln107_fu_323_p2 == 1'd0) & (icmp_ln106_fu_317_p2 == 1'd0) & (icmp_ln105_fu_311_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln105_fu_311_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)))) begin
        ap_phi_mux_bin_2_15_phi_fu_149_p30 = 5'd17;
    end else if (((icmp_ln94_fu_245_p2 == 1'd1) | ((icmp_ln106_fu_317_p2 == 1'd0) & (icmp_ln105_fu_311_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln107_fu_323_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln105_fu_311_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln106_fu_317_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln95_fu_251_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)))) begin
        ap_phi_mux_bin_2_15_phi_fu_149_p30 = 5'd16;
    end else begin
        ap_phi_mux_bin_2_15_phi_fu_149_p30 = 'bx;
    end
end

always @ (*) begin
    if (((icmp_ln107_fu_323_p2 == 1'd0) & (icmp_ln106_fu_317_p2 == 1'd0) & (icmp_ln105_fu_311_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln94_fu_245_p2 == 1'd0))) begin
        ap_phi_mux_bin_3_15_phi_fu_199_p30 = select_ln108_fu_335_p3;
    end else if ((((icmp_ln106_fu_317_p2 == 1'd0) & (icmp_ln105_fu_311_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln107_fu_323_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln105_fu_311_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln95_fu_251_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)))) begin
        ap_phi_mux_bin_3_15_phi_fu_199_p30 = 5'd17;
    end else if (((icmp_ln94_fu_245_p2 == 1'd1) | ((icmp_ln105_fu_311_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd0) & (icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln106_fu_317_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln103_fu_299_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd0) & (icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln104_fu_305_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln101_fu_287_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd0) & (icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln102_fu_293_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln99_fu_275_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd0) & (icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln100_fu_281_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln97_fu_263_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd0) & (icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln98_fu_269_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)) | ((icmp_ln95_fu_251_p2 == 1'd0) & (icmp_ln96_fu_257_p2 == 1'd1) & (icmp_ln94_fu_245_p2 == 1'd0)))) begin
        ap_phi_mux_bin_3_15_phi_fu_199_p30 = 5'd16;
    end else begin
        ap_phi_mux_bin_3_15_phi_fu_199_p30 = 'bx;
    end
end

assign ap_ready = 1'b1;

assign ap_return_0 = zext_ln111_1_fu_364_p1;

assign ap_return_1 = zext_ln111_fu_360_p1;

assign ap_return_2 = zext_ln111_2_fu_368_p1;

assign ap_return_3 = zext_ln111_3_fu_372_p1;

assign icmp_ln100_fu_281_p2 = ((p_read == 8'd54) ? 1'b1 : 1'b0);

assign icmp_ln101_fu_287_p2 = ((p_read == 8'd55) ? 1'b1 : 1'b0);

assign icmp_ln102_fu_293_p2 = ((p_read == 8'd56) ? 1'b1 : 1'b0);

assign icmp_ln103_fu_299_p2 = ((p_read == 8'd57) ? 1'b1 : 1'b0);

assign icmp_ln104_fu_305_p2 = ((p_read == 8'd97) ? 1'b1 : 1'b0);

assign icmp_ln105_fu_311_p2 = ((p_read == 8'd98) ? 1'b1 : 1'b0);

assign icmp_ln106_fu_317_p2 = ((p_read == 8'd99) ? 1'b1 : 1'b0);

assign icmp_ln107_fu_323_p2 = ((p_read == 8'd100) ? 1'b1 : 1'b0);

assign icmp_ln108_fu_329_p2 = ((p_read == 8'd101) ? 1'b1 : 1'b0);

assign icmp_ln94_fu_245_p2 = ((p_read == 8'd48) ? 1'b1 : 1'b0);

assign icmp_ln95_fu_251_p2 = ((p_read == 8'd49) ? 1'b1 : 1'b0);

assign icmp_ln96_fu_257_p2 = ((p_read == 8'd50) ? 1'b1 : 1'b0);

assign icmp_ln97_fu_263_p2 = ((p_read == 8'd51) ? 1'b1 : 1'b0);

assign icmp_ln98_fu_269_p2 = ((p_read == 8'd52) ? 1'b1 : 1'b0);

assign icmp_ln99_fu_275_p2 = ((p_read == 8'd53) ? 1'b1 : 1'b0);

assign select_ln108_fu_335_p3 = ((icmp_ln108_fu_329_p2[0:0] === 1'b1) ? 5'd16 : 5'd17);

assign sext_ln111_1_fu_348_p1 = $signed(ap_phi_mux_bin_0_15_phi_fu_99_p30);

assign sext_ln111_2_fu_352_p1 = $signed(ap_phi_mux_bin_2_15_phi_fu_149_p30);

assign sext_ln111_3_fu_356_p1 = $signed(ap_phi_mux_bin_3_15_phi_fu_199_p30);

assign sext_ln111_fu_344_p1 = $signed(ap_phi_mux_bin_1_15_phi_fu_49_p30);

assign zext_ln111_1_fu_364_p1 = $unsigned(sext_ln111_1_fu_348_p1);

assign zext_ln111_2_fu_368_p1 = $unsigned(sext_ln111_2_fu_352_p1);

assign zext_ln111_3_fu_372_p1 = $unsigned(sext_ln111_3_fu_356_p1);

assign zext_ln111_fu_360_p1 = $unsigned(sext_ln111_fu_344_p1);

endmodule //convert_hex_to_binar_1
