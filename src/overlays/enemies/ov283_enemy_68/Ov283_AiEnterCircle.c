/* Reset +0x48/+0x81, kick anim (1, phase 1), set +0x5c=0x900, clear +0x74, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov283_CircleTick(int);
void Ov283_AiEnterCircle(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x48) = 0;
    *(signed char *)(owner + 0x81) = 0;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 1, 1);
    *(int *)(owner + 0x5c) = 0x900;
    *(int *)(owner + 0x74) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov283_CircleTick);
}
