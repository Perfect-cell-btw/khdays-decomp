/* Skip if the grandchild busy flag (+0xad) is set; else set anim 0x12 and dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov224_AiRecoilTurnStart(void);
void Ov224_AiRecoilTurnWait(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0x12, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov224_AiRecoilTurnStart);
}
