/* Push animation params (1, 1) to the sprite, then dispatch via
 * SetIndexedSlot with handler Ov186_KeepDistanceOrRetreat. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov186_KeepDistanceOrRetreat(void);
void Ov186_SetPoseThenAdvanceSlot(int param_1) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(param_1 + 4))), 1, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov186_KeepDistanceOrRetreat);
}
