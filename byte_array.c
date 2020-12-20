
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    uint8_t value[8];
    uint8_t script_length[1];
    uint8_t script_public_key[25];
} txn_output;

typedef struct
{
    uint8_t previous_txn_hash[32];
    uint8_t previous_output_index[4];
    uint8_t script_length[1];
    uint8_t script_public_key[25];
    uint8_t sequence[4];
} unsigned_txn_input;


typedef struct
{
    uint8_t network_version[4];
    uint8_t input_count[1];
    unsigned_txn_input* input;
    uint8_t output_count[1];
    txn_output* output;
    uint8_t locktime[4];
    uint8_t sighash[4];

} unsigned_txn;



int main(){

const char *received_unsigned_txn_string = "0200000001748dccb662fd73e8f0d8435132b8528dd3739f55388a15795c7e7afe4f555f9f010000001976a9140ce400ffe51ab038f6134beeb14ef56c683ce00088acfdffffff02204e0000000000001976a914d46d05e6ac27683aa5d63a6efc44969798acf13688ac28b30000000000001976a914dacc24d8b195ce046a40caedd5e2e649beee4e3388ac49211a0001000000";

size_t len = strlen(received_unsigned_txn_string);
    // IF_ASSERT(len % 2 != 0)
    //     return NULL;
    size_t final_len = len / 2;
    unsigned char* chrs = (unsigned char*)malloc((final_len+1) * sizeof(*chrs));
    for (size_t i=0, j=0; j<final_len; i+=2, j++)
        chrs[j] = (received_unsigned_txn_string[i] % 32 + 9) % 25 * 16 + (received_unsigned_txn_string[i+1] % 32 + 9) % 25;
    chrs[final_len] = '\0';


    for(size_t i =0 ;i<final_len ; i++){
        printf("%02X",(int)chrs[i]);
    }
    printf("\n");


     unsigned_txn *msg;

    msg =malloc(sizeof( msg));

    memcpy(msg ,chrs, sizeof( msg));

    
	printf("%02X ",msg->network_version);
	printf("\n");

    printf("%02X ",msg->input_count);
	printf("\n");

    printf("%p ",msg-> input);
	printf("\n");

    printf("%02X ",msg->output_count);
	printf("\n");

    printf("%p ",msg->output);
	printf("\n");


    printf("%02X ",msg-> locktime);
	printf("\n");

    printf("%02X ",msg-> sighash);
	printf("\n");
  




}

