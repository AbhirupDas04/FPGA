#include<stdio.h>
#include <hls_stream.h>
#include <ap_int.h>
typedef float M_TYPE;
//Matrix order i.e no. of row and col in input matrix
#define row1 8
#define col1 8
#define row2 8
#define col2 8

struct axis_data{
	M_TYPE data;
	ap_uint<1> last;
};

//void mat_mul_hw(hls::stream<axis_data> &input, hls::stream<axis_data> &output);
//void mat_mul_hw_1(hls::stream<axis_data> & input, hls::stream<axis_data> &output);
void mat_mul_hw_2(hls::stream<axis_data> & input, hls::stream<axis_data> &output);


