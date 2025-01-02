#include <stdio.h>
#include <hls_stream.h>
#include <ap_int.h>

//#define plaintext_len 270
#define plaintext_len 750
#define key_len 64
#define nonce_len 24
#define counter_len 8

#define dim1 4
#define dim2 4
#define dim3 9

typedef char M_TYPE;

struct axis_data{
	M_TYPE data;
	ap_uint<1> last;
};

void chacha_hw(hls::stream<axis_data> & input, hls::stream<axis_data> &output);