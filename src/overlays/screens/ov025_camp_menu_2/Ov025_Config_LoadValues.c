/* Ov025_Config_LoadValues -- Ov025_Config_LoadValues: fill the config page's option values (+0x4e,
 * ten halfwords) from the game-state fields 0x37c4, 0x37bf, 0x37c0 (2 bits), 0x37c3, 0x37c2,
 * 0x37c5, 0x37c6, then 0x37c7 and 0x35bf (2 bits each, modulo 3); value 7 is not loaded.  When
 * the player owns no copy of item 0x1a0 (GameState 0x810 + id) field 0x3c29 is first set to 1.
 * Twin of ov008 02069ca4's first half. */

#include "nitro/types.h"

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
extern void  GameState_SetField(int nField, int nBits, u32 nValue);      /* GameState_SetField */
extern u32   GameState_GetField(int nField, int nBits);                  /* GameState_GetField */

void Ov025_Config_LoadValues(void)
{
    Ov025ConfigPage *pPage;

    pPage = Ov025_GetPageA();
    if (data_0204be18->aItemCount[0x1a0] == 0) {
        GameState_SetField(0x3c29, 2, 1);
    }
    pPage->aValue[0] = GameState_GetField(CONFIG_CONTROLS, 1);
    pPage->aValue[1] = GameState_GetField(CONFIG_CHASE_CAM, 1);
    pPage->aValue[2] = GameState_GetField(CONFIG_CAM_SPEED, 2);
    pPage->aValue[3] = GameState_GetField(CONFIG_CAM_X_AXIS, 1);
    pPage->aValue[4] = GameState_GetField(CONFIG_CAM_Y_AXIS, 1);
    pPage->aValue[5] = GameState_GetField(CONFIG_CURSOR_POSITION, 1);
    pPage->aValue[6] = GameState_GetField(CONFIG_COMMAND_LIST, 1);
    pPage->aValue[8] = GameState_GetField(0x37c7, 2) % 3;
    pPage->aValue[9] = GameState_GetField(0x35bf, 2) % 3;
}
