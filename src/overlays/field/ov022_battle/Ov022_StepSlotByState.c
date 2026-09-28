/* Ov022_StepSlotByState -- drive one slot forward by a frame of time.
 *
 * The counterpart of the reaction driver for the kinds whose states are whole
 * routines of their own: the timer takes the frame's delta and the state picks
 * which one runs.
 *
 *   0  finished -- report it and let the caller retire the slot
 *   1  2  3  each hand off to their own step
 *   4  wait: it ends on the next input, or once the timer passes the hold
 *
 * Returns whether the slot has finished this frame.
 */

#include "nitro/types.h"

#define WAIT_HOLD 0x3000

/* Ov022ActorSlot */
struct ActorSlot {
    u8 pad000[2];
    u8 nSeq;                     /* 0x002 */
    u8 pad003[0x115];
    u8 nState;                   /* 0x118 */
    u8 pad119[3];
    int nTimer;                  /* 0x11c */
};

/* Ov022ReactionCtx */
struct ReactionCtx {
    u8 pad00[0xc];
    int nSlot;                   /* 0x0c */
    u8 pad10[8];
    struct ActorSlot *aSlots[11];/* 0x18 */
};

extern void func_ov022_0208cbf8(struct ReactionCtx *pCtx, int nDelta);
extern void Ov022_StepSlotState2(struct ReactionCtx *pCtx, int nDelta);
extern void Ov022_StepSlotState3(struct ReactionCtx *pCtx, int nDelta);
extern int Session_IsReady(void);

int Ov022_StepSlotByState(struct ReactionCtx *pCtx, int nDelta)
{
    struct ActorSlot *pSlot;
    int bDone;

    pSlot = pCtx->aSlots[pCtx->nSlot];
    bDone = 0;
    pSlot->nTimer += nDelta;
    switch (pSlot->nState) {
    case 0:
        bDone = 1;
        break;
    case 3:
        Ov022_StepSlotState3(pCtx, nDelta);
        break;
    case 1:
        func_ov022_0208cbf8(pCtx, nDelta);
        break;
    case 2:
        Ov022_StepSlotState2(pCtx, nDelta);
        break;
    case 4:
        if (Session_IsReady() != 0) {
            if (pSlot->nTimer >= WAIT_HOLD) {
                bDone = 1;
            }
        } else {
            bDone = 1;
        }
        if (bDone != 0) {
            pSlot->nSeq = pSlot->nSeq - 1;
            pSlot->nState = 0;
        }
        break;
    }
    return bDone;
}
