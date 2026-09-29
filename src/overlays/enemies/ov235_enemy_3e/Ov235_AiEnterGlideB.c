/* Targets the nearest object (action 2 when none), plays anim 10 and model anim 9 and installs the
 * second glide tick. */

#include "game/enemy_common.h"

extern int Ov107_FindNearestObject(int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov235_GlideTick_2(int);
void Ov235_AiEnterGlideB(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int child = Ov107_FindNearestObject(*(int *)owner, 0);
    *(int *)(owner + 0x5c) = child;
    if (child == 0) {
        *(signed char *)(*(int *)owner + 0x1c7) = 2;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
    } else {
        Ov107_PostTagUpdate((Actor *)(*(int *)owner), 10, 0);
        Ov107_StartAnim(*(int *)(*(int *)owner + 0x3a8), 9, 0);
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov235_GlideTick_2);
    }
}
