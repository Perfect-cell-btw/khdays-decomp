/* Restart the scene request queue for a new pair of ids. Drains whatever was
 * already queued exactly as the flush does, then raises the dirty bit, latches
 * the two ids at +0xec/+0xee, clears the two progress words and runs the two
 * setup passes. Bit 1 of +0x28 marks the scene as restarted.
 */
#include "nitro/types.h"

typedef struct {
    u8 pad0000[0x28];
    u8 bStateFlags;             /* +0x28 */
    u8 pad0029[0x13];
    int nQueued;                /* +0x3c */
    u8 pad0040[8];
    unsigned bDirty : 1;        /* +0x48 bit 0 */
    u8 pad004c[0xa0];
    u16 wIdLow;                 /* +0xec */
    u16 wIdHigh;                /* +0xee */
    u8 pad00f0[0x54];
    int nProgress144;           /* +0x144 */
    u8 pad0148[0x18];
    int nProgress160;           /* +0x160 */
} Ov002SceneContext;

extern Ov002SceneContext *data_ov002_0207f618;

extern int Ov002_ForwardToSubDc(int nId);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_2(int nEntry, int nFlag);
extern void Ov002_RebuildGaugeGrid(void);
extern void Ov002_RelayoutGaugeRows(void);

void Ov002_RestartRequestQueue(u16 wIdHigh, u16 wIdLow) {
    Ov002SceneContext *ctx = data_ov002_0207f618;
    int i;
    int nPairs;

    nPairs = (ctx->nQueued + 1) / 2;
    for (i = 0; i < nPairs; i++) {
        Ov002_Ctx_SetTagTrackerNodeArmed_2(Ov002_ForwardToSubDc((u16)(i + 50000)), 1);
    }

    ctx->nQueued = 0;
    ctx->bDirty = 1;
    ctx->wIdLow = wIdLow;
    ctx->wIdHigh = wIdHigh;
    ctx->nProgress144 = 0;
    ctx->nProgress160 = 0;

    Ov002_RebuildGaugeGrid();
    Ov002_RelayoutGaugeRows();

    ctx->bStateFlags = ctx->bStateFlags | 2;
}
