/* Plays looping anim 0, clears the velocity, rolls the walk time and installs the walk tick. */

#include "game/enemy_common.h"

typedef struct { int w[3]; } Blk12;

extern int RandNextScaled(unsigned int mul);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov283_WalkTick(void);
extern Blk12 data_02041dc8;

void Ov283_AiEnterWalk(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 0, 1);
    *(Blk12 *)(p + 0x10) = data_02041dc8;
    *(int *)(p + 0x5c) = 0;
    int min = *(int *)(*(char **)p + 0x224);
    int range = *(int *)(*(char **)p + 0x228) - min;
    if (range < 0) range = -range;
    *(int *)(p + 0x48) = min + RandNextScaled(range + 1);
    *(int *)(p + 0x78) = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov283_WalkTick);
}
