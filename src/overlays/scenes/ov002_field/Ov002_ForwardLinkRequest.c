
/* One eight-byte link request as it arrives from the session. */

#include "nitro/types.h"

typedef struct Ov002LinkRequest {
    u8 nOp;
    char pad001[1];
    u16 nHandle;
    u8 nKind;
    char pad005[1];
    s16 nTag;
} Ov002LinkRequest;

extern char *data_ov002_0207fa00;

extern int Ov002_PublishStateChange(int nHandle, int nKind, int nTag);
extern void GameState_SetField(int nHandle, int nKind, unsigned int nTag);
extern void *NNSi_FndAllocFromDefaultExpHeap(int nSize);
extern void MI_CpuCopy8(const void *pSrc, void *pDst, unsigned int nSize);

void Ov002_ForwardLinkRequest(Ov002LinkRequest *pRequest)
{
    char *pCtx;
    u16 nHandle;
    u8 nKind;
    s16 nTag;

    pCtx = data_ov002_0207fa00;
    nHandle = pRequest->nHandle;
    nTag = pRequest->nTag;
    nKind = pRequest->nKind;

    if (pRequest->nOp == 0x15) {
        if (Ov002_PublishStateChange(nHandle, nKind, nTag) == 0) {
            *(void **)(pCtx + 0x8dbc) = NNSi_FndAllocFromDefaultExpHeap(8);
            MI_CpuCopy8(pRequest, *(void **)(pCtx + 0x8dbc), 8);
            (*(Ov002LinkRequest **)(pCtx + 0x8dbc))->nOp = 0x14;
        }
    } else {
        GameState_SetField(nHandle, nKind, (u16)nTag);
    }
}
