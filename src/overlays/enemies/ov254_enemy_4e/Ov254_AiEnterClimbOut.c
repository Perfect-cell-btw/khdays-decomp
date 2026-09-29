/* Kick anim (0, phase 1), snapshot the target, compute the travel delta, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov254_PanelYForPhase(int, int, int);
extern int Ov254_ClimbOutTick(int);
void Ov254_AiEnterClimbOut(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0, 1);
    *(int *)(owner + 0x10) = 0;
    *(int *)(owner + 0x44) = 0;
    int v = *(int *)(*(int *)(owner + 8) + 4);
    *(int *)(owner + 0x50) = v;
    int r = Ov254_PanelYForPhase(owner, 0xb, v);
    *(int *)(owner + 0x54) = r - *(int *)(owner + 0x50);
    *(signed char *)(owner + 0x70) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov254_ClimbOutTick);
}
