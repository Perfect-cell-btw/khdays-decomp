/* For indices 1..0x276, when Ov008_TestBitInBitset(param_1, i) is nonzero, notify
 * GameState_SetFlag with the message id i+0x37c9. */

#include "game/engine.h"

extern int Ov008_TestBitInBitset(int obj, int index);

void Ov008_ForwardSetBitsInRange(int param_1) {
    int i;
    for (i = 1; i < 0x277; i++) {
        if (Ov008_TestBitInBitset(param_1, i) != 0) {
            GameState_SetFlag(i + 0x37c9);
        }
    }
}
