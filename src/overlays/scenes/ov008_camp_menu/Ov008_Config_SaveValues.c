/* Ov008_Config_SaveValues -- write the Config page's option values (+0x4e, 25 halfwords) back to
 * their game-state fields (the inverse of Ov008_Config_LoadValues), each masked to the field's
 * width (value 16 keeps two bits in a 1-bit field; 7 is not saved).
 * Codegen: the value parameter is declared s16 here so the field load is
 * evaluated before the id / width constants (mwcc argument order). */

#include "nitro/types.h"
#include "game/engine.h"

#include "game/config.h"
typedef struct Ov008SelCtx {
    u8  pad_0000[0x4c];
    s16 sel;                  /* 0x4c: highlighted item */
    s16 aValue[0x19];         /* 0x4e: the option values */
} Ov008SelCtx;

extern Ov008SelCtx *Ov008_GetMenuContext(void);                    /* Ov008_GetMenuContext */

void Ov008_Config_SaveValues(void)
{
    Ov008SelCtx *pCtx;

    pCtx = Ov008_GetMenuContext();
    GameState_SetField(CONFIG_CONTROLS, 1, (s16)(pCtx->aValue[0] & 1));
    GameState_SetField(CONFIG_CHASE_CAM, 1, (s16)(pCtx->aValue[1] & 1));
    GameState_SetField(CONFIG_CAM_SPEED, 2, (s16)(pCtx->aValue[2] & 3));
    GameState_SetField(CONFIG_CAM_X_AXIS, 1, (s16)(pCtx->aValue[3] & 1));
    GameState_SetField(CONFIG_CAM_Y_AXIS, 1, (s16)(pCtx->aValue[4] & 1));
    GameState_SetField(CONFIG_CURSOR_POSITION, 1, (s16)(pCtx->aValue[5] & 1));
    GameState_SetField(CONFIG_COMMAND_LIST, 1, (s16)(pCtx->aValue[6] & 1));
    GameState_SetField(0x37c7, 2, (s16)(pCtx->aValue[8] & 3));
    GameState_SetField(0x35bf, 2, (s16)(pCtx->aValue[9] & 3));
    GameState_SetField(0x3c15, 1, (s16)(pCtx->aValue[10] & 1));
    GameState_SetField(0x3c16, 1, (s16)(pCtx->aValue[11] & 1));
    GameState_SetField(0x3c17, 2, (s16)(pCtx->aValue[12] & 3));
    GameState_SetField(0x3c19, 2, (s16)(pCtx->aValue[13] & 3));
    GameState_SetField(0x3c1b, 2, (s16)(pCtx->aValue[14] & 3));
    GameState_SetField(0x3c1d, 2, (s16)(pCtx->aValue[15] & 3));
    GameState_SetField(0x3c26, 1, (s16)(pCtx->aValue[16] & 3));
    GameState_SetField(0x3c1f, 1, (s16)(pCtx->aValue[17] & 1));
    GameState_SetField(0x3c20, 1, (s16)(pCtx->aValue[18] & 1));
    GameState_SetField(0x35c1, 2, (s16)(pCtx->aValue[19] & 3));
    GameState_SetField(0x3c23, 2, (s16)(pCtx->aValue[20] & 3));
    GameState_SetField(0x3c21, 2, (s16)(pCtx->aValue[21] & 3));
    GameState_SetField(0x3c25, 1, (s16)(pCtx->aValue[22] & 1));
    GameState_SetField(0x3c27, 2, (s16)(pCtx->aValue[23] & 3));
    GameState_SetField(0x3c29, 2, (s16)(pCtx->aValue[24] & 3));
}
