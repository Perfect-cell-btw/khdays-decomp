/* AI step: keeps the previous velocity, lowers the vertical speed, damps the velocity; when the
 * model's animation ends picks a random spin, queues action 4 and clears the step handler. */

#include "game/engine.h"

struct w3 { int a, b, c; };
extern void ScaleVec3Fx12(int factor, void *src, void *dst);
extern void SetIndexedSlot();

void Ov298_CopyScaleVecSetField28ThenAdvance(int this_) {
    int holder = *(int *)(this_ + 4);
    void *src = (void *)(holder + 0x1c);
    *(struct w3 *)(holder + 0x10) = *(struct w3 *)src;
    *(int *)(holder + 0x14) = *(int *)(holder + 0x4c);
    *(int *)(holder + 0x4c) = *(int *)(holder + 0x4c) - 0x80;
    ScaleVec3Fx12(0xe00, src, src);
    if (*(unsigned char *)(*(int *)(holder + 4) + 0xad) != 0) return;
    *(int *)(holder + 0x28) = Rand16NextScaled(0x1922) + 0x1922;
    *(signed char *)(*(int *)holder + 0x1c7) = 4;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
