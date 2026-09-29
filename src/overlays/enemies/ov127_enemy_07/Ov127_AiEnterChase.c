/* Plays anim 2, rolls the move timer and installs the chase decision. */

#include "game/enemy_common.h"

extern int RandNextScaled(unsigned int mul);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov127_DecideChaseMove(void);

void Ov127_AiEnterChase(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 2, 0);
    int min = *(int *)(*(char **)p + 0x224);
    int range = *(int *)(*(char **)p + 0x228) - min;
    if (range < 0) range = -range;
    *(int *)(p + 0x38) = min + RandNextScaled(range + 1);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov127_DecideChaseMove);
}
