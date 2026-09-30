/* Ov026_ShopConfirmPurchase -- Ov008_ShopConfirmPurchase: the shop's "confirm" state.
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

extern char *data_ov026_02091368;
extern u16 gPadPressed;                                              /* pressed keys */
extern GameState *gGameState;

extern void KeyRepeat_Step(u16 *pWord);
extern void Ov026_UpdateTouchState(void);                                 /* Ov008_UpdateTouchState */
extern u16 Mem_ReadU16(u16 *pWord);
extern void PlaySound(int nKind, int nSound);                      /* PlaySound */
extern int Ov026_PanelAlpha(Ov008ParamRecord *pRecord);             /* stock cap */
extern void GameState_SetFlag(int nFlag);                                  /* GameState_SetFlag */
extern void Ov026_GrantRewardItems(int nGrantId);                         /* grant hook */
extern void Ov026_RefreshPanelDisplay(void);                                 /* Ov008_RefreshPanelDisplay */
extern void *Ov026_CommitSelection(void);                                /* Ov008_CommitSelection */

void *Ov026_ShopConfirmPurchase(void)
{
    char *ctx = data_ov026_02091368;
    Ov008ShopDetail *pDetail = (Ov008ShopDetail *)((u8 (*)[0xc400])(ctx + 0x14c) + 1); /* ctx + 0xc54c */
    void *pNext = 0;
    Ov008ParamRecord *pRecord;
    int nItemId;
    GameState *pState;

    KeyRepeat_Step((u16 *)(ctx + 0xc0fc));
    Ov026_UpdateTouchState();
    Mem_ReadU16((u16 *)(ctx + 0xc0fc));
    if ((gPadPressed & KEY_CONFIRM_MASK) != 0 || *(int *)(ctx + 0xc118) != 0) {
        PlaySound(0, 0);
        pRecord = pDetail->pRecord;
        pNext = (void *)Ov026_CommitSelection;
        if (pRecord->pItemDef != 0) {
            nItemId = pRecord->pItemDef->nItemId;
            pState = gGameState;
            if (pState->aItemCount[nItemId] < Ov026_PanelAlpha(pRecord)) {
                pState->aItemCount[nItemId]++;
            }
            GameState_SetFlag(pDetail->pRecord->pItemDef->nItemId + FLAG_ITEM_SEEN_BASE);
        } else {
            GameState_SetFlag(pRecord->nGrantId + FLAG_GRANT_BASE);
            Ov026_GrantRewardItems(pDetail->pRecord->nGrantId);
        }
    }
    Ov026_RefreshPanelDisplay();
    return pNext;
}
