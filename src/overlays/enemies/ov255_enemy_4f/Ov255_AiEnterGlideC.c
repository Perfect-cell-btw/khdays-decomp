/* Kick the 0x13/0 animation, set +0x50, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov255_GlideTick_3(int);
void Ov255_AiEnterGlideC(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x13, 0);
    *(int *)(owner + 0x50) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov255_GlideTick_3);
}
