/* Plays anim 13, resets the timer and installs the next step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov205_TimedAction6ThenReset(void);

void Ov205_AiEnterAnim13(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 13, 0);
    *(int *)(p + 0x2c) = 0;
    p[0x45] = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov205_TimedAction6ThenReset);
}
