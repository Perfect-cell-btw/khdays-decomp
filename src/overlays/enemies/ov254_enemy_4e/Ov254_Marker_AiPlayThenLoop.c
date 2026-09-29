/* Unless the child is busy, kick anim (1, phase 1) and dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov254_Marker_IdleStep(int);
void Ov254_Marker_AiPlayThenLoop(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 1, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov254_Marker_IdleStep);
}
