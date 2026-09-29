/* Ov008_ShopConfirmPurchase -- Ov008_ShopConfirmPurchase: the shop's "confirm" state.
 * Refreshes the touch state (unload/reload of the pad word at ctx+0xc0fc around
 * Ov008_UpdateTouchState); when a confirm key (mask 0xb) or a touch press
 * (ctx+0xc118) is down it plays the cursor cue and buys the selected record: an
 * item record adds one to its stock (capped at the record's maximum) and sets the
 * item's seen flag (0x4db + id); a non-item record sets its own flag (0xc4e + id)
 * and runs its grant hook.  The panel is redrawn and the next state
 * (Ov008_CommitSelection) is returned, or 0 when nothing was pressed.
 */

#include "nitro/types.h"

#define KEY_CONFIRM_MASK 0xb
#define FLAG_ITEM_SEEN_BASE 0x4db
#define FLAG_GRANT_BASE     0xc4e

typedef struct Ov008ItemDef {
    u8  pad_00[0x14];
    int nItemId;              /* 0x14 */
} Ov008ItemDef;

typedef struct Ov008ParamRecord {
    u8            pad_00[0xc];
    Ov008ItemDef *pItemDef;   /* 0x0c: 0 for non-item records */
    u8            pad_10[4];
    int           nGrantId;   /* 0x14 (nExponent for item records) */
} Ov008ParamRecord;

typedef struct Ov008ShopDetail {
    u8                pad_00[0x24];
    Ov008ParamRecord *pRecord;    /* 0x24: selected record */
} Ov008ShopDetail;

typedef struct GameState {
    u8 pad_0000[0x810];
    u8 aItemCount[0x8d0];     /* 0x810 */
} GameState;

extern char *data_ov008_02090fac;
extern u16 data_0204c190;                                              /* pressed keys */
extern GameState *data_0204be18;

extern void KeyRepeat_Step(u16 *pWord);
extern void Ov008_UpdateTouchState(void);                                 /* Ov008_UpdateTouchState */
extern u16 Mem_ReadU16(u16 *pWord);
extern void PlaySound(int nKind, int nSound);                      /* PlaySound */
extern int Ov008_PanelAlpha(Ov008ParamRecord *pRecord);             /* stock cap */
extern void GameState_SetFlag(int nFlag);                                  /* GameState_SetFlag */
extern void Ov008_GrantRewardItems(int nGrantId);                         /* grant hook */
extern void Ov008_RefreshPanelDisplay(void);                                 /* Ov008_RefreshPanelDisplay */
extern void *Ov008_CommitSelection(void);                                /* Ov008_CommitSelection */

void *Ov008_ShopConfirmPurchase(void)
{
    char *ctx = data_ov008_02090fac;
    Ov008ShopDetail *pDetail = (Ov008ShopDetail *)((u8 (*)[0xc400])(ctx + 0x14c) + 1); /* ctx + 0xc54c */
    void *pNext = 0;
    Ov008ParamRecord *pRecord;
    int nItemId;
    GameState *pState;

    KeyRepeat_Step((u16 *)(ctx + 0xc0fc));
    Ov008_UpdateTouchState();
    Mem_ReadU16((u16 *)(ctx + 0xc0fc));
    if ((data_0204c190 & KEY_CONFIRM_MASK) != 0 || *(int *)(ctx + 0xc118) != 0) {
        PlaySound(0, 0);
        pRecord = pDetail->pRecord;
        pNext = (void *)Ov008_CommitSelection;
        if (pRecord->pItemDef != 0) {
            nItemId = pRecord->pItemDef->nItemId;
            pState = data_0204be18;
            if (pState->aItemCount[nItemId] < Ov008_PanelAlpha(pRecord)) {
                pState->aItemCount[nItemId]++;
            }
            GameState_SetFlag(pDetail->pRecord->pItemDef->nItemId + FLAG_ITEM_SEEN_BASE);
        } else {
            GameState_SetFlag(pRecord->nGrantId + FLAG_GRANT_BASE);
            Ov008_GrantRewardItems(pDetail->pRecord->nGrantId);
        }
    }
    Ov008_RefreshPanelDisplay();
    return pNext;
}
