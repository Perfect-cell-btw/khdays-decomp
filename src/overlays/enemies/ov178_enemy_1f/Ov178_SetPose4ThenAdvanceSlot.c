/* Push animation params (4, 0) to the sprite, then dispatch via
 * SetIndexedSlot with handler Ov178_HoverTick. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov178_HoverTick(void);
void Ov178_SetPose4ThenAdvanceSlot(int param_1) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(param_1 + 4))), 4, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov178_HoverTick);
}
