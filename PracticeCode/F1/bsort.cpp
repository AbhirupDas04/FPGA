#include "mat.h"


void b_sort_hw(hls::stream<axis_data> & input, hls::stream<axis_data> &output)
{
#pragma HLS STREAM variable=output dim=1
#pragma HLS STREAM variable=input dim=1
#pragma HLS INTERFACE ap_ctrl_none port=return

int i;

M_TYPE arr1[10],result[10];
//#pragma HLS ARRAY_PARTITION variable=arr1 complete dim=1

axis_data local_stream;

//Storing streaming data to respective data type variables

	for( i=0;i<10;i++)
		{
//#pragma HLS PIPELINE
			local_stream=input.read();
			arr1[i]=local_stream.data;
			
		}

//Matrix  Multiplication computation

	for (int i = 0; i < 10; i++){
//#pragma HLS PIPELINE
		result[i] = arr1[i];
	}

	for (int j = 0; j < 9; ++j) {
		for (int i = 0; i < 9 - j; ++i) {
//#pragma HLS PIPELINE
		
			if (result[i] > result[i + 1]) {
				
				int temp = result[i];
				result[i] = result[i + 1];
				result[i + 1] = temp;
			}
		}
	}

//writing back result to the stream
	for( i=0;i<10;i++)
	{
//#pragma HLS PIPELINE
		local_stream.data=result[i];
		if(i==9)
					local_stream.last=1;
		else
				local_stream.last=0;
		output.write(local_stream);
			
	}
	return ;
}
