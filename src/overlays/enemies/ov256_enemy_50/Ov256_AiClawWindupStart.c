/* Unless busy, clear +0x54 and kick anim 0xb; always dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov256_ClawWindupTick(int);
void Ov256_AiClawWindupStart(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) == 0) {
        *(int *)(owner + 0x54) = 0;
        Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xb, 0);
    }
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_ClawWindupTick);
}
