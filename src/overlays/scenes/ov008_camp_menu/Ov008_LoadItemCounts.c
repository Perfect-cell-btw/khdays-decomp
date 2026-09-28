/* Ov008_LoadItemCounts -- Ov008_LoadItemCounts: fill the item menu's per-item
 * remaining counts (+0x4e, 25 halfwords) from the game state fields.  When
 * the player owns no copy of item 0x1a0 (GameState 0x810 + id) field 0x3c29
 * is first set to 1.  Counts 8 and 9 are the 2-bit fields 0x37c7 / 0x35bf
 * modulo 3; count 7 is not loaded.
 */

#include "nitro/types.h"

#define ITEM_LAST_UNLOCK 0x1a0
#define FIELD_LAST_UNLOCK 0x3c29

typedef struct Ov008SelCtx {
    u8  pad_0000[0x4c];
    s16 sel;                  /* 0x4c: highlighted item */
    s16 counts[0x19];         /* 0x4e: per-item remaining counts */
} Ov008SelCtx;

typedef struct GameState {
    u8 pad_0000[0x810];
    u8 aItemCount[0x8d0];     /* 0x810 */
} GameState;

extern GameState *data_0204be18;
extern Ov008SelCtx *Ov008_GetMenuContext(void);                    /* Ov008_GetMenuContext */
extern void GameState_SetField(int nField, int nBits, u32 nValue);      /* GameState_SetField */
extern u32  GameState_GetField(int nField, int nBits);                  /* GameState_GetField */

void Ov008_LoadItemCounts(void)
{
    Ov008SelCtx *pCtx;

    pCtx = Ov008_GetMenuContext();
    if (data_0204be18->aItemCount[ITEM_LAST_UNLOCK] == 0) {
        GameState_SetField(FIELD_LAST_UNLOCK, 2, 1);
    }
    pCtx->counts[0] = GameState_GetField(0x37c4, 1);
    pCtx->counts[1] = GameState_GetField(0x37bf, 1);
    pCtx->counts[2] = GameState_GetField(0x37c0, 2);
    pCtx->counts[3] = GameState_GetField(0x37c3, 1);
    pCtx->counts[4] = GameState_GetField(0x37c2, 1);
    pCtx->counts[5] = GameState_GetField(0x37c5, 1);
    pCtx->counts[6] = GameState_GetField(0x37c6, 1);
    pCtx->counts[8] = GameState_GetField(0x37c7, 2) % 3;
    pCtx->counts[9] = GameState_GetField(0x35bf, 2) % 3;
    pCtx->counts[10] = GameState_GetField(0x3c15, 1);
    pCtx->counts[11] = GameState_GetField(0x3c16, 1);
    pCtx->counts[12] = GameState_GetField(0x3c17, 2);
    pCtx->counts[13] = GameState_GetField(0x3c19, 2);
    pCtx->counts[14] = GameState_GetField(0x3c1b, 2);
    pCtx->counts[15] = GameState_GetField(0x3c1d, 2);
    pCtx->counts[16] = GameState_GetField(0x3c26, 1);
    pCtx->counts[17] = GameState_GetField(0x3c1f, 1);
    pCtx->counts[18] = GameState_GetField(0x3c20, 1);
    pCtx->counts[19] = GameState_GetField(0x35c1, 2);
    pCtx->counts[20] = GameState_GetField(0x3c23, 2);
    pCtx->counts[21] = GameState_GetField(0x3c21, 2);
    pCtx->counts[22] = GameState_GetField(0x3c25, 1);
    pCtx->counts[23] = GameState_GetField(0x3c27, 2);
    pCtx->counts[24] = GameState_GetField(FIELD_LAST_UNLOCK, 2);
}
