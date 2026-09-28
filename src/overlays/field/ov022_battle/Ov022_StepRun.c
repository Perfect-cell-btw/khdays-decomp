/* ov022: the run's state machine, one step per frame.
 *
 * Eleven states drive a run from idle through its wind-up, its active window and
 * its wind-down. Most transitions marshal a state packet out to the other side
 * first and only then move the state on, and several of them wait for that
 * packet to leave the queue before continuing. Whatever the state does, the run
 * always ends the frame by stepping and feeding its sequence entries and by
 * writing the run's cue back into the actor's record.
 */

#include "nitro/types.h"

struct Actor;
typedef void (*PfnState)(struct Actor *pActor);

struct Actor {
    u64 nFlags;                  /* 0x0000 */
    u8 nOwner;                   /* 0x0008 */
    u8 nId;                      /* 0x0009 */
    u8 pad000a[0x45a];
    u64 nFlags2;                 /* 0x0464 */
    u8 pad046c[0x220];
    PfnState pfnState;           /* 0x068c */
};

struct Run {
    u32 nFlags;                  /* 0x0000 */
    int nState;                  /* 0x0004 */
    u8 pad0008[0x31c];
    int nSpare324;               /* 0x0324 */
    struct Actor *pActor;        /* 0x0328 */
    int nTimer;                  /* 0x032c */
    int nElapsed;                /* 0x0330 */
    u8 pad0334[1];
    u8 nCue;                     /* 0x0335 */
    u8 pad0336[2];
    int nWidth;                  /* 0x0338 */
    u16 nMsgId;                  /* 0x033c */
    u8 nSlotMask;                /* 0x033e */
};

/* Per-id actor records, 0x44 bytes each. */
struct Record {
    u8 pad0000[0x33];
    s8 nCue;                     /* 0x0033 */
    u8 pad0034[0x10];
};

extern struct Record data_0204c3d8[];

extern int Session_IsReady(void);
extern int QueryActiveStateOrDelegate(void);
extern int GetGlobalU16At6(void);
extern int MsgQueue_Contains(int nMsgId);
extern int Slot_EvalPackedParam(int nId, int nWhat);
extern void Ov002_Camera_SetMode(int nA, int nB, int nC);
extern void Ov002_OpenConfirmPrompt(int nWidth, int bWide);
extern void Ov002_UpdateScrollThumb(int nTimer, int nWidth, int nExtra);
extern void Ov002_ClosePrompt(int bOn);
/* Interworking veneer for the call above; the run compares its
 * address, so the reference has to go through the veneer. */
extern void Ov022_VeneerTo_Ov002_ClosePrompt(void);
extern int func_ov022_02083f0c(void);
extern void func_ov022_02094730(struct Run *pRun, int nKind);
extern void Ov022_SendPayloadMessage(struct Run *pRun, int nTimer);
extern void func_ov022_02094b40(struct Run *pRun);
extern void Ov022_ClearWordAt8(struct Run *pRun);
extern int Ov022_IsWord0x32cNonNegative(struct Run *pRun);
extern int Ov022_ArePartsDone(struct Run *pRun);
extern int Ov022_IsActionOver(struct Run *pRun);
extern int Ov022_ShouldForceState(struct Run *pRun);
extern int func_ov022_020946e4(struct Run *pRun);
extern void func_ov022_020954f8(struct Run *pRun);
extern int func_ov022_02095618(struct Run *pRun);
extern int Ov022_IsActionBlocked(struct Run *pRun);
extern void Ov022_StepRunSequences(struct Run *pRun, int nDelta);
extern void Ov022_FeedRunSequences(struct Run *pRun);
extern void Ov022_ResetSlotBytes(u8 *pBlk);
extern int func_ov022_020ab350(struct Actor *pActor);

void Ov022_StepRun(struct Run *pRun, int nDelta)
{
    struct Actor *pActor;
    int nState;
    int bBlocked;
    int bReady;
    int bWide;
    int nWidth;
    u32 nCap;
    struct Record *pRec;

    nState = pRun->nState;
    pActor = pRun->pActor;
    switch (nState) {
    case 0:
        if (Session_IsReady() != 0 && Ov022_IsActionBlocked(pRun) == 0) {
            pRun->nState = 1;
            pRun->nTimer = 0;
        }
        break;
    case 1:
        if (Ov022_IsActionBlocked(pRun) != 0) {
            pRun->nState = 0;
        } else {
            pRun->nTimer += nDelta;
            if (pRun->nTimer > 0x3000) {
                pRun->nTimer = 0;
                func_ov022_02094730(pRun, 0);
                pRun->nState = 2;
                pRun->nSlotMask = (u8)(1 << QueryActiveStateOrDelegate());
                func_ov022_02094b40(pRun);
            }
        }
        break;
    case 2:
        pRun->nTimer += nDelta;
        if (Ov022_IsActionBlocked(pRun) != 0) {
            pRun->nFlags |= 2;
        }
        if (MsgQueue_Contains(pRun->nMsgId) == 0) {
            Ov022_ResetSlotBytes((u8 *)pActor + 0xd90);
            pActor->pfnState(pActor);
            pRun->nMsgId = 0xffff;
            pRun->nState = 3;
        }
        break;
    case 3:
        if (Session_IsReady() != 0 && pRun->nTimer < 0) {
            pRun->nTimer += nDelta;
        }
        if (Ov022_IsActionBlocked(pRun) != 0) {
            pRun->nFlags |= 2;
        }
        if (Ov022_ArePartsDone(pRun) != 0) {
            if (Session_IsReady() != 0) {
                if (pRun->nSlotMask == GetGlobalU16At6() && pRun->nTimer >= 0) {
                    Ov022_ClearWordAt8(pRun);
                    if ((pRun->nFlags & 2) != 0) {
                        func_ov022_02094730(pRun, 2);
                        pRun->nState = 7;
                    } else {
                        pRun->nState = 5;
                        pRun->nTimer = 0;
                        pRun->nSpare324 = 0;
                    }
                }
            } else {
                func_ov022_02094730(pRun, 1);
                pRun->nState = 4;
                pRun->nTimer = 0;
                pRun->nSpare324 = 0;
            }
        }
        break;
    case 4:
        if (MsgQueue_Contains(pRun->nMsgId) == 0) {
            pRun->nMsgId = 0xffff;
            pRun->nElapsed = 0;
            pRun->nState = 6;
            Ov022_ClearWordAt8(pRun);
        }
        break;
    case 5:
        bBlocked = Ov022_IsActionBlocked(pRun);
        bReady = Ov022_IsWord0x32cNonNegative(pRun);
        if (bBlocked != 0) {
            func_ov022_02094730(pRun, 2);
            pRun->nState = 7;
        } else if (bReady != 0) {
            func_ov022_02094730(pRun, 3);
            pRun->nTimer = 0;
            pRun->nElapsed = 0;
            pRun->nState = 8;
        } else {
            pRun->nTimer += nDelta;
            Ov022_SendPayloadMessage(pRun, pRun->nTimer);
        }
        break;
    case 6:
        bWide = 0;
        if ((pRun->nFlags & 2) != 0) {
            if ((pRun->nFlags & 0x200) != 0) {
                nCap = Slot_EvalPackedParam(pActor->nId, 0x52) != 0 ? 5 : 3;
                if (pRun->nCue < nCap) {
                    pRun->nCue = pRun->nCue + 1;
                }
            }
            if (pActor->nOwner == QueryActiveStateOrDelegate()
                && (u32)(pActor->nFlags & 0x10000ULL) == 0
                && (pRun->nFlags & 0x200) != 0) {
                Ov002_ClosePrompt((int)Ov022_VeneerTo_Ov002_ClosePrompt == 0);
            }
            pRun->nFlags = 1;
            pRun->nState = 10;
            pRun->nTimer = 0;
        }
        if ((pRun->nFlags & 0x80) != 0) {
            if (pRun->nTimer == 0) {
                if ((pRun->nFlags & 0x100) == 0) {
                    if (pActor->nOwner == QueryActiveStateOrDelegate()) {
                        Ov002_Camera_SetMode(func_ov022_02083f0c(), 6, 0);
                    }
                    pRun->nFlags |= 0x100;
                }
            } else {
                pRun->nFlags &= ~0x80;
            pRun->nFlags &= ~0x100;
                func_ov022_020954f8(pRun);
                if (func_ov022_02095618(pRun) == 2) {
                    bWide = 1;
                }
                nWidth = func_ov022_020946e4(pRun);
                if (pActor->nOwner == QueryActiveStateOrDelegate()
                    && ((u32)pActor->nFlags & 0x10000) == 0) {
                    Ov002_OpenConfirmPrompt(nWidth, bWide);
                }
            }
        }
        if ((pRun->nFlags & 0x100) != 0) {
            pRun->nElapsed += nDelta;
        }
        if ((pRun->nFlags & 0x200) != 0) {
            nWidth = func_ov022_020946e4(pRun);
            if (pActor->nOwner == QueryActiveStateOrDelegate()
                && ((u32)pActor->nFlags & 0x10000) == 0) {
                Ov002_UpdateScrollThumb(pRun->nTimer, nWidth, pRun->nWidth);
            }
        }
        break;
    case 8:
        if (Ov022_ShouldForceState(pRun) != 0) {
            pRun->nFlags |= 0x800;
        }
        bWide = 0;
        if (MsgQueue_Contains(pRun->nMsgId) == 0) {
            if ((pRun->nFlags & 0x800) != 0) {
                func_ov022_02094730(pRun, 2);
                pRun->nState = 7;
            } else if ((pRun->nFlags & 0x200) != 0) {
                pRun->nFlags = pRun->nFlags & ~0x100;
                if (func_ov022_02095618(pRun) == 2) {
                    bWide = 1;
                }
                nWidth = func_ov022_020946e4(pRun);
                if (pActor->nOwner == QueryActiveStateOrDelegate()
                    && ((u32)pActor->nFlags & 0x10000) == 0) {
                    Ov002_OpenConfirmPrompt(nWidth, bWide);
                }
                pRun->nState = 9;
            } else if ((pRun->nFlags & 0x100) == 0) {
                pRun->nFlags |= 0x80;
            } else {
                pRun->nElapsed += nDelta;
            }
        }
        break;
    case 9:
        if (Ov022_IsActionOver(pRun) != 0) {
            func_ov022_02094730(pRun, 2);
            pRun->nState = 7;
            nCap = Slot_EvalPackedParam(pActor->nId, 0x52) != 0 ? 5 : 3;
            if (pRun->nCue < nCap) {
                pRun->nCue = pRun->nCue + 1;
            }
        } else {
            pRun->nTimer += nDelta;
            Ov022_SendPayloadMessage(pRun, pRun->nTimer);
            nWidth = func_ov022_020946e4(pRun);
            if (pActor->nOwner == QueryActiveStateOrDelegate()
                && ((u32)pActor->nFlags & 0x10000) == 0) {
                Ov002_UpdateScrollThumb(pRun->nTimer, nWidth, pRun->nWidth);
            }
        }
        break;
    case 7:
        if (MsgQueue_Contains(pRun->nMsgId) == 0) {
            if (pActor->nOwner == QueryActiveStateOrDelegate()
                && ((u32)pActor->nFlags & 0x10000) == 0
                && (pRun->nFlags & 0x200) != 0) {
                Ov002_ClosePrompt(func_ov022_020ab350(pActor) == 0);
            }
            Ov022_ClearWordAt8(pRun);
            pRun->nMsgId = 0xffff;
            pRun->nFlags = 1;
            pRun->nState = 10;
            pRun->nTimer = 0;
        }
        break;
    case 10:
        if ((pActor->nFlags2 & 0x10000ULL) == 0) {
            pRun->nTimer += nDelta;
            if (pRun->nTimer >= 0xf000) {
                pRun->nState = 0;
            }
        }
        break;
    }
    Ov022_StepRunSequences(pRun, nDelta);
    Ov022_FeedRunSequences(pRun);
    pRec = &data_0204c3d8[pActor->nId];
    pRec->nCue = pRun->nCue;
}
