#include"mat.h"


void mat_mul_hw_2(hls::stream<axis_data> & input, hls::stream<axis_data> &output)
{
#pragma HLS INTERFACE axis register both port=output
#pragma HLS INTERFACE axis register both port=intput
#pragma HLS INTERFACE ap_ctrl_none port=return

int i, j, k, sum;
M_TYPE mat1[row1][col1], mat2[row2][col2],mat_res[row1][col2];
#pragma HLS ARRAY_PARTITION variable=mat2 complete dim=2
#pragma HLS ARRAY_PARTITION variable=mat1 complete dim=1

axis_data local_stream;

//Storing streaming data to respective data type variables

	for( i=0;i<row1;i++)
		{
			for( j=0;j<col1;j++)
			{
#pragma HLS PIPELINE
				local_stream=input.read();
				mat1[i][j]=local_stream.data;
			}
		}

	for( i=0;i<row2;i++)
			{
				for( j=0;j<col2;j++)
				{
#pragma HLS PIPELINE
					local_stream=input.read();
					mat2[i][j]=local_stream.data;
				}
			}

//Matrix  Multiplication computation

	for( i=0;i<row1;i++)
	{
		for( j=0;j<col2;j++)
		{
#pragma HLS PIPELINE

			sum=0;
			for( k=0;k<row2;k++)
				{
					sum+=mat1[i][k]*mat2[k][j];
				}
				mat_res[i][j]=sum;
		}
	}

//writing back result to the stream
	for( i=0;i<row1;i++)
	{
			for( j=0;j<col2;j++)
			{
#pragma HLS PIPELINE
				local_stream.data=mat_res[i][j];
				if((row1-1==i) &&((col1-1==j)))
							local_stream.last=1;
				else
						local_stream.last=0;
				output.write(local_stream);
			}
	}
	return ;
}



//void mat_mul_hw_1(hls::stream<axis_data> & input, hls::stream<axis_data> &output)
//{
//#pragma HLS INTERFACE axis register both port=output
//#pragma HLS INTERFACE axis register both port=intput
//#pragma HLS INTERFACE ap_ctrl_none port=return
//
//int i, j, k, sum;
//M_TYPE mat1[row1][col1], mat2[row2][col2],mat_res[row1][col2];
//axis_data local_stream;
//
////Storing streaming data to respective data type variables
//
//	for( i=0;i<row1;i++)
//		{
//			for( j=0;j<col1;j++)
//			{
//#pragma HLS PIPELINE
//				local_stream=input.read();
//				mat1[i][j]=local_stream.data;
//			}
//		}
//
//	for( i=0;i<row2;i++)
//			{
//				for( j=0;j<col2;j++)
//				{
//#pragma HLS PIPELINE
//					local_stream=input.read();
//					mat2[i][j]=local_stream.data;
//				}
//			}
//
////Matrix  Multiplication computation
//
//	for( i=0;i<row1;i++)
//	{
//		for( j=0;j<col2;j++)
//		{
//			sum=0;
//			for( k=0;k<row2;k++)
//				{
//#pragma HLS PIPELINE
//					sum+=mat1[i][k]*mat2[k][j];
//				}
//				mat_res[i][j]=sum;
//		}
//	}
//
////writing back result to the stream
//	for( i=0;i<row1;i++)
//	{
//			for( j=0;j<col2;j++)
//			{
//#pragma HLS PIPELINE
//				local_stream.data=mat_res[i][j];
//				if((row1-1==i) &&((col1-1==j)))
//							local_stream.last=1;
//				else
//						local_stream.last=0;
//				output.write(local_stream);
//			}
//	}
//	return ;
//}

//void mat_mul_hw(hls::stream<axis_data> & input, hls::stream<axis_data> &output)
//{
//#pragma HLS INTERFACE axis register both port=output
//#pragma HLS INTERFACE axis register both port=intput
//#pragma HLS INTERFACE ap_ctrl_none port=return
//
//int i, j, k, mat1[row1][col1], mat2[row2][col2],mat_res[row1][col2], sum;
//
//axis_data local_stream;
//
////Storing streaming data to respective data type variables
//
//	for( i=0;i<row1;i++)
//		{
//			for( j=0;j<col1;j++)
//			{
//				local_stream=input.read();
//				mat1[i][j]=local_stream.data;
//			}
//		}
//
//	for( i=0;i<row2;i++)
//			{
//				for( j=0;j<col2;j++)
//				{
//					local_stream=input.read();
//					mat2[i][j]=local_stream.data;
//				}
//			}
//
////Matrix  Multiplication computation
//
//	for( i=0;i<row1;i++)
//	{
//		for( j=0;j<col2;j++)
//		{
//			sum=0;
//			for( k=0;k<row2;k++)
//				{
//					sum+=mat1[i][k]*mat2[k][j];
//				}
//				mat_res[i][j]=sum;
//		}
//	}
//
////writing back result to the stream
//	for( i=0;i<row1;i++)
//	{
//			for( j=0;j<col2;j++)
//			{
//				local_stream.data=mat_res[i][j];
//				if((row1-1==i) &&((col1-1==j)))
//							local_stream.last=1;
//				else
//						local_stream.last=0;
//				output.write(local_stream);
//			}
//	}
//	return ;
//}

