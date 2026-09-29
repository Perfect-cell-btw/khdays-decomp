#include "game/enemy_common.h"

struct lobyte { unsigned int b : 8; };

extern void SetIndexedSlot(int obj, int a, int cb);
extern void Ov284_IdleTick(void);

// Switch to mode 0, set the ready bit (node[0][0x3a8][8] bit0), and advance the
// sub-state with the follow-up callback.
void Ov284_SetReadyBitThenAdvance(int *this)
{
    int node = this[1];
    Ov107_PostTagUpdate((Actor *)(*(int *)node), 0, 1);
    ((struct lobyte *)(*(int *)(*(int *)node + 0x3a8) + 8))->b |= 1;
    SetIndexedSlot((int)this, *(signed char *)((int)this + 0x20), (int)&Ov284_IdleTick);
}
