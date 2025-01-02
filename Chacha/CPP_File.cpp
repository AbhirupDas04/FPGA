#include "Header_File.h"

void split_hw(uint32_t state_matrix[4][4],uint32_t key_stream[][16],uint32_t start,uint32_t remain,uint32_t mode){
    uint32_t temp1;
    uint32_t temp2;
    uint32_t temp3;
    uint32_t temp4;

    uint32_t remain2 = remain % 8;

    for(uint32_t i = 0; i < 4; i++){
        for(uint32_t j = 0; j < 4; j++){
#pragma HLS PIPELINE
            if(mode == 1 && (remain / 8 == 4*i + j) && remain!=0){
                if(remain2 == 0){
                    return;
                }

                temp1 = state_matrix[i][j] << 24;
                if(remain2 == 2){
                    key_stream[start][4*i+j] = temp1;
                    return;
                }
            
                temp2 = state_matrix[i][j] << 16;
                temp2 = temp2 >> 24;
                temp2 = temp2 << 16;

                if(remain2 == 4){
                    key_stream[start][4*i+j] = temp1 + temp2;
                    return;
                }

                temp3 = state_matrix[i][j] << 8;
                temp3 = temp3 >> 24;
                temp3 = temp3 << 8;

                if(remain2 == 6){
                    key_stream[start][4*i+j] = temp1 + temp2 + temp3;
                    return;
                }
            }

            temp1 = state_matrix[i][j] << 24;
            
            temp2 = state_matrix[i][j] << 16;
            temp2 = temp2 >> 24;
            temp2 = temp2 << 16;

            temp3 = state_matrix[i][j] << 8;
            temp3 = temp3 >> 24;
            temp3 = temp3 << 8;

            temp4 = state_matrix[i][j] >> 24;

            key_stream[start][4*i+j] = temp1 + temp2 + temp3 + temp4;
        }
    }
}

void quarterround_hw(uint32_t state_matrix[4][4], uint32_t ind1, uint32_t ind2, uint32_t ind3, uint32_t ind4){

	uint32_t ind1_a = ind1 / 4;
	uint32_t ind1_b = ind1 % 4;
	uint32_t ind2_a = ind2 / 4;
	uint32_t ind2_b = ind2 % 4;
	uint32_t ind3_a = ind3 / 4;
	uint32_t ind3_b = ind3 % 4;
	uint32_t ind4_a = ind4 / 4;
	uint32_t ind4_b = ind4 % 4;

    state_matrix[ind1_a][ind1_b] += state_matrix[ind2_a][ind2_b];
    state_matrix[ind4_a][ind4_b] ^= state_matrix[ind1_a][ind1_b];
    state_matrix[ind4_a][ind4_b] = state_matrix[ind4_a][ind4_b] << 16 | state_matrix[ind4_a][ind4_b] >> 16;

    state_matrix[ind3_a][ind3_b] += state_matrix[ind4_a][ind4_b];
    state_matrix[ind2_a][ind2_b] ^= state_matrix[ind3_a][ind3_b];
    state_matrix[ind2_a][ind2_b] = state_matrix[ind2_a][ind2_b] << 12 | state_matrix[ind2_a][ind2_b] >> 20;

    state_matrix[ind1_a][ind1_b] += state_matrix[ind2_a][ind2_b];
    state_matrix[ind4_a][ind4_b] ^= state_matrix[ind1_a][ind1_b];
    state_matrix[ind4_a][ind4_b] = state_matrix[ind4_a][ind4_b] << 8 | state_matrix[ind4_a][ind4_b] >> 24;

    state_matrix[ind3_a][ind3_b] += state_matrix[ind4_a][ind4_b];
    state_matrix[ind2_a][ind2_b] ^= state_matrix[ind3_a][ind3_b];
    state_matrix[ind2_a][ind2_b] = state_matrix[ind2_a][ind2_b] << 7 | state_matrix[ind2_a][ind2_b] >> 25;
}

void chacha_hw(hls::stream<axis_data> &input, hls::stream<axis_data> &output){
#pragma HLS INTERFACE axis register both port=output
#pragma HLS INTERFACE axis register both port=input
#pragma HLS INTERFACE ap_ctrl_none port=return
	axis_data local_stream;

    uint32_t n_blocks = LEN / 128;
    uint32_t remain = LEN % 128;

    if(remain != 0){
        n_blocks += 1;
    }

    uint32_t plaintext[n_blocks][16];
	uint32_t key[8];
#pragma HLS ARRAY_PARTITION variable=key complete dim=1
	uint32_t nonce[3];
	uint32_t counter;
	uint32_t cipher[n_blocks][16];

    uint32_t act_state_matrix[4][4] = {{},{},{},{0,0,0,0}};
	#pragma HLS ARRAY_PARTITION variable=act_state_matrix complete dim=1

    uint32_t flag = 0;

    uint32_t i,j;

    for(i = 0; i < 4; i++){
#pragma HLS UNROLL
    	local_stream = input.read();
    	act_state_matrix[0][i] = local_stream.data;
    }

	for(i = 0; i < n_blocks; i++){
#pragma HLS UNROLL
        for(j = 0; j < 16; j++){
            local_stream=input.read();
            plaintext[i][j] = local_stream.data;
            if(local_stream.last == 1){
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            break;
        }
	}

	for(i = 0; i < 8; i++){
#pragma HLS UNROLL
		local_stream=input.read();
		key[i] = local_stream.data;
		//printf("%08x\n",key[i]);
	}

	for(i = 0; i < 3; i++){
#pragma HLS UNROLL
		local_stream=input.read();
		nonce[i] = local_stream.data;
		//printf("%08x\n",nonce[i]);
	}

    local_stream=input.read();
    counter = local_stream.data;

    uint32_t state_matrix[4][4], copy_state_matrix[4][4];
#pragma HLS ARRAY_PARTITION variable=state_matrix complete dim=1

    uint32_t temp1;
    uint32_t temp2;
    uint32_t temp3;

//    for(int k = 0; k < 8; k++){
//    	//for(int l = 0; l < 16; l++)
//    		printf("%08x ",key[k]);
//    }

    for(j = 1; j < 3; j++){
        for(i = 0; i < 4; i++){
#pragma HLS UNROLL
            temp1 = key[4*(j-1)+i] << 24;
            
            temp2 = key[4*(j-1)+i] << 16;
            temp2 = temp2 >> 24;
            temp2 = temp2 << 16;

            temp3 = key[4*(j-1)+i] << 8;
            temp3 = temp3 >> 24;
            temp3 = temp3 << 8;

            key[4*(j-1)+i] = key[4*(j-1)+i] >> 24;

            act_state_matrix[j][i] = key[4*(j-1)+i] + temp1 + temp2 + temp3;
        }
    }

    for(i = 1; i < 4; i++){
#pragma HLS UNROLL
        temp1 = nonce[i-1] << 24;
        
        temp2 = nonce[i-1] << 16;
        temp2 = temp2 >> 24;
        temp2 = temp2 << 16;

        temp3 = nonce[i-1] << 8;
        temp3 = temp3 >> 24;
        temp3 = temp3 << 8;

        nonce[i-1] = nonce[i-1] >> 24;

        act_state_matrix[3][i] = nonce[i-1] + temp1 + temp2 + temp3;
    }

    for(uint32_t a = 0; a < n_blocks; a++){
#pragma HLS UNROLL
        act_state_matrix[3][0] = counter;

        for(i = 0; i < 4; i++){
#pragma HLS PIPELINE rewind
           for(j = 0; j < 4; j++){
               state_matrix[i][j] = act_state_matrix[i][j];
                copy_state_matrix[i][j] = act_state_matrix[i][j];
            }
        }

        for(i = 0; i < 10; i++){
        	//for(j = 0; j < 1; j++){
//#pragma HLS PIPELINE
			quarterround_hw(state_matrix,0,4,8,12);
			quarterround_hw(state_matrix,1,5,9,13);
			quarterround_hw(state_matrix,2,6,10,14);
			quarterround_hw(state_matrix,3,7,11,15);
        	//}
            quarterround_hw(state_matrix,0,5,10,15);
            quarterround_hw(state_matrix,1,6,11,12);
            quarterround_hw(state_matrix,2,7,8,13);
            quarterround_hw(state_matrix,3,4,9,14);
        }

        for(i = 0; i < 4; i++){
#pragma HLS PIPELINE rewind
            for(j = 0; j < 4; j++){
                state_matrix[i][j] += copy_state_matrix[i][j];
            }
        }

        if(a!=n_blocks-1){
            split_hw(state_matrix,cipher,a,remain,0);
        }
        else{
            split_hw(state_matrix,cipher,a,remain,1);
        }

        counter++;

    }

    flag = 0;

    for(i = 0; i < n_blocks; i++){
        for(j = 0; j < 16; j++){
           cipher[i][j] = cipher[i][j] ^ plaintext[i][j];

            if(128*i + 8*j <= LEN && (128*i + 8*(j+1)) > LEN){
                if(remain%8 == 2){
                    cipher[i][j] = cipher[i][j] >> 24;
                }
                if(remain%8 == 4){
                    cipher[i][j] = cipher[i][j] >> 16;
                }
                if(remain%8 == 6){
                    cipher[i][j] = cipher[i][j] >> 8;
                }
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            break;
        }
    }

	//writing back result to the stream

    flag = 0;

	for( i = 0; i<n_blocks; i++){
        for(j = 0; j < 16; j++){
            local_stream.data=cipher[i][j];
            //printf("%08x ",cipher[i][j]);
            if(128*i + 8*j < LEN && 128*i + 8*(j+1) >= LEN){
                local_stream.last=1;
                output.write(local_stream);
                flag = 1;
                break;
            }
            else{
                local_stream.last=0;
                output.write(local_stream);
            }
        }

        if(flag == 1){
            break;;
        }
	}
}
