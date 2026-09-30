/* Unless the busy byte at *(*child+0x384)+0xad is set, play the anim (ov107 mode 1,1) and dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov229_DashTick(int);
void Ov229_AiDashWindup(int param_1) {
    int obj = *(int *)*(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(obj + 0x384) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)obj, 1, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov229_DashTick);
}
