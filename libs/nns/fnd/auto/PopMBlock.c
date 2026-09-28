#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define offsetof(type, member) ((u32)&(((type *)0)->member))

typedef struct NNSiFndUntHeapMBlockHead NNSiFndUntHeapMBlockHead;
struct NNSiFndUntHeapMBlockHead {
    NNSiFndUntHeapMBlockHead * pMBlkHdNext;
};
typedef struct NNSiFndUntMBlockList NNSiFndUntMBlockList;
struct NNSiFndUntMBlockList {
    NNSiFndUntHeapMBlockHead * head;
};

/* PopMBlock -- NitroSystem unitheap.c: PopMBlock. */
NNSiFndUntHeapMBlockHead * PopMBlock (NNSiFndUntMBlockList * list)
{
    NNSiFndUntHeapMBlockHead * block = list->head;

    if (block) {
        list->head = block->pMBlkHdNext;
    }

    return block;
}
