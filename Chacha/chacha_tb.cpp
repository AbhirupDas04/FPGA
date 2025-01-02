#include "chacha_header.h"
#include "math.h"

void split(char key[],char new_arr[][8],int n1){
    int count = 0;
    int count2;
    char str[8];
    int count3;
    for(int i = 0; i < n1; i++){
        count3 = 0;
        count2 = count + 6;
        for(int j = 0; j < 4; j++){
            str[count3] = key[count2];
            str[count3+1] = key[count2+1];
            count3 += 2;
            count2 -= 2;
        }
        for(int j = 0; j < 8; j++){
            new_arr[i][j] = str[j];
        }
        count += 8;
    }
}

void split_2(char state_matrix[4][4][9],char key_stream[],int start,int remain,int mode){
    int count1 = start;
    int count2 = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 6; k >= 0; k-=2){
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

void convert_hex_to_binary(char hex[8],char bin[32]){
    for(int i = 0; i < 8; i++){
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

void convert_hex_to_binary_2(char hex[1],char bin[4]){
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

void convert_binary_to_hex(char hex[8],char bin[32]){
    for(int i = 0; i < 8; i++){
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

void convert_binary_to_hex_2(char hex[1],char bin[4]){
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

void convert_hex_to_decimal(char hex[8], double dec[1]){
    double sum = 0;
    for(int i = 0; i < 8; i++){
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

void convert_decimal_to_hex(char hex[8], double dec[1]){
    double quo = dec[0];
    for(int i = 0; i < 8; i++){
        double a = quo/16;
        int b = (int)a;
        double d = (double) b;
        double c = d*16;
        int rem = (int)(quo - c);
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

void add(char state_matrix[4][4][9], int index1, int index2){
    int ind11 = index1 / 4;
    int ind12 = index1 % 4;
    int ind21 = index2 / 4;
    int ind22 = index2 % 4;

    char arr1[8];
    char arr2[8];

    for(int i = 0; i < 8; i++){
        arr1[i] = state_matrix[ind11][ind12][i];
    }

    for(int i = 0; i < 8; i++){
        arr2[i] = state_matrix[ind21][ind22][i];
    }

    double arr3[1];
    double arr4[1];

    convert_hex_to_decimal(arr1,arr3);
    convert_hex_to_decimal(arr2,arr4);

    double val1 = arr3[0];
    double val2 = arr4[0];

    val1 += val2;
    if(val1 > (double)4294967295){
        val1 -= (double)4294967296;
    }

    arr3[0] = val1;

    convert_decimal_to_hex(arr1,arr3);

    for(int i = 0; i < 8; i++){
        state_matrix[ind11][ind12][i] = arr1[i];
    }

}

void add_2(char state_matrix[4][4][9], char copy_state_matrix[4][4][9], int index){
    int ind1 = index / 4;
    int ind2 = index % 4;

    char arr1[8];
    char arr2[8];

    for(int i = 0; i < 8; i++){
        arr1[i] = state_matrix[ind1][ind2][i];
    }

    for(int i = 0; i < 8; i++){
        arr2[i] = copy_state_matrix[ind1][ind2][i];
    }

    double arr3[1];
    double arr4[1];

    convert_hex_to_decimal(arr1,arr3);
    convert_hex_to_decimal(arr2,arr4);

    double val1 = arr3[0];
    double val2 = arr4[0];

    val1 += val2;
    if(val1 > (double)4294967295){
        val1 -= (double)4294967296;
    }

    arr3[0] = val1;

    convert_decimal_to_hex(arr1,arr3);

    for(int i = 0; i < 8; i++){
        state_matrix[ind1][ind2][i] = arr1[i];
    }

}

void xor_1(char state_matrix[4][4][9], int index1, int index2){
    int ind11 = index1 / 4;
    int ind12 = index1 % 4;
    int ind21 = index2 / 4;
    int ind22 = index2 % 4;

    char arr1[8];
    char arr2[8];

    for(int i = 0; i < 8; i++){
        arr1[i] = state_matrix[ind11][ind12][i];
    }

    for(int i = 0; i < 8; i++){
        arr2[i] = state_matrix[ind21][ind22][i];
    }

    char arr3[32];
    char arr4[32];
    
    convert_hex_to_binary(arr1,arr3);
    convert_hex_to_binary(arr2,arr4);
    
    for(int i = 0; i<32; i++){
        if(arr3[i]==arr4[i]){
            arr3[i] = '0';
        }
        else{
            arr3[i] = '1';
        }
    }

    convert_binary_to_hex(arr1,arr3);

    for(int i = 0; i < 8; i++){
        state_matrix[ind11][ind12][i] = arr1[i];
    }

}

void xor_2(char keystream[],char plaintext[],int index){
    char hex1[1], hex2[1];
    char bin1[4], bin2[4];

    hex1[0] = keystream[index];
    hex2[0] = plaintext[index];

    convert_hex_to_binary_2(hex1,bin1);
    convert_hex_to_binary_2(hex2,bin2);

    for(int i = 0; i<4; i++){
        if(bin1[i] == bin2[i]){
            bin1[i] = '0';
        }
        else{
            bin1[i] = '1';
        }
    }

    convert_binary_to_hex_2(hex1,bin1);
    keystream[index] = hex1[0];
}

void ls(char state_matrix[4][4][9], int index1, int shift){
    int ind11 = index1 / 4;
    int ind12 = index1 % 4;

    char arr1[8];

    for(int i = 0; i < 8; i++){
        arr1[i] = state_matrix[ind11][ind12][i];
    }

    char arr2[32];
    char arr3[32];
    
    convert_hex_to_binary(arr1,arr2);

    shift %= 32;

    int count2 = shift-1;
    for(int i = 31; i > 31-shift; i--){
        arr3[i] = arr2[count2];
        count2--;
    }

    int count = 31;
    for(int i = 31-shift; i >= 0; i--){
        arr3[i] = arr2[count];
        count--;
    }
    
    convert_binary_to_hex(arr1,arr3);

    for(int i = 0; i < 8; i++){
        state_matrix[ind11][ind12][i] = arr1[i];
    }

}

void quarterround(char state_matrix[4][4][9], int index1, int index2, int index3, int index4){
    add(state_matrix,index1,index2);
    xor_1(state_matrix,index4,index1);
    ls(state_matrix,index4,16);

    add(state_matrix,index3,index4);
    xor_1(state_matrix,index2,index3);
    ls(state_matrix,index2,12);

    add(state_matrix,index1,index2);
    xor_1(state_matrix,index4,index1);
    ls(state_matrix,index4,8);

    add(state_matrix,index3,index4);
    xor_1(state_matrix,index2,index3);
    ls(state_matrix,index2,7);
}

void chacha(M_TYPE plaintext[plaintext_len],M_TYPE key[key_len],M_TYPE nonce[nonce_len],M_TYPE counter[counter_len],M_TYPE cipher[plaintext_len]);

int main()
{
	//char plaintext[] = {"416e79207375626d697373696f6e20746f20746865204945544620696e74656e6465642062792074686520436f6e7472696275746f7220666f72207075626c69636174696f6e20617320616c6c206f722070617274206f6620616e204945544620496e7465726e65742d4472616674206f722052464320616e6420616e792073746174656d6566"};
	char plaintext[] = {"416e79207375626d697373696f6e20746f20746865204945544620696e74656e6465642062792074686520436f6e7472696275746f7220666f72207075626c69636174696f6e20617320616c6c206f722070617274206f6620616e204945544620496e7465726e65742d4472616674206f722052464320616e6420616e792073746174656d656e74206d6164652077697468696e2074686520636f6e74657874206f6620616e204945544620616374697669747920697320636f6e7369646572656420616e20224945544620436f6e747269627574696f6e222e20537563682073746174656d656e747320696e636c756465206f72616c2073746174656d656e747320696e20494554462073657373696f6e732c2061732077656c6c206173207772697474656e20616e6420656c656374726f6e696320636f6d6d756e69636174696f6e73206d61646520617420616e792074696d65206f7220706c6163652c207768696368206172652061646472657373656420746f"};
    char key[] = {"0000000000000000000000000000000000000000000000000000000000000001"};
	char nonce[] = {"000000000000000000000002"};
	char cipher[plaintext_len], cipher_hw[plaintext_len];

	double counter_val[1] = {1};
	char counter[counter_len];
	convert_decimal_to_hex(counter,counter_val);

	chacha(plaintext,key,nonce,counter,cipher);

	convert_decimal_to_hex(counter,counter_val);

	//-------------------Hardware function---------------------
	hls::stream<axis_data> input,output;
	axis_data local_stream;

	//Generating the input for stream from pre-defined data types
	for(int i = 0; i < plaintext_len; i++){
		local_stream.data = plaintext[i];
		if(i == plaintext_len-1){
			local_stream.last = 1;
		}
		else{
			local_stream.last = 0;
		}
		input.write(local_stream);
	}

	for(int i = 0; i < key_len; i++){
		local_stream.data = key[i];
		if(i == key_len-1){
			local_stream.last = 1;
		}
		else{
			local_stream.last = 0;
		}
		input.write(local_stream);
	}

	for(int i = 0; i < nonce_len; i++){
		local_stream.data = nonce[i];
		if(i == plaintext_len-1){
			local_stream.last = 1;
		}
		else{
			local_stream.last = 0;
		}
		input.write(local_stream);
	}

	for(int i = 0; i < counter_len; i++){
		local_stream.data = counter[i];
		if(i == plaintext_len-1){
			local_stream.last = 1;
		}
		else{
			local_stream.last = 0;
		}
		input.write(local_stream);
	}

	//calling the hardware function
	chacha_hw(input,output);

	// converting the output received from the stream to per-defined data type
	for(int i = 0; i < plaintext_len; i++){
		local_stream=output.read();
		cipher_hw[i]=local_stream.data;
	}

	//Comparing the output from the PS (software) and PL (FPGA)
	for(int i=0;i<plaintext_len;i++){
		printf("%c",cipher_hw[i]);
		if(cipher[i]!=cipher_hw[i]){
			printf("Error\n");
		}
	}
	printf("No Error\n");
	return 0;
}

void chacha(M_TYPE plaintext[plaintext_len],M_TYPE key[key_len],M_TYPE nonce[nonce_len],M_TYPE counter[counter_len],M_TYPE cipher[plaintext_len]){
	int len = plaintext_len;
    int n_blocks = len / 128;
    int remain = len % 128;

    if(remain != 0){
        n_blocks += 1;
    }

	double counter_val_arr[1];

	convert_hex_to_decimal(counter,counter_val_arr);

    int counter_val = (int)(counter_val_arr[0]);

    for(int a = 0; a < n_blocks; a++){
        char state_matrix[dim1][dim2][dim3] = {{"61707865","3320646e" ,"79622d32" ,"6b206574"},{},{},{}};

        char key_arr[8][8];
        split(key,key_arr,8);

        char nonce_arr[3][8];
        split(nonce,nonce_arr,3);

        int count = 0;
        for(int i = 1; i <= 2; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 8; k++){
                    state_matrix[i][j][k] = key_arr[count][k];
                }
                count+=1;
            }
        }

        count = 0;
        for(int j = 1; j < 4; j++){
            for(int k = 0; k < 8; k++){
                state_matrix[3][j][k] = nonce_arr[count][k];
            }
            count+=1;
        }

        double arr1[1];
        arr1[0] = (double)counter_val;
        convert_decimal_to_hex(counter,arr1);

        for(int k = 0; k < 8; k++){
            state_matrix[3][0][k] = counter[k];
        }

        char copy_state_matrix[4][4][9];

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 8; k++){
                    copy_state_matrix[i][j][k] = state_matrix[i][j][k];
                }
            }
        }

        for(int i = 0; i < 10; i++){
            quarterround(state_matrix,0,4,8,12);
            quarterround(state_matrix,1,5,9,13);
            quarterround(state_matrix,2,6,10,14);
            quarterround(state_matrix,3,7,11,15);
            quarterround(state_matrix,0,5,10,15);
            quarterround(state_matrix,1,6,11,12);
            quarterround(state_matrix,2,7,8,13);
            quarterround(state_matrix,3,4,9,14);
        }

        for(int i = 0; i < 16; i++){
            add_2(state_matrix,copy_state_matrix,i);
        }

        if(a!=n_blocks-1){
            split_2(state_matrix,cipher,a*128,remain,0);
        }
        else{
            split_2(state_matrix,cipher,a*128,remain,1);
        }

        counter_val++;

    }

    for(int i = 0; i < len; i++){
        xor_2(cipher,plaintext,i);
    }
}
