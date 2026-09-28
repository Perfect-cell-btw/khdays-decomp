

#include "nitro/types.h"
#include "nitro/mi.h"
#include "nitro/os.h"
#include "nnsys/fnd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

extern void NNS_FndResetFrmHeapHead (NNSiFndHeapHead * pHeapHd);
extern void NNS_FndResetFrmHeapTail (NNSiFndHeapHead * pHeapHd);

/* NNS_FndFreeToFrmHeap -- NitroSystem frameheap.c: NNS_FndFreeToFrmHeap. */
void NNS_FndFreeToFrmHeap (NNSFndHeapHandle heap, int mode)
{

    if (mode & NNS_FND_FRMHEAP_FREE_HEAD) {
        NNS_FndResetFrmHeapHead(heap);
    }

    if (mode & NNS_FND_FRMHEAP_FREE_TAIL) {
        NNS_FndResetFrmHeapTail(heap);
    }
}
