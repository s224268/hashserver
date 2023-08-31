#include <stdio.h>
#include <string.h>
#include "include/openssl/sha.h"

uint64_t match(uint8_t hash[32], uint64_t start, uint64_t end){

    for (int j = 0; j < 32; j++) {
        printf("%02x", hash[j]);
    }
    printf("\n");

    for(;start<=end; start++){
        char hexstring[16];
        sprintf(hexstring, "%llX", start);
        char guess[32];//Shouldnt this be 16?

        SHA256(hexstring, strlen(hexstring), guess);
        //printf("%s", hash);
        if (strcmp(guess, hash) == 0){
            printf("%llu", start);
            return start;
        }
    }
    return 1;
}

int main()
{
    uint64_t correct = 23342345;

    char hexstring[16]; //It is unclear whether the input should be a char[] or an actual number
    unsigned char hash[32];
    sprintf(hexstring, "%llX", correct);

    printf("%s\n",hexstring);

    //uint64ToHexBuffer(correct, hexstring);
    SHA256(hexstring, strlen(hexstring), hash);

    for (int j = 0; j < 32; j++) {
        printf("%02x", hash[j]);
    }
    printf("\n");

    match(hash, 2334234, 23342349);

    return 0;
}



