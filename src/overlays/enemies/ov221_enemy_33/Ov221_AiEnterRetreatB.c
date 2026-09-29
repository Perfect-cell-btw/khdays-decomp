/* Plays anim 0x11 with turn rate 0x600 and installs the retreat tick. */

#include "game/enemy_common.h"

/* Set +0x74=6, anim 0x11, +0x6c=0x600, clear +0x75/+0x5c, then dispatch. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov221_RetreatTick(void);
void Ov221_AiEnterRetreatB(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(unsigned char *)(child + 0x74) = 6;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0x11, 0);
    *(int *)(child + 0x6c) = 0x600;
    *(unsigned char *)(child + 0x75) = 0;
    *(int *)(child + 0x5c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov221_RetreatTick);
}
