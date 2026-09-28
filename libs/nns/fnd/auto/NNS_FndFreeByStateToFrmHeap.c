

#include "nitro/types.h"
#include "nitro/mi.h"
#include "nitro/os.h"
#include "nnsys/fnd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

typedef u32 NNSiUIntPtr;
inline NNSiUIntPtr NNSiGetUIntPtr(const void* ptr)
{
    return (NNSiUIntPtr)ptr;
}
inline void* AddU32ToPtr(void* ptr, u32 val)
{
    return (void*)( NNSiGetUIntPtr(ptr) + val );
}
static inline NNSiFndFrmHeapHead * GetFrmHeapHeadPtrFromHeapHead (NNSiFndHeapHead * pHHead)
{
    return AddU32ToPtr(pHHead, sizeof(NNSiFndHeapHead));
}

/* NNS_FndFreeByStateToFrmHeap -- NitroSystem frameheap.c: NNS_FndFreeByStateToFrmHeap. */
BOOL NNS_FndFreeByStateToFrmHeap (NNSFndHeapHandle heap, u32 tagName)
{

    {
        NNSiFndFrmHeapHead * pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead(heap);
        NNSiFndFrmHeapState * pState = pFrmHeapHd->pState;

        if (tagName != 0) {
            for (; pState; pState = pState->pPrevState)
            {
                if (pState->tagName == tagName)
                    break;
            }
        }

        if (!pState) {
            return FALSE;
        }

        pFrmHeapHd->headAllocator = pState->headAllocator;
        pFrmHeapHd->tailAllocator = pState->tailAllocator;

        pFrmHeapHd->pState = pState->pPrevState;

        return TRUE;
    }
}
