/* Clears the four 0x104-byte and two 0x48-byte party buffers and their counters. */

#include "game/engine.h"

extern void MI_CpuFill8(void *dst, unsigned char val, unsigned int size);

extern unsigned char data_02042a1c[];
extern unsigned char gPartyMembers[];
extern unsigned char gPartyState[];
extern unsigned char data_0204c500[];

void PartyState_ResetBuffers(void) {
    int i;
    unsigned char *p;

    data_02042a1c[1] = 0;
    p = gPartyMembers;
    for (i = 0; i < 4; i++) {
        MI_CpuFill8(p, 0, 0x104);
        p += 0x104;
    }
    gPartyState[1] = 0;
    data_02042a1c[0] = 0;
    p = data_0204c500;
    for (i = 0; i < 2; i++) {
        MI_CpuFill8(p, 0, 0x48);
        p += 0x48;
    }
    PartyState_ClearHeldItem();
}
