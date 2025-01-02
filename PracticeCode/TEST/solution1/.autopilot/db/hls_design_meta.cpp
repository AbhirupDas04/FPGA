#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst", 1, hls_in, -1, "", "", 1),
	Port_Property("input_V_data_dout", 32, hls_in, 0, "ap_fifo", "fifo_data", 10),
	Port_Property("input_V_data_empty_n", 1, hls_in, 0, "ap_fifo", "fifo_status", 10),
	Port_Property("input_V_data_read", 1, hls_out, 0, "ap_fifo", "fifo_update", 10),
	Port_Property("input_V_last_V_dout", 1, hls_in, 1, "ap_fifo", "fifo_data", 10),
	Port_Property("input_V_last_V_empty_n", 1, hls_in, 1, "ap_fifo", "fifo_status", 10),
	Port_Property("input_V_last_V_read", 1, hls_out, 1, "ap_fifo", "fifo_update", 10),
	Port_Property("output_V_data_din", 32, hls_out, 2, "ap_fifo", "fifo_data", 10),
	Port_Property("output_V_data_full_n", 1, hls_in, 2, "ap_fifo", "fifo_status", 10),
	Port_Property("output_V_data_write", 1, hls_out, 2, "ap_fifo", "fifo_update", 10),
	Port_Property("output_V_last_V_din", 1, hls_out, 3, "ap_fifo", "fifo_data", 10),
	Port_Property("output_V_last_V_full_n", 1, hls_in, 3, "ap_fifo", "fifo_status", 10),
	Port_Property("output_V_last_V_write", 1, hls_out, 3, "ap_fifo", "fifo_update", 10),
};
const char* HLS_Design_Meta::dut_name = "b_sort_hw";
