#include <stdio.h>
#include <stdint.h>

void split_2(uint32_t state_matrix[4][4],uint32_t key_stream[][16],uint32_t start,uint32_t remain,uint32_t mode){
    uint32_t temp1;
    uint32_t temp2;
    uint32_t temp3;
    uint32_t temp4;

    uint32_t remain2 = remain % 8;

    for(uint32_t i = 0; i < 4; i++){
        for(uint32_t j = 0; j < 4; j++){
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

void quarterround(uint32_t state_matrix[4][4], uint32_t ind1, uint32_t ind2, uint32_t ind3, uint32_t ind4){
    state_matrix[ind1/4][ind1%4] += state_matrix[ind2/4][ind2%4];
    state_matrix[ind4/4][ind4%4] ^= state_matrix[ind1/4][ind1%4];
    state_matrix[ind4/4][ind4%4] = state_matrix[ind4/4][ind4%4] << 16 | state_matrix[ind4/4][ind4%4] >> 16;

    state_matrix[ind3/4][ind3%4] += state_matrix[ind4/4][ind4%4];
    state_matrix[ind2/4][ind2%4] ^= state_matrix[ind3/4][ind3%4];
    state_matrix[ind2/4][ind2%4] = state_matrix[ind2/4][ind2%4] << 12 | state_matrix[ind2/4][ind2%4] >> 20;

    state_matrix[ind1/4][ind1%4] += state_matrix[ind2/4][ind2%4];
    state_matrix[ind4/4][ind4%4] ^= state_matrix[ind1/4][ind1%4];
    state_matrix[ind4/4][ind4%4] = state_matrix[ind4/4][ind4%4] << 8 | state_matrix[ind4/4][ind4%4] >> 24;

    state_matrix[ind3/4][ind3%4] += state_matrix[ind4/4][ind4%4];
    state_matrix[ind2/4][ind2%4] ^= state_matrix[ind3/4][ind3%4];
    state_matrix[ind2/4][ind2%4] = state_matrix[ind2/4][ind2%4] << 7 | state_matrix[ind2/4][ind2%4] >> 25;
}

// uint32_t key[8] = {0x1c9240a5,0xeb55d38a,0xf3338886,0x04f6b5f0,0x473917c1,0x402b8009,0x9dca5cbc,0x207075c0};
// uint32_t nonce[3]= {0x00000000,0x00000000,0x00000002};
// uint32_t counter_val = 42;
// uint32_t plaintext[][16]={{0x27547761,0x73206272,0x696c6c69,0x672c2061,0x6e642074,0x68652073,0x6c697468,0x7920746f,0x7665730a,0x44696420,0x67797265,0x20616e64,0x2067696d,0x626c6520,0x696e2074,0x68652077},{0x6162653a,0x0a416c6c,0x206d696d,0x73792077,0x65726520,0x74686520,0x626f726f,0x676f7665,0x732c0a41,0x6e642074,0x6865206d,0x6f6d6520,0x72617468,0x73206f75,0x74677261,0x62652e00}};

// uint32_t len = 254;

//Test Case 4
// uint32_t key[8] = {0x00ff0000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000};   //8*32=256 bits keys 
// uint32_t nonce[3]= {0x00000000,0x00000000,0x00000000}  ;        //Nonce
// uint32_t counter_val = 0x00000002;      //counter
// uint32_t plaintext[][16]={0x4c616469,0x65732061,0x6e642047,0x656e746c,0x656d656e,0x206f6620,0x74686520,0x636c6173,0x73206f66,0x20273939,0x3a204966,0x20492063,0x6f756c64,0x206f6666,0x65722079,0x6f75206f};

// uint32_t len = 128;

//Test Case 1   For Cipher Text
uint32_t key[8] = {0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000};   //8*32=256 bits keys 
uint32_t nonce[3]= {0x00000000,0x00000000,0x00000000}  ;        //Nonce
uint32_t counter_val = 0x00000000;      //counter
uint32_t plaintext[][16]={0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000};

uint32_t len = 128;

// uint32_t key[8] = {0x00010203,0x04050607,0x08090a0b,0x0c0d0e0f,0x10111213,0x14151617,0x18191a1b,0x1c1d1e1f};   //8*32=256 bits keys 
// uint32_t nonce[3]= {0x00000009,0x0000004a,0x00000000}  ;        //Nonce
// uint32_t counter_val = 0x00000001;      //counter
// uint32_t plaintext[][16]={{0x4c616469,0x65732061,0x6e642047,0x656e746c,0x656d656e,0x206f6620,0x74686520,0x636c6173,0x73206f66,0x20273939,0x3a204966,0x20492063,0x6f756c64,0x206f6666,0x65722079,0x6f75206f},{0x6e6c7920,0x6f6e6520,0x74697020,0x666f7220,0x74686520,0x66757475,0x72652c20,0x73756e73,0x63726565,0x6e20776f,0x756c6420,0x62652069,0x742e0000 }};

// uint32_t len = 128;

void main(){
    uint32_t n_blocks = len / 128;
    uint32_t remain = len % 128;

    if(remain != 0){
        n_blocks += 1;
    }

    uint32_t keystream[n_blocks][16];

    uint32_t act_state_matrix[4][4] = {{0x61707865,0x3320646e,0x79622d32,0x6b206574},{},{},{0,0,0,0}};
    uint32_t state_matrix[4][4], copy_state_matrix[4][4];

    uint32_t temp1;
    uint32_t temp2;
    uint32_t temp3;

    for(uint32_t j = 1; j < 3; j++){
        for(uint32_t i = 0; i < 4; i++){
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

    for(uint32_t i = 1; i < 4; i++){
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
        act_state_matrix[3][0] = counter_val;

        for(uint32_t i = 0; i < 4; i++){
            for(uint32_t j = 0; j < 4; j++){
                state_matrix[i][j] = act_state_matrix[i][j];
                copy_state_matrix[i][j] = act_state_matrix[i][j];
            }
        }

        // for(uint32_t i = 0; i < 1; i++){
        //     for(uint32_t j = 0; j < 16; j++){
        //         printf("%08x    ",state_matrix[i][j]);

        //         if(j % 4 == 3){
        //             printf("\n");
        //         }
        //     }
        // }

        for(uint32_t i = 0; i < 10; i++){
            quarterround(state_matrix,0,4,8,12);
            quarterround(state_matrix,1,5,9,13);
            quarterround(state_matrix,2,6,10,14);
            quarterround(state_matrix,3,7,11,15);
            quarterround(state_matrix,0,5,10,15);
            quarterround(state_matrix,1,6,11,12);
            quarterround(state_matrix,2,7,8,13);
            quarterround(state_matrix,3,4,9,14);
        }

        for(uint32_t i = 0; i < 4; i++){
            for(uint32_t j = 0; j < 4; j++){
                state_matrix[i][j] += copy_state_matrix[i][j];
            }
        }

        // for(uint32_t i = 0; i < 4; i++){
        //     for(uint32_t j = 0; j < 4; j++){
        //         printf("%08x    ",state_matrix[i][j]);
        //     }
        //     printf("\n");
        // }

        // printf("\n");

        if(a!=n_blocks-1){
            split_2(state_matrix,keystream,a,remain,0);
        }
        else{
            split_2(state_matrix,keystream,a,remain,1);
        }

        // for(uint32_t i = 0; i < 1; i++){
        //     for(uint32_t j = 0; j < 16; j++){
        //         printf("%08x    ",keystream[i][j]);

        //         if(j % 4 == 3){
        //             printf("\n");
        //         }
        //     }
        //     printf("\n\n");
        // }

        counter_val++;

    }

    // for(uint32_t i = 0; i < n_blocks; i++){
    //     for(uint32_t j = 0; j < 16; j++){
    //         printf("%08x    ",keystream[i][j]);

    //         if(j%4 == 3){
    //             printf("\n");
    //         }

    //         if(128*i + 8*j <= len && (128*i + 8*(j+1)) > len){
    //             break;
    //         }
    //     }
    //     printf("\n");
    // }

    uint32_t flag = 0;

    for(uint32_t i = 0; i < n_blocks; i++){
        for(uint32_t j = 0; j < 16; j++){
            keystream[i][j] = keystream[i][j] ^ plaintext[i][j];

            if(128*i + 8*j <= len && (128*i + 8*(j+1)) > len){
                if(remain%8 == 2){
                    keystream[i][j] = keystream[i][j] >> 24;
                }
                if(remain%8 == 4){
                    keystream[i][j] = keystream[i][j] >> 16;
                }
                if(remain%8 == 6){
                    keystream[i][j] = keystream[i][j] >> 8;
                }
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            break;
        }
    }

    // printf("\n\n\n\n\n");

    flag = 0;

    for(uint32_t i = 0; i < n_blocks; i++){
        for(uint32_t j = 0; j < 16; j++){
            if(128*i + 8*j == len){
                flag = 1;
                break;
            }

            if(128*i + 8*j <= len && (128*i + 8*(j+1)) > len){
                printf("%x    ",keystream[i][j]);
            }
            else{
                printf("%08x    ",keystream[i][j]);
            }

            if(j%4 == 3){
                printf("\n");
            }

            if(128*i + 8*j <= len && (128*i + 8*(j+1)) > len){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            break;
        }
        printf("\n");
    }
}