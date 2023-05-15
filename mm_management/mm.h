
#define MEMEORY_SIZE(BLOCK_SIZE,NUM_BLOCKS)    (((BLOCK_SIZE)+(sizeof(struct blockHeader_st))) * (NUM_BLOCKS))

struct blockHeader_st {
  struct blockHeader_st *sptr_next;
};

struct memory_st {
    char *memory;
   struct blockHeader_st *sptr_firstBlock;
    int num_Blocks;
    int num_FreeBlocks;
    int block_Size;
};


void mm_Init(struct memory_st *my_pool);
void *mm_allocate(struct memory_st *my_pool);
void mm_free(void *data,struct memory_st *my_pool);
void mm_showStates(struct memory_st *my_pool);