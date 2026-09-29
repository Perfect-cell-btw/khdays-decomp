/* Reset the launch block: notify 020cd028, clear +0x30/+0x34/+0x44/+0x3c, set +0x50=6, force the
 * +0x53 low nibble to 3, kick anim 3 and dispatch. */

#include "game/enemy_common.h"

extern int Ov258_AcquireTarget(int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov258_TickBarrage(int);
struct nib { unsigned char lo : 4, hi : 4; };
void Ov258_EnterBarrage(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov258_AcquireTarget(param_1, 1);
    *(int *)(owner + 0x30) = 0;
    *(int *)(owner + 0x34) = 0;
    *(int *)(owner + 0x44) = 0;
    *(unsigned short *)(owner + 0x50) = 6;
    ((struct nib *)(owner + 0x53))->lo = 3;
    *(int *)(owner + 0x3c) = 0;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 3, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov258_TickBarrage);
}
