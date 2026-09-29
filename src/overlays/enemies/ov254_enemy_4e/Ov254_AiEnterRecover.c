/* Kick the 0x1d/0 animation, set +0x10, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov254_RecoverEntry(int);
void Ov254_AiEnterRecover(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x1d, 0);
    *(int *)(owner + 0x10) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov254_RecoverEntry);
}
