/* AI step: posts tag 1, starts a timer of 0x78 frames plus a random offset and installs the next
 * movement step. */

#include "game/enemy_common.h"

extern int RandNextScaled(unsigned int mul);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov170_HoverBobTick(void);

void Ov170_AiStep_StartTag1WithTimer(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 1, 1);
    *(int *)(p + 0x54) = RandNextScaled(1) + 0x78;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov170_HoverBobTick);
}
