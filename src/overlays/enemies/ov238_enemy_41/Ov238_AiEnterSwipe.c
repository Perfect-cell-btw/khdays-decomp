/* Kick anim 3, set +0x31=3 and clear +0x20, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov238_AiSwipeTick(int);
void Ov238_AiEnterSwipe(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 3, 0);
    *(signed char *)(owner + 0x31) = 3;
    *(int *)(owner + 0x20) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov238_AiSwipeTick);
}
