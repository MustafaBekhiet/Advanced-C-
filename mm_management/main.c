#include<stdio.h>
#include "mm.h"

#define BLOCK_SIZE   16
#define NUM_BLOCK    8


int main(void){

    int block_size; int num_block;
    printf("Enter number of block : ");
    scanf("%d",&num_block);
    printf("Choose block size(4,8,16,32,......) : ");
    scanf("%d",&block_size);
    printf("\n");
    char pool_memory[MEMEORY_SIZE(block_size,num_block)];

    struct memory_st myPOOL = {.memory = pool_memory, .block_Size = block_size, .num_Blocks=num_block};
    mm_Init(&myPOOL);
    mm_showStates(&myPOOL);       
    
    void *data_1 = mm_allocate(&myPOOL);
    mm_showStates(&myPOOL);
    
    void *data_2 = mm_allocate(&myPOOL);
    mm_showStates(&myPOOL);

    mm_free(data_1,&myPOOL);
    mm_showStates(&myPOOL);

    return 0;
}