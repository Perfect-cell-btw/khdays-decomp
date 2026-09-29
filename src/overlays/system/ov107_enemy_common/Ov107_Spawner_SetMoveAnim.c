/* Replaces the spawner's move animation and sets its duration (looping when none). */

#include "game/enemy_common.h"
#include "game/engine.h"

void Ov107_Spawner_SetMoveAnim(char *self, void *pAnim, int duration) {
    if (*(void **)(self + 0xf4) != 0) {
        FreeInstanceMemory(*(void **)(self + 0xf4));
        *(void **)(self + 0xf4) = 0;
    }
    if (pAnim != 0) {
        *(void **)(self + 0xf4) = pAnim;
        Ov107_SetOwnerWord((int *)pAnim, (int)self);
        if (duration > 0) {
            *(int *)(self + 0xf8) = duration;
            *(unsigned short *)(self + 0x48) &= ~1;
        } else {
            *(int *)(self + 0xf8) = 0;
            *(unsigned short *)(self + 0x48) |= 1;
        }
    }
}
