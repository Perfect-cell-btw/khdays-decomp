/* Unless busy, kick anim 0xe, arm the 020c5af8 timer, then dispatch. */

#include "game/enemy_common.h"

extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov237_LandTick(int);
void Ov237_AiEnterLand(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xe, 0);
    Ov107_BuildAndSendUpdate(*(int *)owner, 0x12d, 0xd, *(int *)(owner + 0x38));
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov237_LandTick);
}
