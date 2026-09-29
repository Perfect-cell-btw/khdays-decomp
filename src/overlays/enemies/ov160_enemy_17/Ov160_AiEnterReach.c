/* Clear the child field at +0x14, set anim state 1, then dispatch via
 * SetIndexedSlot (handler Ov160_ReachCheckTick). */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov160_ReachCheckTick(void);
void Ov160_AiEnterReach(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x14) = 0;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 1, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov160_ReachCheckTick);
}
