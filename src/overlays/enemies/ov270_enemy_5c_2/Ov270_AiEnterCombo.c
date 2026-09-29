/* Plays anim 15, resets the combo state and installs the combo tick. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov270_ComboTick(void);

void Ov270_AiEnterCombo(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 15, 0);
    p[0x50] = 0;
    *(int *)(p + 0x30) = 0;
    p[0x53] = 0;
    *(int *)(p + 0x54) = 0;
    p[0x51] = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov270_ComboTick);
}
