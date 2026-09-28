

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
extern void * NNSi_AllocFromHeadOfExpHeap (NNSiFndFrmHeapHead * pFrmHeapHd, u32 size, int alignment);

/* NNS_FndRecordStateForFrmHeap -- NitroSystem frameheap.c: NNS_FndRecordStateForFrmHeap. */
BOOL NNS_FndRecordStateForFrmHeap (NNSFndHeapHandle heap, u32 tagName)
{

    {
        NNSiFndFrmHeapHead * pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead(heap);
        void * oldHeadAllocator = pFrmHeapHd->headAllocator;

        NNSiFndFrmHeapState * pState = NNSi_AllocFromHeadOfExpHeap(pFrmHeapHd, sizeof(NNSiFndFrmHeapState), MIN_ALIGNMENT);
        if (!pState) {
            return FALSE;
        }

        pState->tagName = tagName;
        pState->headAllocator = oldHeadAllocator;
        pState->tailAllocator = pFrmHeapHd->tailAllocator;
        pState->pPrevState = pFrmHeapHd->pState;

        pFrmHeapHd->pState = pState;

        return TRUE;
    }
}
