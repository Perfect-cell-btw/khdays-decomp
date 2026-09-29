/* Plays anim 8, resets the state and installs the next step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov240_TimedAction4ThenDispatch(void);

void Ov240_AiEnterAnim8(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 8, 0);
    *(int *)(p + 0x38) = 0;
    p[0x3e] = 0;
    p[0x3c] = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov240_TimedAction4ThenDispatch);
}
