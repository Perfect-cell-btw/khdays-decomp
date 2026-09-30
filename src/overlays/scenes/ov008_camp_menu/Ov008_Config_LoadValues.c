/* Ov008_Config_LoadValues -- fill the Config page's option values (+0x4e, 25 halfwords) from
 * their game-state fields: the first seven are the page's options (include/game/config.h), 8
 * and 9 the 2-bit fields 0x37c7 / 0x35bf modulo 3; 7 is not loaded. When the player owns no copy
 * of item 0x1a0 (GameState 0x810 + id) field 0x3c29 is first set to 1. The ov025 twin is
 * Ov025_Config_LoadValues. */

#include "nitro/types.h"

#include "game/config.h"
#define ITEM_LAST_UNLOCK 0x1a0
#define FIELD_LAST_UNLOCK 0x3c29

typedef struct Ov008SelCtx {
    u8  pad_0000[0x4c];
    s16 sel;                  /* 0x4c: highlighted item */
    s16 aValue[0x19];         /* 0x4e: the option values */
} Ov008SelCtx;

typedef struct GameState {
    u8 pad_0000[0x810];
    u8 aItemCount[0x8d0];     /* 0x810 */
} GameState;

extern GameState *gGameState;
extern Ov008SelCtx *Ov008_GetMenuContext(void);                    /* Ov008_GetMenuContext */
extern void GameState_SetField(int nField, int nBits, u32 nValue);      /* GameState_SetField */
extern u32  GameState_GetField(int nField, int nBits);                  /* GameState_GetField */

void Ov008_Config_LoadValues(void)
{
    Ov008SelCtx *pCtx;

    pCtx = Ov008_GetMenuContext();
    if (gGameState->aItemCount[ITEM_LAST_UNLOCK] == 0) {
        GameState_SetField(FIELD_LAST_UNLOCK, 2, 1);
    }
    pCtx->aValue[0] = GameState_GetField(CONFIG_CONTROLS, 1);
    pCtx->aValue[1] = GameState_GetField(CONFIG_CHASE_CAM, 1);
    pCtx->aValue[2] = GameState_GetField(CONFIG_CAM_SPEED, 2);
    pCtx->aValue[3] = GameState_GetField(CONFIG_CAM_X_AXIS, 1);
    pCtx->aValue[4] = GameState_GetField(CONFIG_CAM_Y_AXIS, 1);
    pCtx->aValue[5] = GameState_GetField(CONFIG_CURSOR_POSITION, 1);
    pCtx->aValue[6] = GameState_GetField(CONFIG_COMMAND_LIST, 1);
    pCtx->aValue[8] = GameState_GetField(0x37c7, 2) % 3;
    pCtx->aValue[9] = GameState_GetField(0x35bf, 2) % 3;
    pCtx->aValue[10] = GameState_GetField(0x3c15, 1);
    pCtx->aValue[11] = GameState_GetField(0x3c16, 1);
    pCtx->aValue[12] = GameState_GetField(0x3c17, 2);
    pCtx->aValue[13] = GameState_GetField(0x3c19, 2);
    pCtx->aValue[14] = GameState_GetField(0x3c1b, 2);
    pCtx->aValue[15] = GameState_GetField(0x3c1d, 2);
    pCtx->aValue[16] = GameState_GetField(0x3c26, 1);
    pCtx->aValue[17] = GameState_GetField(0x3c1f, 1);
    pCtx->aValue[18] = GameState_GetField(0x3c20, 1);
    pCtx->aValue[19] = GameState_GetField(0x35c1, 2);
    pCtx->aValue[20] = GameState_GetField(0x3c23, 2);
    pCtx->aValue[21] = GameState_GetField(0x3c21, 2);
    pCtx->aValue[22] = GameState_GetField(0x3c25, 1);
    pCtx->aValue[23] = GameState_GetField(0x3c27, 2);
    pCtx->aValue[24] = GameState_GetField(FIELD_LAST_UNLOCK, 2);
}
