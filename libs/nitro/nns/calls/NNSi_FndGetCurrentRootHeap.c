
#include "nitro/types.h"

extern u32 *gObjSystem[];

void *NNSi_FndGetCurrentRootHeap(void)
{
    return (void *)gObjSystem[1][8];
}
