

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

void NNS_FndDestroyFrmHeap(NNSFndHeapHandle heap);
void NNS_SndHeapClear(NNSSndHeapHandle heap);
extern void NNS_SndHeapClear (NNSSndHeapHandle heap);

/* NNS_SndHeapDestroy -- NitroSystem heap.c: NNS_SndHeapDestroy. */
void NNS_SndHeapDestroy (NNSSndHeapHandle heap)
{

    NNS_SndHeapClear(heap);
    NNS_FndDestroyFrmHeap(heap->handle);
}
