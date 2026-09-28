/*
 * Ov002_PollPageTouches - read every slot's touch and route it.
 *
 * Each of the four slots is read in turn. A touch inside the board goes to the
 * page under it, and a slot other than the local one that still holds something
 * marks the board as changed; a touch outside the board, or on a slot with
 * nothing to report, releases whatever that slot was holding.
 *
 * Whatever was read is kept as the slot's last touch, so the next pass can tell
 * a press from a hold.
 *
 * ARM.
 */

#include "nitro/types.h"

typedef struct {
    u16 wX;
    u16 wY;
    u16 wButtons;
    char pad006[2];
} Ov002TouchInput;

typedef struct {
    char pad000[4];
    int nSlot;
    char pad008[0xc];
    int bDirty;
    int aFlags[4];
} Ov002TabCtx;

typedef struct {
    char pad000[0xc];
    char aLast[4];
    u16 wButtons;
    char pad012[2];
} Ov002TabSlot;

extern Ov002TabCtx *data_ov002_0207f99c;
extern Ov002TabSlot data_ov002_0207f9a0[];

extern void MI_CpuCopy8(const void *pSrc, void *pDst, unsigned int nSize);
extern int Session_GetLocalPlayerIndex(void);

extern int Ov002_LinkSyncReadPeer(Ov002TouchInput *pOut, u8 nSlot);
extern void Ov002_PlotStroke(int nSlot, Ov002TouchInput *pInput);
extern void Ov002_HandlePageTouch(int nSlot, Ov002TouchInput *pInput);

int Ov002_PollPageTouches(void)
{
    Ov002TabCtx *ctx;
    int i;
    int nOwner;
    Ov002TouchInput input;
    Ov002TabSlot *pSlot;

    ctx = data_ov002_0207f99c;
    nOwner = Session_GetLocalPlayerIndex();
    pSlot = data_ov002_0207f9a0;

    for (i = 0; i < 4; i++) {
        ctx->nSlot = i;
        if (Ov002_LinkSyncReadPeer(&input, (u8)i) != 0) {
            if (input.wX >= 0x18 && input.wX < 0xe8 &&
                input.wY >= 0x20 && input.wY < 0x88) {
                Ov002_PlotStroke(i, &input);
                if (i != nOwner && ctx->aFlags[i] != 0) {
                    ctx->bDirty = 1;
                }
            } else {
                Ov002_HandlePageTouch(i, &input);
                ctx->aFlags[i] = 0;
            }
            MI_CpuCopy8(&input, pSlot->aLast, 8);
        } else {
            ctx->aFlags[i] = 0;
            pSlot->wButtons = 0;
        }
        pSlot++;
    }
    return 0;
}
