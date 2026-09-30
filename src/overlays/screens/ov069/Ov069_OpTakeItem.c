/* Script opcode: take an item from the player. Operands: item id and amount. Ids outside
 * 1..0x3ff are ignored. The free stock is the +0x810 count minus one per slot of the three
 * 40-entry +0xee0 rows holding the id; the amount is subtracted while it fits, otherwise the
 * stock is emptied. */

#include "nitro/types.h"
#include "game/engine.h"

extern char *gGameState;

int Ov069_OpTakeItem(void *vm, unsigned short *pc)
{
    int id;
    u16 count;
    int i;
    int j;
    char *row;
    u16 amount;

    id = ScriptVm_ReadOperandInt(vm, pc);
    if (id > 0 && id >= 0x400) {
        return 1;
    }
    row = gGameState;
    count = *(u8 *)(row + id + 0x810);
    for (i = 0; i < 3; i++) {
        j = 0;
        {
            char *slot = row;
            for (; j < 0x28; j++) {
                if (id == *(u16 *)(slot + 0xee0) && count != 0) {
                    count--;
                }
                slot += 2;
            }
        }
        row += 0x50;
    }
    amount = ScriptVm_ReadOperandInt(vm, pc + 4);
    if (count > amount) {
        *(u8 *)(gGameState + 0x810 + id) -= amount;
    } else {
        *(u8 *)(gGameState + id + 0x810) = 0;
    }
    return 1;
}
