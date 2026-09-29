/* Unless the child is busy, kick anim 0xa then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov245_AiStep_QueueAction2OnAnimEnd_3(int);
void Ov245_Rider_AiEndPause(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xa, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_AiStep_QueueAction2OnAnimEnd_3);
}
