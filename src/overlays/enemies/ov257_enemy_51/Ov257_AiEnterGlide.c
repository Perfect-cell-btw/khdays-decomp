/* Targets the nearest object (action 2 when none), plays anim 7 and model anim 6 and installs the
 * glide tick. */

#include "game/enemy_common.h"

extern int Ov107_FindNearestObject(int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov257_DiveInTick(int);
void Ov257_AiEnterGlide(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int child = Ov107_FindNearestObject(*(int *)owner, 0);
    *(int *)(owner + 0x60) = child;
    if (child == 0) {
        *(signed char *)(*(int *)owner + 0x1c7) = 2;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
    } else {
        Ov107_PostTagUpdate((Actor *)(*(int *)owner), 7, 0);
        Ov107_StartAnim(*(int *)(*(int *)owner + 0x3d0), 6, 0);
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov257_DiveInTick);
    }
}
