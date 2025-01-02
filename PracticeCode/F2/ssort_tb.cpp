#include "mat.h"

void s_sort(M_TYPE arr1[10], M_TYPE result[10]);

int main()
{
	M_TYPE arr1[10], result[10],result_hw[10];
	int i;

	//populating the input
	for(i=0;i<10;i++)
	{
		arr1[i] = 10 - i;
	}

	//calling software function of matrix mul.
	s_sort(arr1,result);

//-------------------Hardware function---------------------
hls::stream<axis_data> input,output;
axis_data local_stream;

//Generating the input for stream from pre-defined data types
for(i=0;i<10;i++)
	{
		local_stream.data=arr1[i];
		//Generating the last signal
		if(i==9)
				{
					local_stream.last=1;
				}
		else
		{
			local_stream.last=0;
		}
		input.write(local_stream);
	}

//calling the hardware function
s_sort_hw(input,output);



// converting the output received from the stream to per-defined data type
for(i=0; i<10;i++)
{
	local_stream=output.read();
	result_hw[i]=local_stream.data;
}

//Comparing the output from the PS (software) and PL (FPGA)
	for(i=0;i<10;i++)
	{
		if(result[i]!=result_hw[i])
		{
			printf("Error\n");
		}
	
	}
	printf("No Error\n");
	return 0;
}


void s_sort(M_TYPE arr1[10], M_TYPE result[10])
{
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

	return ;
}
