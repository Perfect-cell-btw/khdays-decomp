/* Plays anim 13 and model anim 5 and installs the second offset tracking step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov194_AiTrackOffsetUntilAnimEnd_2(void);

void Ov194_AiEnterTrackOffsetB(char *obj) {
    char *p = *(char **)(obj + 4);
    *(int *)(p + 0x14) = 0;
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 13, 0);
    Ov107_StartAnim(*(int *)(*(char **)p + 0x3d0), 5, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov194_AiTrackOffsetUntilAnimEnd_2);
}
