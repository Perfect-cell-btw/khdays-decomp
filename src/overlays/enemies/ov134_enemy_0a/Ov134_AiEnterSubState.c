/* Plays anim 9, resets the state and installs the sub-state step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov134_ConfigSubStateThenAdvanceSlot(void);

void Ov134_AiEnterSubState(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 9, 0);
    p[0x40] = 0;
    *(int *)(p + 0x30) = 0;
    p[0x41] = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov134_ConfigSubStateThenAdvanceSlot);
}
