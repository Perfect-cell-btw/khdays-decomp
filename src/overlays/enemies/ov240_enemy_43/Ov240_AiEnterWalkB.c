/* Plays looping anim 2, resets the part and installs the next step. */

#include "game/enemy_common.h"

extern void Ov240_startAnim(int obj, int arg);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov240_stateFixedAngleMatrix_2(void);

void Ov240_AiEnterWalkB(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 2, 1);
    Ov240_startAnim(*(int *)p, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov240_stateFixedAngleMatrix_2);
}
