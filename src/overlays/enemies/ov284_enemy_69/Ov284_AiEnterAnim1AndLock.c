/* Plays anim 1, sets the part flag and +0x1ae bit 0, installs the sub-state 9 prep step. */

#include "game/enemy_common.h"

struct lobyte { unsigned int b : 8; };

extern void SetIndexedSlot(int *a, int i, int v);
extern void Ov284_PrepSubState9IfChildIdle(void);

void Ov284_AiEnterAnim1AndLock(int *this)
{
    int node = this[1];
    Ov107_PostTagUpdate((Actor *)(*(int *)node), 1, 0);
    ((struct lobyte *)(*(int *)(*(int *)node + 0x3a8) + 8))->b |= 1;
    *(unsigned short *)(*(int *)node + 0x1ae) |= 1;
    SetIndexedSlot(this, *(signed char *)((int)this + 0x20), (int)&Ov284_PrepSubState9IfChildIdle);
}
