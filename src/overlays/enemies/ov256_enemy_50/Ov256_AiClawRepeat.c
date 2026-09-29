/* Unless busy, advance the +0x54 counter; on 2 kick anim 0xe and dispatch, else kick anim 0xd. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov256_AiClawEnd(int);
void Ov256_AiClawRepeat(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(int *)(owner + 0x54) += 1;
    if (*(int *)(owner + 0x54) == 2) {
        *(int *)(owner + 0x4c) = 0;
        Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xe, 0);
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_AiClawEnd);
    } else {
        Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xd, 0);
    }
}
