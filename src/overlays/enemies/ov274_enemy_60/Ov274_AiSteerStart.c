/* Unless the gate byte at *(child+0xc) is set, pose the sub-node at (*child)+0x3b4 (ov107
 * mode 0,1) and the main node (ov107 mode 2,1), then register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov274_SteerHeadingGate(int);
void Ov274_AiSteerStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)*(int *)(child + 0xc) != 0) return;
    Ov107_StartAnim(*(int *)(*(int *)child + 0x3b4), 0, 1);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 2, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov274_SteerHeadingGate);
}
