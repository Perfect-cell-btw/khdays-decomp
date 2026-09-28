#include "nitro/types.h"

/* One twelve-byte spawn request as it arrives from the session. */
typedef struct Ov002SpawnRequest {
    u8 nOp;
    char pad001[1];
    s16 nId;
    s16 nSub;
    s16 nX;
    s16 nY;
    s16 nZ;
} Ov002SpawnRequest;

extern char *data_ov002_0207fa00;

extern int Session_GetLocalPlayerIndex(void);
extern unsigned int Ov002_BuildSessionCommand(int nOp, Ov002SpawnRequest *pRequest);
extern void *NNSi_FndAllocFromDefaultExpHeap(int nSize);
extern void MI_CpuCopy8(const void *pSrc, void *pDst, unsigned int nSize);
extern void Slot_Spawn(int nId, int nSub, int *pPos, int nFlag);

/* Run one spawn request: either spawn it here, or hand it to the session.
 *
 * Any op but 0x18 spawns straight away, the three coordinates scaled up by
 * sixteen into a position triple. Op 0x18 goes to the session instead, under
 * an op that depends on whether this console holds the first seat. If the
 * session answers 0xffff the request is kept, copied into a fresh twelve byte
 * block hung off the context.
 */
void Ov002_HandleSpawnRequest(Ov002SpawnRequest *pRequest)
{
    char *pCtx;
    int nOp;
    int aPos[3];

    pCtx = data_ov002_0207fa00;
    if (pRequest->nOp == 0x18) {
        if (Session_GetLocalPlayerIndex() == 0) {
            nOp = 0x17;
        } else {
            nOp = 0x18;
        }
        if (Ov002_BuildSessionCommand(nOp, pRequest) != 0xffff) {
            return;
        }
        if (*(void **)(pCtx + 0x8dbc) == 0) {
            return;
        }
        *(void **)(pCtx + 0x8dbc) = NNSi_FndAllocFromDefaultExpHeap(0xc);
        MI_CpuCopy8(pRequest, *(void **)(pCtx + 0x8dbc), 0xc);
    } else {
        aPos[0] = pRequest->nX << 4;
        aPos[1] = pRequest->nY << 4;
        aPos[2] = pRequest->nZ << 4;
        Slot_Spawn(pRequest->nId, pRequest->nSub, aPos, 0);
    }
}
