/* Ov022_PickComboPhase -- decide which combo phase the frame's input opens.
 *
 * Nothing happens outside the combo state's active window. Without flag bit 2:
 * pending action 1 opens phase 1 through the current lock's descriptor (when
 * the charge mode is 1 only a descriptor with a negative limit does); button
 * bit 11 opens phase 2 when the slot rule 0x32 and the slot block agree, or
 * through the alternate lock's descriptor the same way, and marks flag-2 bit
 * 53 for the local player; pending action 4 opens phase 3 when the reaction
 * context allows the latched action and the animation request is idle, else
 * marks flag-2 bit 55 for the local player.
 *
 * Then button bit 1, unless flag bit 36 and flag-2 bit 7 are both up: with the
 * combo state open and input bit 2, slot rule 0x31 opens phase 4; without
 * input bit 2, a ready reaction block and slot rule 0x33 open phase 5.
 */

/* Ov022ComboRecord */

#include "nitro/types.h"

struct ComboRecord {
    u8 pad00[0x24];
    int nLimit;                  /* 0x24 negative: no limit */
};

/* Ov022ComboLock */
struct ComboLock {
    u8 pad00[0x14];
    struct ComboRecord *pRecord; /* 0x14 */
};

/* Ov022ComboState: the actor's combo block at 0x910 */
struct ComboState {
    u32 nFlags;                  /* 0x000 */
    u8 pad004[0x478];
    int nPhase;                  /* 0x47c */
};

/* Ov022Actor */
struct Actor {
    u64 nFlags;                  /* 0x0000 */
    u8 pad0008[1];
    u8 nId;                      /* 0x0009 */
    u8 pad000a[0xe];
    u16 nButtons;                /* 0x0018 */
    u8 pad001a[2];
    u16 nPendingAction;          /* 0x001c */
    u8 pad001e[6];
    u32 nInputMask;              /* 0x0024 */
    u8 pad0028[0x43c];
    u64 nFlags2;                 /* 0x0464 */
    u8 pad046c[0x72];
    u16 nLatchedArg;             /* 0x04de */
    u8 pad04e0[0x2d0];
    int nAnimFrame;              /* 0x07b0 */
    u8 pad07b4[0x15c];
    struct ComboState combo;     /* 0x0910 */
    u8 animReq[0x10];            /* 0x0d90 */
    u8 pad0da0[0x2d0];
    u8 slotBlk[0x128];           /* 0x1070 */
    u8 reactBlk[0x10f0];         /* 0x1198 */
    u8 reactionCtx[0x70];        /* 0x2288 */
};

#define FLAG_BIT2 (1ULL << 2)
#define FLAG_BIT36 (1ULL << 36)
#define FLAG2_BIT7 (1ULL << 7)
#define FLAG2_BIT53 (1ULL << 53)
#define FLAG2_BIT55 (1ULL << 55)
#define BUTTON_BIT1 0x2
#define BUTTON_BIT11 0x800
#define INPUT_BIT2 0x4
#define ACTION_1 1
#define ACTION_4 4
#define CHARGE_MODE_1 1
#define RULE_PHASE4 0x31
#define RULE_PHASE2 0x32
#define RULE_PHASE5 0x33

extern int Ov022_IsFrameInComboWindow(struct ComboState *pCombo, int nFrame);
extern struct ComboLock *Ov022_PickComboLockA(struct ComboState *pCombo);
extern struct ComboLock *Ov022_PickComboLockB(struct ComboState *pCombo);
extern void *Ov022_ComboStateOpenOrSelf(struct ComboState *pCombo);
extern int Ov022_GetByte2770(struct Actor *pActor);
extern int Slot_EvalPackedParam(int nId, int nRule);
extern int Ov022_IsBit0Set(u8 *pSlotBlk);
extern int Ov022_IsBit0Set_3(u8 *pReactBlk);
extern int Session_GetLocalPlayerIndex(void);
extern int Ov022_IsSlotActionAllowed(u8 *pCtx, int nAction);
extern int Ov022_IsByte8ZeroOr3(u8 *pAnimReq);

void Ov022_PickComboPhase(struct Actor *pActor)
{
    struct ComboLock *pLock;
    int bOpen;

    if (Ov022_IsFrameInComboWindow(&pActor->combo, pActor->nAnimFrame) == 0) {
        return;
    }
    if ((pActor->nFlags & FLAG_BIT2) == 0) {
        if (pActor->nPendingAction == ACTION_1) {
            pLock = Ov022_PickComboLockA(&pActor->combo);
            if (pLock != 0) {
                if (Ov022_GetByte2770(pActor) == CHARGE_MODE_1) {
                    if (pLock->pRecord->nLimit < 0) {
                        pActor->combo.nPhase = 1;
                    }
                } else {
                    pActor->combo.nPhase = 1;
                }
            }
        }
        if ((pActor->nButtons & BUTTON_BIT11) == BUTTON_BIT11) {
            bOpen = 0;
            if (Slot_EvalPackedParam(pActor->nId, RULE_PHASE2) != 0
                && Ov022_IsBit0Set(pActor->slotBlk) != 0) {
                bOpen = 1;
            }
            pLock = Ov022_PickComboLockB(&pActor->combo);
            if (pLock != 0) {
                if (Ov022_GetByte2770(pActor) == CHARGE_MODE_1) {
                    if (pLock->pRecord->nLimit < 0) {
                        bOpen = 1;
                    }
                } else {
                    bOpen = 1;
                }
            }
            if (bOpen) {
                pActor->combo.nPhase = 2;
                if (Session_GetLocalPlayerIndex() == 0) {
                    pActor->nFlags2 |= FLAG2_BIT53;
                }
            }
        }
        if (pActor->nPendingAction == ACTION_4) {
            if (Ov022_IsSlotActionAllowed(pActor->reactionCtx, pActor->nLatchedArg) != 0
                && Ov022_IsByte8ZeroOr3(pActor->animReq) != 0) {
                pActor->combo.nPhase = 3;
            } else if (Session_GetLocalPlayerIndex() == 0) {
                pActor->nFlags2 |= FLAG2_BIT55;
            }
        }
    }
    if ((pActor->nButtons & BUTTON_BIT1) != BUTTON_BIT1) {
        return;
    }
    if ((pActor->nFlags & FLAG_BIT36) != 0 && (pActor->nFlags2 & FLAG2_BIT7) != 0) {
        return;
    }
    if (Ov022_ComboStateOpenOrSelf(&pActor->combo) != 0 && (pActor->nInputMask & INPUT_BIT2) != 0) {
        if (Slot_EvalPackedParam(pActor->nId, RULE_PHASE4) != 0) {
            pActor->combo.nPhase = 4;
        }
        return;
    }
    if ((pActor->nInputMask & INPUT_BIT2) != 0) {
        return;
    }
    if (Ov022_IsBit0Set_3(pActor->reactBlk) != 0
        && Slot_EvalPackedParam(pActor->nId, RULE_PHASE5) != 0) {
        pActor->combo.nPhase = 5;
    }
}
