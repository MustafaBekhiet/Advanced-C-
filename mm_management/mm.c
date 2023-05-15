#include <string.h>
#include<stdio.h>
#include"mm.h"



void mm_Init(struct memory_st *my_pool){
    memset(my_pool->memory,0,MEMEORY_SIZE(my_pool->block_Size,my_pool->num_Blocks));
    my_pool->sptr_firstBlock = (struct blockHeader_st *)(my_pool->memory);
    struct blockHeader_st *Current_Block = my_pool->sptr_firstBlock;    
    int i =0;
    for(;i<my_pool->num_Blocks-1;i++)
    {
        Current_Block->sptr_next = (struct blockHeader_st *)(char *)(Current_Block+1) + my_pool->block_Size;
        Current_Block = Current_Block->sptr_next;
        my_pool->num_FreeBlocks++;
    }
    Current_Block->sptr_next = NULL ;
    my_pool->num_FreeBlocks++;
}
void *mm_allocate(struct memory_st *my_pool){
    void *data = NULL ;
    if(my_pool->num_FreeBlocks>0)
    {
        data = (void *)(char*) my_pool->sptr_firstBlock + sizeof(struct blockHeader_st);
        my_pool->sptr_firstBlock = my_pool->sptr_firstBlock->sptr_next;
        my_pool->num_FreeBlocks--;
    }
    return data;
}
void mm_free(void *data, struct memory_st *my_pool){
   if(my_pool->num_FreeBlocks < my_pool->num_Blocks)
   {
        struct blockHeader_st *Block;
        Block = (struct blockHeader_st *)((char*)data -sizeof(struct blockHeader_st)) ;
        Block->sptr_next = my_pool->sptr_firstBlock;
        my_pool->sptr_firstBlock = Block; 
        my_pool->num_FreeBlocks++;
   }
    
}
void mm_showStates(struct memory_st *my_pool){

   printf("Number of Available Blocks are : %d\n",my_pool->num_FreeBlocks);

   struct blockHeader_st *block = my_pool->sptr_firstBlock;
   while(block != NULL)
   {
    printf("%#p\n",block);
    block = block->sptr_next;
   }
    printf("\n");
}