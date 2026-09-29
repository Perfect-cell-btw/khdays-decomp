/* Clear +0x24, play the anim (ov107 mode 0xa), clear the +0x50 byte, fire
 * ov107_020c5af8(*child, 0x116, 0xb, *(child)+0x3bc + 4) and register the handler. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov206_StompTick(int);
void Ov206_AiEnterStomp(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x24) = 0;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0xa, 0);
    *(signed char *)(child + 0x50) = 0;
    Ov107_BuildAndSendUpdate(*(int *)child, 0x116, 0xb, *(int *)(*(int *)child + 0x3bc) + 4);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov206_StompTick);
}
