/* Script opcode: give the player an item. Operands: item id and amount. Id -1 unlocks a
 * stat instead: amount 0xc raises the two 0x37b7/0x37b9 kind-2 counters to at least 1, any
 * other amount the kind-2 counter at 0x379f + amount. A real id (1..0x276) adds the amount to
 * its +0x810 stock byte in the save block (capped at 99) and sets game flag 0x4db + id. */
#include "nitro/types.h"

extern int ScriptVm_ReadOperandInt(void *vm, unsigned short *pc);
extern unsigned int GameState_GetField(int id, int kind);
extern void GameState_SetField(int id, int kind, int value);
extern void GameState_SetFlag(int flag);
extern char *data_0204be18;

int Ov069_OpGiveItem(void *vm, unsigned short *pc)
{
    int id;
    int amount;
    u8 *stock;
    int value;

    id = ScriptVm_ReadOperandInt(vm, pc);
    amount = ScriptVm_ReadOperandInt(vm, pc + 4);
    if (id == -1) {
        if (amount == 0xc) {
            if ((unsigned short)GameState_GetField(0x37b7, 2) < 1) {
                GameState_SetField(0x37b7, 2, 1);
            }
            if ((unsigned short)GameState_GetField(0x37b9, 2) < 1) {
                GameState_SetField(0x37b9, 2, 1);
            }
        } else {
            if ((unsigned short)GameState_GetField(amount * 2 + 0x379f, 2) < 1) {
                GameState_SetField(amount * 2 + 0x379f, 2, 1);
            }
        }
    } else if (id > 0 && id < 0x277) {
        stock = (u8 *)(data_0204be18 + 0x810);
        value = stock[id];
        value += amount;
        if (value > 0x63) {
            value = 0x63;
        }
        stock[id] = value;
        GameState_SetFlag(id + 0x4db);
    }
    return 1;
}
