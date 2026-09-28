/* Ov021_PrizeBoxAdvanceFrame -- Ov021_PrizeBoxAdvanceFrame: advance the prize box's animation frame
 * (+0x1b0) by nDelta and play it on pNode (ov002 0207c67c) while the model is bound (bit 2 of
 * +0x12).  Past the last frame (length +0x1b4 minus one frame) a looping animation wraps the
 * frame back by the length, a one-shot one clamps to the last frame and stops advancing.
 * Answers 1 while the animation still runs, 0 once a one-shot has finished.  The prize box is
 * ov021's class-0x11 object: a box holding one prize of a list shuffled across the boxes. */

#include "nitro/types.h"

typedef struct Ov021PrizeBox {
    u8   pad_000[0x12];
    u16  nPieceFlags;         /* 0x012: bit 2 = model bound */
    u8   pad_014[0x1b0 - 0x14];
    int  nMainFrame;          /* 0x1b0 */
    int  nMainLength;         /* 0x1b4 */
} Ov021PrizeBox;

extern void Ov002_SetFrameOnActiveTracks(void *pNode, int nFrame);            /* set the node's frame */

int Ov021_PrizeBoxAdvanceFrame(Ov021PrizeBox *pSelf, void *pNode, int nDelta, int bLoop)
{
    int bDone;
    int nEnd;

    bDone = 0;
    if (bLoop) {
        nEnd = pSelf->nMainLength - 0x1000;
        if (pSelf->nMainFrame > nEnd) {
            pSelf->nMainFrame -= nEnd;
        }
    } else {
        nEnd = pSelf->nMainLength - 0x1000;
        if (pSelf->nMainFrame > nEnd) {
            pSelf->nMainFrame = nEnd;
            bDone = 1;
        }
    }
    if (pSelf->nPieceFlags & 4) {
        Ov002_SetFrameOnActiveTracks(pNode, pSelf->nMainFrame);
    }
    if (!bDone) {
        pSelf->nMainFrame += nDelta;
    }
    return !bDone;
}
