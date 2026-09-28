/* Ov008_BeginSaveToSlot -- Ov008_BeginSaveToSlot: prepare and start a save into
 * slot nSlot.  Copies the 9-bit day counter (field 0) into field 0x452, rolls
 * a random reward tier for the slot (0..2 while the day is below 26, else
 * 0..3) into the slot's entry (+0x28 + 0x1c * slot) and fields 0xc4b (tier) /
 * 0xc98 (slot); bumps the save counter (+0x1ef8) into the two 16-bit halves of
 * fields 0xc77 / 0xc87; latches the two "changed" flags (0x18bd / 0x18c9) into
 * bytes +0x1efc / +0x1efd and clears them; starts the card write, marks card
 * op 3 and returns the write's result (kept live across the store: that is
 * why the constant 3 goes to r1).
 */

#include "nitro/types.h"

typedef struct Ov008SaveTierEntry {
    u32 nTier;                /* +0 (= save entry +0x18) */
    u8  pad_04[0x1c - 0x4];
} Ov008SaveTierEntry;

typedef struct Ov008SaveMenu {
    u8  pad_0000[0x28];
    Ov008SaveTierEntry aTier[3]; /* 0x028: the save entries' reward tier words, stride 0x1c */
    u8  pad_007c[0x238 - 0x7c];
    int nCardOp;              /* 0x238 */
    u8  pad_023c[0x1ef8 - 0x23c];
    u32 nSaveCount;           /* 0x1ef8 */
    u8  bChangedA;            /* 0x1efc */
    u8  bChangedB;            /* 0x1efd */
} Ov008SaveMenu;

#define FIELD_DAY        0
#define FIELD_DAY_COPY   0x452
#define FIELD_TIER       0xc4b
#define FIELD_TIER_SLOT  0xc98
#define FIELD_COUNT_HI   0xc77
#define FIELD_COUNT_LO   0xc87
#define FLAG_CHANGED_A   0x18bd
#define FLAG_CHANGED_B   0x18c9
#define CARD_OP_TRANSFER 3
#define TIER_DAY_SPLIT   26

extern u32  GameState_GetField(int nField, int nBits);                       /* GameState_GetField */
extern void GameState_SetField(int nField, int nBits, int nValue);           /* GameState_SetField */
extern u32  Rand16NextScaled(u16 nRange);                                  /* Rand16NextScaled */
extern int  GameState_IsFlagSet(int nFlag);                                   /* GameState_IsFlagSet */
extern void func_020235bc(int nFlag);                                   /* GameState_ClearFlag */
extern int Ov008_CommitSaveToSlot(int nSlot);                             /* Ov008_CommitSaveToSlot */

int Ov008_BeginSaveToSlot(Ov008SaveMenu *pMenu, u32 nSlot)
{
    u32 nTier;
    u32 nCount;
    int nRange;
    int nResult;

    GameState_SetField(FIELD_DAY_COPY, 9, (u16)GameState_GetField(FIELD_DAY, 9));
    nRange = GameState_GetField(FIELD_DAY, 9) >= TIER_DAY_SPLIT ? 3 : 2;
    pMenu->aTier[nSlot].nTier = Rand16NextScaled((u16)nRange);
    nTier = pMenu->aTier[nSlot].nTier;
    GameState_SetField(FIELD_TIER, 2, (u16)nTier);
    GameState_SetField(FIELD_TIER_SLOT, 2, (u16)nSlot);
    nCount = pMenu->nSaveCount + 1;
    GameState_SetField(FIELD_COUNT_HI, 16, (u16)(nCount >> 16));
    GameState_SetField(FIELD_COUNT_LO, 16, (u16)nCount);
    pMenu->bChangedA = GameState_IsFlagSet(FLAG_CHANGED_A);
    pMenu->bChangedB = GameState_IsFlagSet(FLAG_CHANGED_B);
    func_020235bc(FLAG_CHANGED_A);
    func_020235bc(FLAG_CHANGED_B);
    nResult = Ov008_CommitSaveToSlot(nSlot);
    pMenu->nCardOp = CARD_OP_TRANSFER;
    return nResult;
}
