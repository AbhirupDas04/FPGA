#include <stdio.h>
#include <hls_stream.h>
#include <ap_int.h>
#include <stdint.h>

#define LEN 254
//#define LEN 128
//#define LEN 228

struct axis_data{
	uint32_t data;
	ap_uint<1> last;
};

void chacha_hw(hls::stream<axis_data> & input, hls::stream<axis_data> &output);