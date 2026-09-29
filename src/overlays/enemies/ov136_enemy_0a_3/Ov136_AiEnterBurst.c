/* Plays anim 4, resets the burst state and installs the burst tick. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov136_BurstAttackTick(void);

void Ov136_AiEnterBurst(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 4, 0);
    p[0x40] = 0;
    *(int *)(p + 0x30) = 0;
    p[0x41] = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov136_BurstAttackTick);
}
