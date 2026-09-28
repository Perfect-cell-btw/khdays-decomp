/* Ov022_DispatchIdleInput -- turn the frame's input into a state change while
 * the actor idles.
 *
 * A held reach block that is not settled, or that refuses the -1 unit test,
 * blocks everything. Without flag bit 2 a pending action is tried (enabled
 * while the reach block counts), then the tail update. With the reaction
 * block clear for the aim mode, button bit 1 in aim mode 1 or 2 opens state
 * 0xd. With the combo block live: an armed reaction, a live aim angle and
 * button-2 bit 11 make an aimed jump (aim flag up, the step rate taken from
 * the jump rate), or button bit 11 in aim mode 1 or 2 a plain one; either
 * clears the recoil under flag bit 36 and opens state 6. Otherwise button-2
 * bit 1 in aim mode 2 with slot rule 0x2e opens state 0x1e, unless the hold
 * byte is up with time left. A change other than pending action 1 while the
 * reach block counts clears the reach timer.
 */

#include "nitro/types.h"

/* Ov022AimState: the aim bytes at actor+0x2bb0 */
struct AimState {
    u8 nAimSlot;                 /* 0x00 */
    u8 bHold;                    /* 0x01 */
    s8 nAimMode;                 /* 0x02 */
};

/* Ov022Actor */
struct Actor {
    u64 nFlags;                  /* 0x0000 */
    u8 pad0008[1];
    u8 nId;                      /* 0x0009 */
    u8 pad000a[0xe];
    u16 nButtons;                /* 0x0018 */
    u16 nButtons2;               /* 0x001a */
    u16 nPendingAction;          /* 0x001c */
    u8 pad001e[0x3a];
    int nRecoil;                 /* 0x0058 */
    u8 pad005c[0x461];
    u8 bAimedJump;               /* 0x04bd */
    u8 pad04be[0x1f6];
    int nStepRate;               /* 0x06b4 */
    int nRecoilDecay;            /* 0x06b8 */
    u8 pad06bc[0xadc];
    u8 reactBlk[0x180];          /* 0x1198 */
    u8 comboBlk[0x958];          /* 0x1318 */
    int nHoldTime;               /* 0x1c70 */
    u8 pad1c74[6];
    short nJumpRate;             /* 0x1c7a */
    u8 pad1c7c[0x10];
    u8 blkReach[0x110];          /* 0x1c8c */
    int nReachTimer;             /* 0x1d9c */
    u8 pad1da0[0xd1c];
    int nAimAngle;               /* 0x2abc */
    u8 pad2ac0[0xf0];
    struct AimState aim;         /* 0x2bb0 */
};

#define FLAG_BIT2 (1ULL << 2)
#define FLAG_BIT36 (1ULL << 36)
#define BUTTON_BIT1 0x2
#define BUTTON_BIT11 0x800
#define BUTTON2_BIT1 0x2
#define BUTTON2_BIT11 0x800
#define AIM_NONE (-1)
#define AIM_MODE_1 1
#define AIM_MODE_2 2
#define REACH_TEST (-0x1000)
#define RULE_WALK 0x2e
#define STATE_AIM 0xd
#define STATE_JUMP 6
#define STATE_WALK 0x1e
#define ACTION_1 1

extern int Ov022_IsBit0Set_5(u8 *pBlk);
extern int func_ov022_02094074(u8 *pBlk);
extern int func_ov022_020940a0(u8 *pBlk, int nArg);
extern int Ov022_IsActiveAndCountPositive(u8 *pBlk);
extern int Ov022_TryPendingAction(struct Actor *pActor, int bEnabled);    /* Ov022_TryPendingAction */
extern int Ov022_UpdateTailState(struct Actor *pActor);                  /* Ov022_UpdateTailState */
extern int func_ov022_02092b10(u8 *pBlk, int nSlot);
extern int Ov022_ActorSetState(struct Actor *pActor, int nState);      /* Ov022_ActorSetState */
extern int Ov022_IsActiveAndCounterZero(u8 *pBlk);
extern int func_ov022_02092dc8(u8 *pBlk, int nArg);
extern int Slot_EvalPackedParam(int nId, int nRule);

int Ov022_DispatchIdleInput(struct Actor *pActor)
{
    int nRet;
    int bEnabled;
    int bAim;
    int bFree;
    struct AimState *pAim;

    pAim = &pActor->aim;
    nRet = 0;
    if (Ov022_IsBit0Set_5(pActor->blkReach) != 0) {
        if (func_ov022_02094074(pActor->blkReach) == 0
            || func_ov022_020940a0(pActor->blkReach, REACH_TEST) == 0) {
            return 0;
        }
    }
    if ((pActor->nFlags & FLAG_BIT2) == 0) {
        bEnabled = 0;
        if (Ov022_IsActiveAndCountPositive(pActor->blkReach) != 0) {
            bEnabled = 1;
        }
        nRet = Ov022_TryPendingAction(pActor, bEnabled);
        if (nRet == 0) {
            nRet = Ov022_UpdateTailState(pActor);
            if (nRet != 0) {
                goto done;
            }
        }
    }
    if (func_ov022_02092b10(pActor->reactBlk, pActor->aim.nAimSlot) != 0) {
        bAim = 0;
        if ((pActor->nButtons & BUTTON_BIT1) == BUTTON_BIT1 && !(pAim->nAimMode != AIM_MODE_1 && pAim->nAimMode != AIM_MODE_2)) {
            bAim = 1;
        }
        if (bAim) {
            nRet = Ov022_ActorSetState(pActor, STATE_AIM);
            if (nRet != 0) {
                goto done;
            }
        }
    }
    if (Ov022_IsActiveAndCounterZero(pActor->comboBlk) != 0) {
        int bJump = 0;
        int bAimed = 0;
        if (func_ov022_02092dc8(pActor->reactBlk, 1) != 0 && pActor->nAimAngle != AIM_NONE
            && (pActor->nButtons2 & BUTTON2_BIT11) != 0) {
            bAimed = 1;
        }
        if (bAimed) {
            bJump = 1;
        } else if ((pActor->nButtons & BUTTON_BIT11) == BUTTON_BIT11) {
            if (!(pAim->nAimMode != AIM_MODE_1 && pAim->nAimMode != AIM_MODE_2)) {
                bJump = 1;
            }
        }
        if (bJump) {
            if (bAimed) {
                pActor->bAimedJump = 1;
                pActor->nStepRate = pActor->nJumpRate;
            }
            if ((pActor->nFlags & FLAG_BIT36) != 0) {
                pActor->nRecoil = 0;
                pActor->nRecoilDecay = 0;
            }
            nRet = Ov022_ActorSetState(pActor, STATE_JUMP);
            if (nRet != 0) {
                goto done;
            }
        }
    }
    if (nRet == 0 && (pActor->nButtons2 & BUTTON2_BIT1) != 0 && pAim->nAimMode == AIM_MODE_2
        && Slot_EvalPackedParam(pActor->nId, RULE_WALK) != 0) {
        bFree = 1;
        if (pAim->bHold != 0 && pActor->nHoldTime > 0) {
            bFree = 0;
        }
        if (bFree) {
            nRet = Ov022_ActorSetState(pActor, STATE_WALK);
        }
    }
done:
    if (nRet != 0 && pActor->nPendingAction != ACTION_1 && Ov022_IsActiveAndCountPositive(pActor->blkReach) != 0) {
        pActor->nReachTimer = 0;
    }
    return nRet;
}
