/* Drops a reference to a resource slot, releasing the slot when the last reference goes. */

#include "game/engine.h"

extern int data_ov008_02090f04;

void Ov008_DecRefSlot(int arg0) {
    int v = *(int *)(*(int *)((char *)&data_ov008_02090f04 + 4) + arg0 * 4 + 0x96bc);
    if (v < 1) return;
    if (v == 1) ResSlot_Release_2(arg0);
    {
        int base = *(int *)((char *)&data_ov008_02090f04 + 4) + 0x96bc;
        *(int *)(base + arg0 * 4) = *(int *)(base + arg0 * 4) - 1;
    }
}
