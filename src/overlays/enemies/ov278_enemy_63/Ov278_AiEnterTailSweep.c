/* Clear +0x28, wipe the +0x4c scratch, kick anim 0xc, arm the 0x166/0x11 timer, clear the
 * +0x51 flag, then dispatch 020d000c. */

#include "game/enemy_common.h"

extern void MI_CpuFill8(void *, int, int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov278_TailSweepTick(int);
void Ov278_AiEnterTailSweep(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x28) = 0;
    MI_CpuFill8((void *)(owner + 0x4c), 0, 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xc, 0);
    Ov107_BuildAndSendUpdate(*(int *)owner, 0x166, 0x11, *(int *)(owner + 0x38));
    *(unsigned char *)(owner + 0x51) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov278_TailSweepTick);
}
