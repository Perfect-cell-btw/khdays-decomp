#include "game/enemy_common.h"

extern void SetIndexedSlot(void *a, int b, void *cb);
extern void Ov173_StalkTick(void);

void Ov173_AiStep_StartTag1(char *a) {
    char *p = *(char **)(a + 0x4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 1, 1);
    *(int *)(p + 0x48) = 0;
    SetIndexedSlot(a, *(signed char *)(a + 0x20), Ov173_StalkTick);
}
