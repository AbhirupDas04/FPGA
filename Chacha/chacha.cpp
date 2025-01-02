#include "chacha_header.h"
#include "math.h"

void split_hw_3(char key[],char new_arr[][8],int n1){
    int count = 0;
    int count2;
    char str[8];
    int count3;
    for(int i = 0; i < 3; i++){
        count3 = 0;
        count2 = count + 6;
        for(int j = 0; j < 4; j++){
#pragma HLS PIPELINE
            str[count3] = key[count2];
            str[count3+1] = key[count2+1];
            count3 += 2;
            count2 -= 2;
        }
        for(int j = 0; j < 8; j++){
#pragma HLS PIPELINE
            new_arr[i][j] = str[j];
        }
        count += 8;
    }
}

void split_hw_8(char key[],char new_arr[][8],int n1){
    int count = 0;
    int count2;
    char str[8];
    int count3;
    for(int i = 0; i < 8; i++){
        count3 = 0;
        count2 = count + 6;
        for(int j = 0; j < 4; j++){
#pragma HLS PIPELINE
            str[count3] = key[count2];
            str[count3+1] = key[count2+1];
            count3 += 2;
            count2 -= 2;
        }
        for(int j = 0; j < 8; j++){
#pragma HLS PIPELINE
            new_arr[i][j] = str[j];
        }
        count += 8;
    }
}

void split_2_hw(char state_matrix[4][4][9],char key_stream[],int start,int remain,int mode){
    int count1 = start;
    int count2 = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 6; k >= 0; k-=2){
#pragma HLS PIPELINE
                count2 += 2;
                key_stream[count1] = state_matrix[i][j][k];
                key_stream[count1+1] = state_matrix[i][j][k+1];
                count1 += 2;
                if(count2 == remain && mode == 1){
                    return;
                }
            }
        }
    }
}

void convert_hex_to_binary_hw(char hex[8],char bin[32]){
    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        if(hex[i]=='0'){bin[4*i] = '0'; bin[4*i+1] = '0'; bin[4*i+2] = '0'; bin[4*i+3] = '0';}
        else if(hex[i]=='1'){bin[4*i] = '0'; bin[4*i+1] = '0'; bin[4*i+2] = '0'; bin[4*i+3] = '1';}
        else if(hex[i]=='2'){bin[4*i] = '0'; bin[4*i+1] = '0'; bin[4*i+2] = '1'; bin[4*i+3] = '0';}
        else if(hex[i]=='3'){bin[4*i] = '0'; bin[4*i+1] = '0'; bin[4*i+2] = '1'; bin[4*i+3] = '1';}
        else if(hex[i]=='4'){bin[4*i] = '0'; bin[4*i+1] = '1'; bin[4*i+2] = '0'; bin[4*i+3] = '0';}
        else if(hex[i]=='5'){bin[4*i] = '0'; bin[4*i+1] = '1'; bin[4*i+2] = '0'; bin[4*i+3] = '1';}
        else if(hex[i]=='6'){bin[4*i] = '0'; bin[4*i+1] = '1'; bin[4*i+2] = '1'; bin[4*i+3] = '0';}
        else if(hex[i]=='7'){bin[4*i] = '0'; bin[4*i+1] = '1'; bin[4*i+2] = '1'; bin[4*i+3] = '1';}
        else if(hex[i]=='8'){bin[4*i] = '1'; bin[4*i+1] = '0'; bin[4*i+2] = '0'; bin[4*i+3] = '0';}
        else if(hex[i]=='9'){bin[4*i] = '1'; bin[4*i+1] = '0'; bin[4*i+2] = '0'; bin[4*i+3] = '1';}
        else if(hex[i]=='a'){bin[4*i] = '1'; bin[4*i+1] = '0'; bin[4*i+2] = '1'; bin[4*i+3] = '0';}
        else if(hex[i]=='b'){bin[4*i] = '1'; bin[4*i+1] = '0'; bin[4*i+2] = '1'; bin[4*i+3] = '1';}
        else if(hex[i]=='c'){bin[4*i] = '1'; bin[4*i+1] = '1'; bin[4*i+2] = '0'; bin[4*i+3] = '0';}
        else if(hex[i]=='d'){bin[4*i] = '1'; bin[4*i+1] = '1'; bin[4*i+2] = '0'; bin[4*i+3] = '1';}
        else if(hex[i]=='e'){bin[4*i] = '1'; bin[4*i+1] = '1'; bin[4*i+2] = '1'; bin[4*i+3] = '0';}
        else if(hex[i]=='f'){bin[4*i] = '1'; bin[4*i+1] = '1'; bin[4*i+2] = '1'; bin[4*i+3] = '1';}
    }
}

void convert_hex_to_binary_2_hw(char hex[1],char bin[4]){
    for(int i = 0; i < 1; i++){
        if(hex[i]=='0'){bin[4*i] = '0'; bin[4*i+1] = '0'; bin[4*i+2] = '0'; bin[4*i+3] = '0';}
        else if(hex[i]=='1'){bin[4*i] = '0'; bin[4*i+1] = '0'; bin[4*i+2] = '0'; bin[4*i+3] = '1';}
        else if(hex[i]=='2'){bin[4*i] = '0'; bin[4*i+1] = '0'; bin[4*i+2] = '1'; bin[4*i+3] = '0';}
        else if(hex[i]=='3'){bin[4*i] = '0'; bin[4*i+1] = '0'; bin[4*i+2] = '1'; bin[4*i+3] = '1';}
        else if(hex[i]=='4'){bin[4*i] = '0'; bin[4*i+1] = '1'; bin[4*i+2] = '0'; bin[4*i+3] = '0';}
        else if(hex[i]=='5'){bin[4*i] = '0'; bin[4*i+1] = '1'; bin[4*i+2] = '0'; bin[4*i+3] = '1';}
        else if(hex[i]=='6'){bin[4*i] = '0'; bin[4*i+1] = '1'; bin[4*i+2] = '1'; bin[4*i+3] = '0';}
        else if(hex[i]=='7'){bin[4*i] = '0'; bin[4*i+1] = '1'; bin[4*i+2] = '1'; bin[4*i+3] = '1';}
        else if(hex[i]=='8'){bin[4*i] = '1'; bin[4*i+1] = '0'; bin[4*i+2] = '0'; bin[4*i+3] = '0';}
        else if(hex[i]=='9'){bin[4*i] = '1'; bin[4*i+1] = '0'; bin[4*i+2] = '0'; bin[4*i+3] = '1';}
        else if(hex[i]=='a'){bin[4*i] = '1'; bin[4*i+1] = '0'; bin[4*i+2] = '1'; bin[4*i+3] = '0';}
        else if(hex[i]=='b'){bin[4*i] = '1'; bin[4*i+1] = '0'; bin[4*i+2] = '1'; bin[4*i+3] = '1';}
        else if(hex[i]=='c'){bin[4*i] = '1'; bin[4*i+1] = '1'; bin[4*i+2] = '0'; bin[4*i+3] = '0';}
        else if(hex[i]=='d'){bin[4*i] = '1'; bin[4*i+1] = '1'; bin[4*i+2] = '0'; bin[4*i+3] = '1';}
        else if(hex[i]=='e'){bin[4*i] = '1'; bin[4*i+1] = '1'; bin[4*i+2] = '1'; bin[4*i+3] = '0';}
        else if(hex[i]=='f'){bin[4*i] = '1'; bin[4*i+1] = '1'; bin[4*i+2] = '1'; bin[4*i+3] = '1';}
    }
}

void convert_binary_to_hex_hw(char hex[8],char bin[32]){
    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        if(bin[4*i]=='0'){
            if(bin[4*i+1]=='0'){
                if(bin[4*i+2]=='0'){
                    if(bin[4*i+3]=='0'){ hex[i] = '0'; }
                    else{ hex[i] = '1'; }
                }
                else{
                    if(bin[4*i+3]=='0'){ hex[i] = '2'; }
                    else{ hex[i] = '3'; }
                }
            }
            else{
                if(bin[4*i+2]=='0'){
                    if(bin[4*i+3]=='0'){ hex[i] = '4'; }
                    else{ hex[i] = '5'; }
                }
                else{
                    if(bin[4*i+3]=='0'){ hex[i] = '6'; }
                    else{ hex[i] = '7'; }
                }
            }
        }
        else{
            if(bin[4*i+1]=='0'){
                if(bin[4*i+2]=='0'){
                    if(bin[4*i+3]=='0'){ hex[i] = '8'; }
                    else{ hex[i] = '9'; }
                }
                else{
                    if(bin[4*i+3]=='0'){ hex[i] = 'a'; }
                    else{ hex[i] = 'b'; }
                }
            }
            else{
                if(bin[4*i+2]=='0'){
                    if(bin[4*i+3]=='0'){ hex[i] = 'c'; }
                    else{ hex[i] = 'd'; }
                }
                else{
                    if(bin[4*i+3]=='0'){ hex[i] = 'e'; }
                    else{ hex[i] = 'f'; }
                }
            }
        }
    }
}

void convert_binary_to_hex_2_hw(char hex[1],char bin[4]){
    for(int i = 0; i < 1; i++){
        if(bin[4*i]=='0'){
            if(bin[4*i+1]=='0'){
                if(bin[4*i+2]=='0'){
                    if(bin[4*i+3]=='0'){ hex[i] = '0'; }
                    else{ hex[i] = '1'; }
                }
                else{
                    if(bin[4*i+3]=='0'){ hex[i] = '2'; }
                    else{ hex[i] = '3'; }
                }
            }
            else{
                if(bin[4*i+2]=='0'){
                    if(bin[4*i+3]=='0'){ hex[i] = '4'; }
                    else{ hex[i] = '5'; }
                }
                else{
                    if(bin[4*i+3]=='0'){ hex[i] = '6'; }
                    else{ hex[i] = '7'; }
                }
            }
        }
        else{
            if(bin[4*i+1]=='0'){
                if(bin[4*i+2]=='0'){
                    if(bin[4*i+3]=='0'){ hex[i] = '8'; }
                    else{ hex[i] = '9'; }
                }
                else{
                    if(bin[4*i+3]=='0'){ hex[i] = 'a'; }
                    else{ hex[i] = 'b'; }
                }
            }
            else{
                if(bin[4*i+2]=='0'){
                    if(bin[4*i+3]=='0'){ hex[i] = 'c'; }
                    else{ hex[i] = 'd'; }
                }
                else{
                    if(bin[4*i+3]=='0'){ hex[i] = 'e'; }
                    else{ hex[i] = 'f'; }
                }
            }
        }
    }
}

void convert_hex_to_decimal_hw(char hex[8], int dec[1]){
    int sum = 0;
    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        int val;
        if (48<=hex[i] && hex[i]<=57){
            val = hex[i] - 48;
        }
        else{
            val = hex[i] - 87;
        }
        sum += val * pow(16,7-i);
    }
    
    dec[0] = sum;
}

void convert_decimal_to_hex_hw(char hex[8], int dec[1]){
    int quo = dec[0];
    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        int a = quo/16;
        int c = a*16;
        int rem = quo - c;
        quo = a;
        if (rem == 0){ hex[7-i] = '0'; }
        else if (rem == 1){ hex[7-i] = '1'; }
        else if (rem == 2){ hex[7-i] = '2'; }
        else if (rem == 3){ hex[7-i] = '3'; }
        else if (rem == 4){ hex[7-i] = '4'; }
        else if (rem == 5){ hex[7-i] = '5'; }
        else if (rem == 6){ hex[7-i] = '6'; }
        else if (rem == 7){ hex[7-i] = '7'; }
        else if (rem == 8){ hex[7-i] = '8'; }
        else if (rem == 9){ hex[7-i] = '9'; }
        else if (rem == 10){ hex[7-i] = 'a'; }
        else if (rem == 11){ hex[7-i] = 'b'; }
        else if (rem == 12){ hex[7-i] = 'c'; }
        else if (rem == 13){ hex[7-i] = 'd'; }
        else if (rem == 14){ hex[7-i] = 'e'; }
        else if (rem == 15){ hex[7-i] = 'f'; }
    }
}

void add_hw(char state_matrix[4][4][9], int index1, int index2, char arr1[8], char arr2[8], char arr3[32], char arr4[32]){
    int ind11 = index1 / 4;
    int ind12 = index1 % 4;
    int ind21 = index2 / 4;
    int ind22 = index2 % 4;

    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        arr1[i] = state_matrix[ind11][ind12][i];
    }

    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        arr2[i] = state_matrix[ind21][ind22][i];
    }

    convert_hex_to_binary_hw(arr1,arr3);
    convert_hex_to_binary_hw(arr2,arr4);

    int carry = 0;

    for(int i = 31; i >= 0; i--){
#pragma HLS PIPELINE
        int sum1 = (int)arr3[i] - 48 + (int)arr4[i] - 48 + carry;
        switch(sum1){
            case 0: arr3[i] = '0'; carry = 0; break;
            case 1: arr3[i] = '1'; carry = 0; break;
            case 2: arr3[i] = '0'; carry = 1; break;
            case 3: arr3[i] = '1'; carry = 1; break;
        }
    }

    convert_binary_to_hex_hw(arr1,arr3);

    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        state_matrix[ind11][ind12][i] = arr1[i];
    }

}

void add_2_hw(char state_matrix[4][4][9], char copy_state_matrix[4][4][9], int index, char arr1[8], char arr2[8], char arr3[32], char arr4[32]){
    int ind1 = index / 4;
    int ind2 = index % 4;

    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        arr1[i] = state_matrix[ind1][ind2][i];
    }

    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        arr2[i] = copy_state_matrix[ind1][ind2][i];
    }

    convert_hex_to_binary_hw(arr1,arr3);
    convert_hex_to_binary_hw(arr2,arr4);

    int carry = 0;

    for(int i = 31; i >= 0; i--){
#pragma HLS PIPELINE
        int sum1 = (int)arr3[i] - 48 + (int)arr4[i] - 48 + carry;
        switch(sum1){
            case 0: arr3[i] = '0'; carry = 0; break;
            case 1: arr3[i] = '1'; carry = 0; break;
            case 2: arr3[i] = '0'; carry = 1; break;
            case 3: arr3[i] = '1'; carry = 1; break;
        }
    }

    convert_binary_to_hex_hw(arr1,arr3);

    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        state_matrix[ind1][ind2][i] = arr1[i];
    }

}

void xor_1_hw(char state_matrix[4][4][9], int index1, int index2, char arr1[8], char arr2[8], char arr3[32], char arr4[32]){
    int ind11 = index1 / 4;
    int ind12 = index1 % 4;
    int ind21 = index2 / 4;
    int ind22 = index2 % 4;

    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        arr1[i] = state_matrix[ind11][ind12][i];
    }

    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        arr2[i] = state_matrix[ind21][ind22][i];
    }
    
    convert_hex_to_binary_hw(arr1,arr3);
    convert_hex_to_binary_hw(arr2,arr4);
    
    for(int i = 0; i<32; i++){
#pragma HLS PIPELINE
        if(arr3[i]==arr4[i]){
            arr3[i] = '0';
        }
        else{
            arr3[i] = '1';
        }
    }

    convert_binary_to_hex_hw(arr1,arr3);

    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        state_matrix[ind11][ind12][i] = arr1[i];
    }

}

void xor_2_hw(char keystream[],char plaintext[],int index,char hex1[1],char hex2[1],char bin1[4],char bin2[4]){
    hex1[0] = keystream[index];
    hex2[0] = plaintext[index];

    convert_hex_to_binary_2_hw(hex1,bin1);
    convert_hex_to_binary_2_hw(hex2,bin2);

    for(int i = 0; i<4; i++){
        if(bin1[i] == bin2[i]){
            bin1[i] = '0';
        }
        else{
            bin1[i] = '1';
        }
    }

    convert_binary_to_hex_2_hw(hex1,bin1);
    keystream[index] = hex1[0];
}

void ls_hw(char state_matrix[4][4][9], int index1, int shift, char arr1[8], char arr2[32], char arr3[32]){
    int ind11 = index1 / 4;
    int ind12 = index1 % 4;

    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        arr1[i] = state_matrix[ind11][ind12][i];
    }
    
    convert_hex_to_binary_hw(arr1,arr2);

    shift %= 32;

    int count2 = shift-1;
    for(int i = 31; i > 0; i--){
#pragma HLS PIPELINE
        arr3[i] = arr2[count2];
        count2--;
		if (i==32-shift){
			break;
		}
    }

    int count = 31;
    for(int i = 31; i >= 0; i--){
#pragma HLS PIPELINE
		if(i > 31 - shift){
			continue;
		}
        arr3[i] = arr2[count];
        count--;
    }
    
    convert_binary_to_hex_hw(arr1,arr3);

    for(int i = 0; i < 8; i++){
#pragma HLS PIPELINE
        state_matrix[ind11][ind12][i] = arr1[i];
    }

}

void quarterround_hw(char state_matrix[4][4][9], int index1, int index2, int index3, int index4, char arr5[32], char arr6[32], char arr1[8], char arr2[8], int arr3[1], int arr4[1]){
    add_hw(state_matrix,index1,index2,arr1,arr2,arr5,arr6);
    xor_1_hw(state_matrix,index4,index1,arr1,arr2,arr5,arr6);
    ls_hw(state_matrix,index4,16,arr1,arr5,arr6);

    add_hw(state_matrix,index3,index4,arr1,arr2,arr5,arr6);
    xor_1_hw(state_matrix,index2,index3,arr1,arr2,arr5,arr6);
    ls_hw(state_matrix,index2,12,arr1,arr5,arr6);

    add_hw(state_matrix,index1,index2,arr1,arr2,arr5,arr6);
    xor_1_hw(state_matrix,index4,index1,arr1,arr2,arr5,arr6);
    ls_hw(state_matrix,index4,8,arr1,arr5,arr6);

    add_hw(state_matrix,index3,index4,arr1,arr2,arr5,arr6);
    xor_1_hw(state_matrix,index2,index3,arr1,arr2,arr5,arr6);
    ls_hw(state_matrix,index2,7,arr1,arr5,arr6);
}

void chacha_hw(hls::stream<axis_data> & input, hls::stream<axis_data> &output){
#pragma HLS STREAM variable=output dim=1
#pragma HLS STREAM variable=input dim=1
#pragma HLS INTERFACE ap_ctrl_none port=return
	char plaintext[plaintext_len];
	char key[key_len];
	char nonce[nonce_len];
	char counter[counter_len];
	char cipher[plaintext_len];

	axis_data local_stream;

	for(int i = 0; i < plaintext_len; i++){
#pragma HLS PIPELINE
		local_stream=input.read();
		plaintext[i] = local_stream.data;
	}

	for(int i = 0; i < key_len; i++){
#pragma HLS PIPELINE
		local_stream=input.read();
		key[i] = local_stream.data;
	}

	for(int i = 0; i < nonce_len; i++){
#pragma HLS PIPELINE
		local_stream=input.read();
		nonce[i] = local_stream.data;
	}

	for(int i = 0; i < counter_len; i++){
#pragma HLS PIPELINE
		local_stream=input.read();
		counter[i] = local_stream.data;
	}

    //

    int int_arr_test1[1];
    int int_arr_test2[1];

    char hex_arr_test1[8];
    char hex_arr_test2[8];

    char bin_arr_test1[32];
//#pragma HLS ARRAY_PARTITION variable=bin_arr_test1 block factor=16 dim=1
    char bin_arr_test2[32];
//#pragma HLS ARRAY_PARTITION variable=bin_arr_test2 block factor=16 dim=1

    //

	int len = plaintext_len;
    int n_blocks = len / 128;
    int remain = len % 128;

    if(remain != 0){
        n_blocks += 1;
    }

	int counter_val_arr[1];

	convert_hex_to_decimal_hw(counter,counter_val_arr);

    int counter_val = (int)(counter_val_arr[0]);

    for(int a = 0; a < n_blocks; a++){
        char state_matrix[dim1][dim2][dim3] = {{"61707865","3320646e" ,"79622d32" ,"6b206574"},{},{},{}};

        char key_arr[8][8];
        split_hw_8(key,key_arr,8);

        char nonce_arr[3][8];
        split_hw_3(nonce,nonce_arr,3);

        int count = 0;
        for(int i = 1; i <= 2; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 8; k++){
#pragma HLS PIPELINE
                    state_matrix[i][j][k] = key_arr[count][k];
                }
                count+=1;
            }
        }

        count = 0;
        for(int j = 1; j < 4; j++){
            for(int k = 0; k < 8; k++){
#pragma HLS PIPELINE
                state_matrix[3][j][k] = nonce_arr[count][k];
            }
            count+=1;
        }

        int arr1[1];
        arr1[0] = (int)counter_val;
        convert_decimal_to_hex_hw(counter,arr1);

        for(int k = 0; k < 8; k++){
#pragma HLS PIPELINE
            state_matrix[3][0][k] = counter[k];
        }

        char copy_state_matrix[4][4][9];

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 8; k++){
#pragma HLS PIPELINE
                    copy_state_matrix[i][j][k] = state_matrix[i][j][k];
                }
            }
        }

        for(int i = 0; i < 10; i++){
            quarterround_hw(state_matrix,0,4,8,12,bin_arr_test1,bin_arr_test2,hex_arr_test1,hex_arr_test2,int_arr_test1,int_arr_test2);
            quarterround_hw(state_matrix,1,5,9,13,bin_arr_test1,bin_arr_test2,hex_arr_test1,hex_arr_test2,int_arr_test1,int_arr_test2);
            quarterround_hw(state_matrix,2,6,10,14,bin_arr_test1,bin_arr_test2,hex_arr_test1,hex_arr_test2,int_arr_test1,int_arr_test2);
            quarterround_hw(state_matrix,3,7,11,15,bin_arr_test1,bin_arr_test2,hex_arr_test1,hex_arr_test2,int_arr_test1,int_arr_test2);
            quarterround_hw(state_matrix,0,5,10,15,bin_arr_test1,bin_arr_test2,hex_arr_test1,hex_arr_test2,int_arr_test1,int_arr_test2);
            quarterround_hw(state_matrix,1,6,11,12,bin_arr_test1,bin_arr_test2,hex_arr_test1,hex_arr_test2,int_arr_test1,int_arr_test2);
            quarterround_hw(state_matrix,2,7,8,13,bin_arr_test1,bin_arr_test2,hex_arr_test1,hex_arr_test2,int_arr_test1,int_arr_test2);
            quarterround_hw(state_matrix,3,4,9,14,bin_arr_test1,bin_arr_test2,hex_arr_test1,hex_arr_test2,int_arr_test1,int_arr_test2);
        }

        for(int i = 0; i < 16; i++){
            add_2_hw(state_matrix,copy_state_matrix,i,hex_arr_test1,hex_arr_test2,bin_arr_test1,bin_arr_test2);
        }

        if(a!=n_blocks-1){
            split_2_hw(state_matrix,cipher,a*128,remain,0);
        }
        else{
            split_2_hw(state_matrix,cipher,a*128,remain,1);
        }

        counter_val++;

    }

    char hex_arr_1[1];
    char hex_arr_2[1];
    char bin_arr_1[4];
    char bin_arr_2[4];

    for(int i = 0; i < len; i++){
#pragma HLS PIPELINE
        xor_2_hw(cipher,plaintext,i,hex_arr_1,hex_arr_2,bin_arr_1,bin_arr_2);
    }

	//writing back result to the stream
	for(int i = 0; i<plaintext_len; i++){
#pragma HLS PIPELINE
		local_stream.data=cipher[i];
		if(i == plaintext_len-1){
			local_stream.last=1;
		}
		else{
			local_stream.last=0;
		}
		output.write(local_stream);
	}

	return;
}