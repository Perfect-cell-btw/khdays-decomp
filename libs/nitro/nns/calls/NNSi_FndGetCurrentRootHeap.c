
#include "nitro/types.h"

extern u32 *data_0204c058[];

void *NNSi_FndGetCurrentRootHeap(void)
{
    return (void *)data_0204c058[1][8];
}
