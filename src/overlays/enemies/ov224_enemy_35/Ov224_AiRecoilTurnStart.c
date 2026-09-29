/* Unless the grandchild is busy (+0xad), set anim 0x13, run Ov224_startAnim,
 * then dispatch. */

#include "game/enemy_common.h"

extern void Ov224_startAnim(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov224_TurnTick(void);
void Ov224_AiRecoilTurnStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0x13, 0);
    Ov224_startAnim(*(int *)child, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov224_TurnTick);
}
