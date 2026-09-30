/* Ov022_RollSlotRetreat -- decide whether the actor's player slot should
 * retreat this frame.
 *
 * With the slot's bit 3 up, any of the actor's slot actions 12..14 that has
 * a rule and is allowed by the reaction context drops that bit. The slot is
 * then held back to state 1 (from 5) when it is barred: bit 4 together with
 * bit 2, bits 3 and 5, or charge mode 6; or its cooldown still runs, the
 * game-state flag 0x20e0 is set, or the actor's state block says so. A slot
 * in state 5 that is not barred is given a half unit of cooldown and put back
 * to 1. Otherwise a roll of a hundred (plus ten with slot bit 12, plus ten in
 * charge mode 9) sends the slot to state 5: past 20 when the actor is under
 * a fifth of its member's full health, past 50 when under half.
 */

/* Ov002MissionMemberBody: the member's own stored stat row */

#include "nitro/types.h"

struct StatRow {
    u8 pad00[6];
    u16 nHpMax;                  /* 0x06 */
    u8 pad08[8];
};

/* Ov002MissionMember */
struct MissionMember {
    u8 pad00[8];
    struct StatRow row;          /* 0x08 */
    u8 pad18[0xec];
};

/* PlayerSlot */
struct PlayerSlot {
    int nState;                  /* 0x00 */
    u32 nFlags;                  /* 0x04 */
    u8 pad08[4];
    int nCooldown;               /* 0x0c */
};

/* Ov022Actor */
struct Actor {
    u8 pad0000[9];
    u8 nId;                      /* 0x0009 */
    u8 pad000a[8];
    u16 nHp;                     /* 0x0012 */
    u8 pad0014[0x2274];
    u8 reactionCtx[0x70];        /* 0x2288 */
    u8 stateBlk[0x478];          /* 0x22f8 */
    s8 nChargeMode;              /* 0x2770 */
};

#define SLOT_RETREAT 5
#define SLOT_FOLLOWING 1
#define SLOT_BIT2 0x4
#define SLOT_BIT3 0x8
#define SLOT_BIT4 0x10
#define SLOT_BIT5 0x20
#define SLOT_BIT12 0x1000
#define CHARGE_MODE_6 6
#define CHARGE_MODE_9 9
#define ACTION_FIRST 12
#define ACTION_END 15
#define GAME_FLAG_20E0 0x20e0
#define RETREAT_COOLDOWN 0x2000
#define ROLL_LOW 20
#define ROLL_HALF 50

extern struct MissionMember gPartyMembers[];   /* the mission member table */

extern struct PlayerSlot *GetPlayerSlotTableEntry(int nSlot);
extern int Load2DArrayU8(int nId, int nAction);
extern int func_ov022_0209029c(u8 *pCtx, int nAction);
extern int GameState_IsFlagSet(int nFlag);
extern int Ov022_IsState9Or6WithFlag200(u8 *pBlk);
extern u32 Session_RandNextScaled(int nRange);

void Ov022_RollSlotRetreat(struct Actor *pActor)
{
    struct MissionMember *pMember;
    struct PlayerSlot *pSlot;
    int nAction;
    u32 nRoll;

    pSlot = GetPlayerSlotTableEntry((u8)(pActor->nId - 1));
    pMember = &gPartyMembers[pActor->nId];
    if ((pSlot->nFlags & SLOT_BIT3) != 0) {
        for (nAction = ACTION_FIRST; nAction < ACTION_END; nAction++) {
            if (Load2DArrayU8(pActor->nId, nAction) > 0
                && func_ov022_0209029c(pActor->reactionCtx, nAction) != 0) {
                pSlot->nFlags &= ~SLOT_BIT3;
            }
        }
    }
    if ((((pSlot->nFlags & SLOT_BIT2) != 0
          || ((pSlot->nFlags & SLOT_BIT3) != 0 && (pSlot->nFlags & SLOT_BIT5) != 0)
          || pActor->nChargeMode == CHARGE_MODE_6)
         && (pSlot->nFlags & SLOT_BIT4) != 0)
        || pSlot->nCooldown > 0 || GameState_IsFlagSet(GAME_FLAG_20E0) != 0
        || Ov022_IsState9Or6WithFlag200(pActor->stateBlk) != 0) {
        if (pSlot->nState == SLOT_RETREAT) {
            pSlot->nState = SLOT_FOLLOWING;
        }
        return;
    }
    if (pSlot->nState == SLOT_RETREAT) {
        pSlot->nCooldown = RETREAT_COOLDOWN;
        pSlot->nState = SLOT_FOLLOWING;
        return;
    }
    nRoll = Session_RandNextScaled(100);
    if ((pSlot->nFlags & SLOT_BIT12) != 0) {
        nRoll += 10;
    }
    if (pActor->nChargeMode == CHARGE_MODE_9) {
        nRoll += 10;
    }
    if (pMember->row.nHpMax / 5 > pActor->nHp) {
        if (nRoll > ROLL_LOW) {
            pSlot->nState = SLOT_RETREAT;
        }
    } else if (pActor->nHp < (int)((u32)pMember->row.nHpMax >> 1)) {
        if (nRoll > ROLL_HALF) {
            pSlot->nState = SLOT_RETREAT;
        }
    }
}
