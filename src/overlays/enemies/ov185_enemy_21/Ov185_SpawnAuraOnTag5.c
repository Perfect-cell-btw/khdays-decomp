/* Single-case switch: `msg[2] == 5 && msg[3] == 0` lets mwcc if-convert the second test
 * into the first (ldrbeq/cmpeq); the ROM branches on both.
 * Ov107_CreateSpawnTask takes FIVE arguments (the fifth on the stack); Ghidra shows six. */

#include "game/enemy_common.h"

extern void Ov185_UnlinkHeldNode(int self);
extern void Ov107_AiState_OnMessage(int self, int msg, int c);

void Ov185_SpawnAuraOnTag5(int self, int msg, int c) {
    switch (*(unsigned char *)(msg + 2)) {
    case 5:
        if (*(unsigned char *)(msg + 3) == 0) {
            if (*(int *)(self + 0x390) == 0) {
                *(int *)(self + 0x390) = Ov107_CreateSpawnTask(self, 0x120, 5, 1, (void *)(self + 0xa0));
            } else {
                Ov185_UnlinkHeldNode(self);
            }
        }
        break;
    }
    Ov107_AiState_OnMessage(self, msg, c);
}
