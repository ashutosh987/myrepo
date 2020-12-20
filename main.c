#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "crypto/bip39.h"


#define BIP39_WORDS 2048
#define BIP39_PBKDF2_ROUNDS 2048


int main(){

const char *mnmonic = "garden reject beauty inch scissors rifle amazing couch bacon multiply swim poverty impose spray ugly term stamp prevent nothing mutual awful project wrist movie" ;
const char *mnmonic1;
        // mnemonic_to_seed(mnmonic,mnmonic1);
        printf("%d",mnemonic_find_word(mnmonic));
}