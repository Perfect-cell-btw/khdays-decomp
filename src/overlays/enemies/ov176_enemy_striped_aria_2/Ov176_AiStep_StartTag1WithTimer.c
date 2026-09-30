/* AI step: posts tag 1, starts a timer of 0x78 frames plus a random offset and installs the next
 * movement step. */

#include "game/engine.h"

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov176_HoverBobTick(void);

void Ov176_AiStep_StartTag1WithTimer(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 1, 1);
    *(int *)(p + 0x54) = RandNextScaled(1) + 0x78;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov176_HoverBobTick);
}
