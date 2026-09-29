/* Clients: copies a received member state block into the sync block and marks it received. */

#include "game/engine.h"

extern int data_ov022_020b2ea4;
extern void MI_CpuCopy8(unsigned short *arg0, unsigned short *arg1, unsigned int arg2);
void func_ov022_020897dc(unsigned short *arg0, unsigned int arg1) {
    int p = data_ov022_020b2ea4;
    if (Session_GetLocalPlayerIndex() == 0) return;
    MI_CpuCopy8(arg0, (unsigned short *)(p + 0x14), arg1);
    *(char *)(p + 0xd4) = 1;
}
