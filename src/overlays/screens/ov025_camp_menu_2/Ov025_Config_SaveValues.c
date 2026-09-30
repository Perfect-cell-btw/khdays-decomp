/* Ov025_Config_SaveValues -- Ov025_Config_SaveValues: write the config page's option values (+0x4e)
 * back to the game-state fields 0x37c4, 0x37bf, 0x37c0 (2 bits), 0x37c3, 0x37c2, 0x37c5, 0x37c6,
 * 0x37c7 and 0x35bf (2 bits), masked to their width; value 7 is not saved.  Twin of ov008
 * 02069eec's first half.  Codegen: the value parameter is declared s16 so the field load is
 * evaluated before the id / width constants (mwcc argument order). */

#include "nitro/types.h"
#include "game/engine.h"

#include "game/config.h"
typedef struct Ov025ConfigPage {
    u8   pad_00[0x4e];
    s16  aValue[10];          /* 0x4e: the option values (7 unused) */
} Ov025ConfigPage;

typedef struct GameState {
    u8   pad_0000[0x810];
    u8   aItemCount[0x8d0];   /* 0x810 */
} GameState;

extern Ov025ConfigPage *Ov025_GetPageA(void);                  /* Ov008_GetPageA */
extern GameState *data_0204be18;

void Ov025_Config_SaveValues(void)
{
    Ov025ConfigPage *pPage;

    pPage = Ov025_GetPageA();
    GameState_SetField(CONFIG_CONTROLS, 1, (s16)(pPage->aValue[0] & 1));
    GameState_SetField(CONFIG_CHASE_CAM, 1, (s16)(pPage->aValue[1] & 1));
    GameState_SetField(CONFIG_CAM_SPEED, 2, (s16)(pPage->aValue[2] & 3));
    GameState_SetField(CONFIG_CAM_X_AXIS, 1, (s16)(pPage->aValue[3] & 1));
    GameState_SetField(CONFIG_CAM_Y_AXIS, 1, (s16)(pPage->aValue[4] & 1));
    GameState_SetField(CONFIG_CURSOR_POSITION, 1, (s16)(pPage->aValue[5] & 1));
    GameState_SetField(CONFIG_COMMAND_LIST, 1, (s16)(pPage->aValue[6] & 1));
    GameState_SetField(0x37c7, 2, (s16)(pPage->aValue[8] & 3));
    GameState_SetField(0x35bf, 2, (s16)(pPage->aValue[9] & 3));
}
