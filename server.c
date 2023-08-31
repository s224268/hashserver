#include <stdio.h>
#include <string.h>
#include "include/openssl/sha.h"

uint64_t match(unsigned char hash[32], uint64_t start, uint64_t end){

    for (; start<=end; start++){
        unsigned char guess[32];
        SHA256(hash, strlen(hash), guess);
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

    char hexstring[16];
    unsigned char hash[32];
    sprintf(hexstring, "%X", correct);

    printf("%s\n",hexstring);

    //uint64ToHexBuffer(correct, hexstring);
    SHA256(hexstring, strlen(hexstring), hash);
    int j;
    for (j = 0; j < 32; j++) {
        printf("%02x", hash[j]);
    }
    printf("\n");

    match(hash, 23342342, 23342349);

    return 0;
}



