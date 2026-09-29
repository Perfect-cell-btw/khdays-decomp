/* Marks game flag 0x20e1 according to whether the current item id (2021980) occupies any slot
 * of the save block's three 40-entry +0xee0 rows: set when found, cleared otherwise. Always 1. */

#include "nitro/types.h"

extern int ScriptVm_ReadOperandInt(void *, int);
extern void GameState_SetFlag(int flag);
extern void GameState_ClearFlag(int flag);
extern char *data_0204be18;

int Ov069_MarkCurrentItemEquipped(void *arg0, int arg1)
{
    int id;
    int i;
    int j;
    char *row;

    id = ScriptVm_ReadOperandInt(arg0, arg1);
    row = data_0204be18;
    for (i = 0; i < 3; i++) {
        j = 0;
        {
            char *slot = row;
            for (; j < 0x28; j++) {
                if (id == *(u16 *)(slot + 0xee0)) {
                    GameState_SetFlag(0x20e1);
                    return 1;
                }
                slot += 2;
            }
        }
        row += 0x50;
    }
    GameState_ClearFlag(0x20e1);
    return 1;
}
