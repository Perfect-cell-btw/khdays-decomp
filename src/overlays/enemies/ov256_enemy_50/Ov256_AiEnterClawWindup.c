/* Clear +0x6a, kick animation 0xa, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov256_AiClawWindupStart(int);
void Ov256_AiEnterClawWindup(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(signed char *)(owner + 0x6a) = 0;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xa, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_AiClawWindupStart);
}
