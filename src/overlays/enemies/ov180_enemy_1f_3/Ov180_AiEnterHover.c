/* Plays looping anim 1, rolls the bob time and installs the hover bob tick. */

#include "game/engine.h"

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov180_HoverBobTick(void);

void Ov180_AiEnterHover(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 1, 1);
    *(int *)(p + 0x54) = RandNextScaled(1) + 0x28;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov180_HoverBobTick);
}
