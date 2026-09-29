/* Dispatch to SetIndexedSlot with param_1, its signed byte at +0x20, and handler Ov107_FollowUntilAnimEnd. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
int Ov107_stAdvanceState_ccedc(int param_1) {
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov107_FollowUntilAnimEnd);
}
