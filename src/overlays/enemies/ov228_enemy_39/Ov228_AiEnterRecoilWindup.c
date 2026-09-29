/* Resolve the target via Ov107_FindNearestObject into +0x3bc; if none, mark state 2
 * and dispatch (null handler); else set anim 0x16, clear +0x4c/+0x62/+0x61, and
 * dispatch. */

#include "game/enemy_common.h"

extern int Ov107_FindNearestObject(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov228_RecoilWindUpTick(void);
void Ov228_AiEnterRecoilWindup(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(*(int *)child + 0x3bc) = Ov107_FindNearestObject(*(int *)child, 0);
    if (*(int *)(*(int *)child + 0x3bc) == 0) {
        *(signed char *)(*(int *)child + 0x1c7) = 2;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0x16, 0);
    *(int *)(child + 0x4c) = 0;
    *(unsigned char *)(child + 0x62) = 0;
    *(unsigned char *)(child + 0x61) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov228_RecoilWindUpTick);
}
