/* Push animation params (15, 0) to the sprite, then dispatch via
 * SetIndexedSlot with handler Ov278_AiQueue2OnAnimEnd. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov278_AiQueue2OnAnimEnd(void);
void Ov278_AiStep_StartTag15(int param_1) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(param_1 + 4))), 15, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov278_AiQueue2OnAnimEnd);
}
