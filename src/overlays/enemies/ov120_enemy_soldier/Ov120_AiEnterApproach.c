/* Plays anim 1, rolls the approach timer and installs the approach tick. */

#include "game/engine.h"

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov120_AimPickMeleeReaction(void);

void Ov120_AiEnterApproach(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 1, 1);
    int min = *(int *)(*(char **)p + 0x224);
    int range = *(int *)(*(char **)p + 0x228) - min;
    if (range < 0) range = -range;
    *(int *)(p + 0x40) = min + RandNextScaled(range + 1);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov120_AimPickMeleeReaction);
}
