/* Ov008_SaveItemCounts -- Ov008_SaveItemCounts: write the item menu's per-item
 * remaining counts (+0x4e, 25 halfwords) back to their game state fields
 * (the inverse of Ov008_LoadItemCounts), each masked to the field's width
 * (count 16 keeps two bits in a 1-bit field; count 7 is not saved).
 * Codegen: the value parameter is declared s16 here so the field load is
 * evaluated before the id / width constants (mwcc argument order).
 */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov008SelCtx {
    u8  pad_0000[0x4c];
    s16 sel;                  /* 0x4c: highlighted item */
    s16 counts[0x19];         /* 0x4e: per-item remaining counts */
} Ov008SelCtx;

extern Ov008SelCtx *Ov008_GetMenuContext(void);                    /* Ov008_GetMenuContext */

void Ov008_SaveItemCounts(void)
{
    Ov008SelCtx *pCtx;

    pCtx = Ov008_GetMenuContext();
    GameState_SetField(0x37c4, 1, (s16)(pCtx->counts[0] & 1));
    GameState_SetField(0x37bf, 1, (s16)(pCtx->counts[1] & 1));
    GameState_SetField(0x37c0, 2, (s16)(pCtx->counts[2] & 3));
    GameState_SetField(0x37c3, 1, (s16)(pCtx->counts[3] & 1));
    GameState_SetField(0x37c2, 1, (s16)(pCtx->counts[4] & 1));
    GameState_SetField(0x37c5, 1, (s16)(pCtx->counts[5] & 1));
    GameState_SetField(0x37c6, 1, (s16)(pCtx->counts[6] & 1));
    GameState_SetField(0x37c7, 2, (s16)(pCtx->counts[8] & 3));
    GameState_SetField(0x35bf, 2, (s16)(pCtx->counts[9] & 3));
    GameState_SetField(0x3c15, 1, (s16)(pCtx->counts[10] & 1));
    GameState_SetField(0x3c16, 1, (s16)(pCtx->counts[11] & 1));
    GameState_SetField(0x3c17, 2, (s16)(pCtx->counts[12] & 3));
    GameState_SetField(0x3c19, 2, (s16)(pCtx->counts[13] & 3));
    GameState_SetField(0x3c1b, 2, (s16)(pCtx->counts[14] & 3));
    GameState_SetField(0x3c1d, 2, (s16)(pCtx->counts[15] & 3));
    GameState_SetField(0x3c26, 1, (s16)(pCtx->counts[16] & 3));
    GameState_SetField(0x3c1f, 1, (s16)(pCtx->counts[17] & 1));
    GameState_SetField(0x3c20, 1, (s16)(pCtx->counts[18] & 1));
    GameState_SetField(0x35c1, 2, (s16)(pCtx->counts[19] & 3));
    GameState_SetField(0x3c23, 2, (s16)(pCtx->counts[20] & 3));
    GameState_SetField(0x3c21, 2, (s16)(pCtx->counts[21] & 3));
    GameState_SetField(0x3c25, 1, (s16)(pCtx->counts[22] & 1));
    GameState_SetField(0x3c27, 2, (s16)(pCtx->counts[23] & 3));
    GameState_SetField(0x3c29, 2, (s16)(pCtx->counts[24] & 3));
}
