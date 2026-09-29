/* Single-case switch: `if (msg[2] == 5)` (or `== 5 && ...`) lets mwcc if-convert the
 * inner test into the outer one (ldrbeq/cmpeq); the ROM branches on both. */

#include "game/enemy_common.h"

extern void Ov107_AiState_OnMessage(int a, int b, int c);

void Ov233_EventArmEmitterForward(int self, unsigned char *msg, int arg3) {
    switch (msg[2]) {
    case 5:
        if (msg[3] == 0) {
            *(int *)(self + msg[3] * 8 + 0x394) = Ov107_CreateNodeBodyTask(
                *(int *)(self + 0x3c), *(int *)(self + msg[3] * 8 + 0x390), 0x17,
                self + 0xa0, msg[4], 0);
        }
        break;
    }
    Ov107_AiState_OnMessage(self, (int)msg, arg3);
}
