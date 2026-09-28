/* Flush the queued scene requests. Does nothing unless the dirty bit at +0x48 is
 * set; clearing it, replaying request 0x32 and then acknowledging one request per
 * queued pair, counting up from 50000. The queue length is reset to zero.
 */

#include "nitro/types.h"

typedef struct {
    u8 pad0000[0x3c];
    int nQueued;                /* +0x3c */
    u8 pad0040[8];
    unsigned bDirty : 1;        /* +0x48 bit 0 */
} Ov002SceneContext;

extern Ov002SceneContext *data_ov002_0207f618;

extern int Ov002_ForwardToSubDc(int nId);
extern void Ov002_ForwardToSubDc_2(int nEntry);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_2(int nEntry, int nFlag);

void Ov002_FlushQueuedRequests(void) {
    Ov002SceneContext *ctx = data_ov002_0207f618;
    int nPairs;
    int i;

    if (ctx->bDirty) {
        ctx->bDirty = 0;
        Ov002_ForwardToSubDc_2(Ov002_ForwardToSubDc(0x32));

        nPairs = (ctx->nQueued + 1) / 2;
        for (i = 0; i < nPairs; i++) {
            Ov002_Ctx_SetTagTrackerNodeArmed_2(
                Ov002_ForwardToSubDc((unsigned short)(i + 50000)), 1);
        }

        ctx->nQueued = 0;
    }
}
