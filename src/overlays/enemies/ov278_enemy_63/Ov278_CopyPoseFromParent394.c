/* Ov278_CopyPoseFromParent394 -- copy the four-word pose block at +0x1b4 down from the parent at +0x394,
 * put the object in mode 2 and run the base tick.
 * The copy is written as `((int *)obj)[i + 0x6d]`, an ARRAY INDEX WITH THE FIELD OFFSET FOLDED IN
 * (0x1b4 / 4 = 0x6d): that is what keeps the ROM's `add r0, obj, i lsl #2 ; ldr [r0,#0x1b4]`
 * instead of a strength-reduced running pointer. */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent(int obj, int arg);

void Ov278_CopyPoseFromParent394(int obj, int arg) {
    int i;
    for (i = 0; i < 4; i++) {
        ((int *)obj)[i + 0x6d] = ((int *)*(int *)(obj + 0x394))[i + 0x6d];
    }
    Ov107_SetStatusAndEmit(obj, 2);
    Ov107_HandleRegionEvent(obj, arg);
}
