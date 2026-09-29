/* Run 020ccd54, reset fields, kick anim 9, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov256_PickTarget(int);
extern int Ov256_ClawLobTick(int);
void Ov256_AiEnterClawLob(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov256_PickTarget(param_1);
    *(int *)(owner + 0x54) = 0;
    *(int *)(owner + 0x4c) = 0;
    *(signed char *)(owner + 0x69) = 2;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 9, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_ClawLobTick);
}
