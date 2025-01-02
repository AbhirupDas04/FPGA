#include<stdio.h>
#include <hls_stream.h>
#include <ap_int.h>
typedef float M_TYPE;

struct axis_data{
	M_TYPE data;
	ap_uint<1> last;
};

void b_sort_hw(hls::stream<axis_data> & input, hls::stream<axis_data> &output);
