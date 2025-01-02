#include "mat.h"


void s_sort_hw(hls::stream<axis_data> & input, hls::stream<axis_data> &output)
{
#pragma HLS INTERFACE axis register both port=output
#pragma HLS INTERFACE axis register both port=intput
#pragma HLS INTERFACE ap_ctrl_none port=return

int i;

M_TYPE arr1[10],result[10];
#pragma HLS ARRAY_PARTITION variable=arr1 complete dim=1

axis_data local_stream;

//Storing streaming data to respective data type variables

	for( i=0;i<10;i++)
		{
			#pragma HLS PIPELINE
			local_stream=input.read();
			arr1[i]=local_stream.data;
			
		}

//Matrix  Multiplication computation

	for (int i = 0; i < 10; i++){
		result[i] = arr1[i];
	}

	for(int i = 0; i < 10; i++) {
        for(int j = i+1; j < 10;j++) {
            if(result[i] > result[j]) {
                int temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

//writing back result to the stream
	for( i=0;i<10;i++)
	{
		#pragma HLS PIPELINE
		local_stream.data=arr1[i];
		if(i==9)
					local_stream.last=1;
		else
				local_stream.last=0;
		output.write(local_stream);
			
	}
	return ;
}