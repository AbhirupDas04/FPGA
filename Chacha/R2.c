#include <stdio.h>
#include <stdint.h>

//Test Case 1
// uint32_t key[8] = {0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000};   //8*32=256 bits keys 
// uint32_t nonce[3]= {0x00000000,0x00000000,0x00000000}  ;        //Nonce
// uint32_t counter = 0x00000000;      //counter
// uint32_t plaintext[BLOCK][16]={0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000};

// Test Case 2
// uint32_t key[8] = {0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000};   //8*32=256 bits keys 
// uint32_t nonce[3]= {0x00000000,0x00000000,0x00000000}  ;        //Nonce
// uint32_t counter = 0x00000001;      //counter
// uint32_t plaintext[BLOCK][16]={0x4c616469,0x65732061,0x6e642047,0x656e746c,0x656d656e,0x206f6620,0x74686520,0x636c6173,0x73206f66,0x20273939,0x3a204966,0x20492063,0x6f756c64,0x206f6666,0x65722079,0x6f75206f};

//Test Case 3
// uint32_t key[8] = {0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000001};   //8*32=256 bits keys 
// uint32_t nonce[3]= {0x00000000,0x00000000,0x00000000}  ;        //Nonce
// uint32_t counter = 0x00000001;      //counter
// uint32_t plaintext[BLOCK][16]={0x4c616469,0x65732061,0x6e642047,0x656e746c,0x656d656e,0x206f6620,0x74686520,0x636c6173,0x73206f66,0x20273939,0x3a204966,0x20492063,0x6f756c64,0x206f6666,0x65722079,0x6f75206f};
//observation -> In third case I observed 00 if present in LSB of big endian it will not be reflected in the 

//Test Case 4
// uint32_t key[8] = {0x00ff0000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000};   //8*32=256 bits keys 
// uint32_t nonce[3]= {0x00000000,0x00000000,0x00000000}  ;        //Nonce
// uint32_t counter = 0x00000002;      //counter
// uint32_t plaintext[BLOCK][16]={0x4c616469,0x65732061,0x6e642047,0x656e746c,0x656d656e,0x206f6620,0x74686520,0x636c6173,0x73206f66,0x20273939,0x3a204966,0x20492063,0x6f756c64,0x206f6666,0x65722079,0x6f75206f};


//Test Case 5
// uint32_t key[8] = {0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000};   //8*32=256 bits keys 
// uint32_t nonce[3]= {0x00000000,0x00000000,0x00000002}  ;        //Nonce
// uint32_t counter = 0x00000000;      //counter
// uint32_t plaintext[BLOCK][16]={0x4c616469,0x65732061,0x6e642047,0x656e746c,0x656d656e,0x206f6620,0x74686520,0x636c6173,0x73206f66,0x20273939,0x3a204966,0x20492063,0x6f756c64,0x206f6666,0x65722079,0x6f75206f};

//Test Case 6  ->Example used in RFC page no.9  //Getting Garbage value beyond valid keystream
// uint32_t key[8] = {0x03020100,0x07060504,0x0b0a0908,0x0f0e0d0c,0x13121110,0x17161514,0x1b1a1918,0x1f1e1d1c};   //8*32=256 bits keys 
// uint32_t key[8] = {0x00010203,0x04050607,0x08090a0b,0x0c0d0e0f,0x10111213,0x14151617,0x18191a1b,0x1c1d1e1f};   //8*32=256 bits keys 
// uint32_t nonce[3]= {0x00000000,0x0000004a,0x00000000}  ;        //Nonce
// uint32_t counter = 0x00000001;      //counter
// uint32_t plaintext[BLOCK][16]={{0x4c616469,0x65732061,0x6e642047,0x656e746c,0x656d656e,0x206f6620,0x74686520,0x636c6173,0x73206f66,0x20273939,0x3a204966,0x20492063,0x6f756c64,0x206f6666,0x65722079,0x6f75206f},{0x6e6c7920,0x6f6e6520,0x74697020,0x666f7220,0x74686520,0x66757475,0x72652c20,0x73756e73,0x63726565,0x6e20776f,0x756c6420,0x62652069,0x742e0000 }};



//Test Case 1   For Cipher Text
// uint32_t key[8] = {0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000};   //8*32=256 bits keys 
// uint32_t nonce[3]= {0x00000000,0x00000000,0x00000000}  ;        //Nonce
// uint32_t counter = 0x00000000;      //counter
// uint32_t plaintext[BLOCK][16]={0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000};

//Test Case 2 For cipher text





// Test Case 3   For Cipher Text  //Getting Garabage value beyond valid cipher text
uint32_t key[8] = {0x1c9240a5,0xeb55d38a,0xf3338886,0x04f6b5f0,0x473917c1,0x402b8009,0x9dca5cbc,0x207075c0};   //8*32=256 bits keys 
uint32_t nonce[3]= {0x00000000,0x00000000,0x00000002}  ;        //Nonce
uint32_t counter = 42;      //counter
uint32_t plaintext[][16]={{0x27547761,0x73206272,0x696c6c69,0x672c2061,0x6e642074,0x68652073,0x6c697468,0x7920746f,0x7665730a,0x44696420,0x67797265,0x20616e64,0x2067696d,0x626c6520,0x696e2074,0x68652077},{0x6162653a,0x0a416c6c,0x206d696d,0x73792077,0x65726520,0x74686520,0x626f726f,0x676f7665,0x732c0a41,0x6e642074,0x6865206d,0x6f6d6520,0x72617468,0x73206f75,0x74677261,0x62652e}};  //  0x62652e00 Last value 00 is appended for padding purpose

// uint8_t plaintext[BLOCK][]={0x27,}

// uint32_t key[8] = {0x03020100,0x07060504,0x0b0a0908,0x0f0e0d0c,0x13121110,0x17161514,0x1b1a1918,0x1f1e1d1c};   //8*32=256 bits keys 

#include <stdio.h>
#include <stdint.h>

void split(uint32_t key[],uint32_t n){
    uint32_t temp1;
    uint32_t temp2;
    uint32_t temp3;

    for(uint32_t i = 0; i < n; i++){
        temp1 = key[i] << 24;
        
        temp2 = key[i] << 16;
        temp2 = temp2 >> 24;
        temp2 = temp2 << 16;

        temp3 = key[i] << 8;
        temp3 = temp3 >> 24;
        temp3 = temp3 << 8;

        key[i] = key[i] >> 24;

        key[i] = key[i] + temp1 + temp2 + temp3;
    }
}

void main(){
    // split(key,8);
    // for(uint32_t i = 0; i < 8; i++){
    //     printf("%08x\n",key[i]);
    // }

    // uint32_t a = 16;
    // printf("%d",a^=16);

    printf("%u %u",0x61717765, 0xff00);
}
