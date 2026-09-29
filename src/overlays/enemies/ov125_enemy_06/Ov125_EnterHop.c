/* Start the ov125 enemy's hop: cancel the current action (mode 6, flag 1), clear the hop
 * timers (+0x40, +0x48, +0x2c), roll a random hop direction (-0x1000 or +0x1000) into +0x44,
 * seed the +0x3c counter with 15 times the owner's +0x2c rate, the +0x4c count with 5 + rand(6)
 * and the +0x50 count with 7 + rand(4), then register the hop think callback. */

#include "game/enemy_common.h"

extern int RandNextScaled();
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov125_HopTick(void);

void Ov125_EnterHop(int self) {
    int v;
    int *node = *(int **)(self + 4);
    Ov107_PostTagUpdate((Actor *)(*node), 6, 1);
    node[0x10] = 0;
    node[0x11] = RandNextScaled(2) + (v - v) != 0 ? -0x1000 : 0x1000;
    node[0x12] = 0;
    node[0xf] = *(int *)(*(int *)self + 0x2c) * 0x1e / 2;
    node[0x13] = RandNextScaled(6) + 5;
    node[0xb] = 0;
    node[0x14] = RandNextScaled(4) + 7;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov125_HopTick);
}
