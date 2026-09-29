/* Unless busy, tick +0x40; on reaching 5 kick anim 0x15, retire the +0x468 node and advance to
 * 020d0bf4, otherwise just kick anim 0x14. */

#include "game/enemy_common.h"

extern int Ov254_ForwardToAiIfReady_4(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov254_AiStep_QueueAction4OnAnimEnd(int);
void Ov254_AiLoopAnimThenRelease(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(int *)(owner + 0x40) += 1;
    if (*(int *)(owner + 0x40) >= 5) {
        Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x15, 0);
        Ov254_ForwardToAiIfReady_4(*(int *)(*(int *)owner + 0x468));
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov254_AiStep_QueueAction4OnAnimEnd);
    } else {
        Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x14, 0);
    }
}
