/* Drops a reference to a resource slot, releasing the slot when the last reference goes. */

#include "game/engine.h"

extern int data_ov025_020b5744;

void Ov025_DecRefSlot(int arg0) {
    int v = *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + arg0 * 4 + 0x96bc);
    if (v < 1) return;
    if (v == 1) ResSlot_Release_2(arg0);
    {
        int base = *(int *)((char *)&data_ov025_020b5744 + 4) + 0x96bc;
        *(int *)(base + arg0 * 4) = *(int *)(base + arg0 * 4) - 1;
    }
}
