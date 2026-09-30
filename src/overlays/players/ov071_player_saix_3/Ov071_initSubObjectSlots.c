/* Zero the global object slot header (base=*data_ov033_020b4b80+0x2c2c) and init the 6+1 sub-object
 * slots (base+0xc, then 6x stride 0x110) via RegisterSeqAndInit, seeding per-slot counter 0x1c-i.
 * x4 ov033/051/071/089. */

#include "game/engine.h"

extern void *data_ov071_020b9a60;
extern void *gOv071SaixLiE1PackPath;
extern void *gOv071SaixLiE0PackPath;

void Ov071_initSubObjectSlots(void)
{
    int i;
    char *slot;
    char *base;
    int zero;
    char *obj = (char *)*(int *)&data_ov071_020b9a60;
    base = obj + 0x2c2c;
    *(int *)(obj + 0x2c2c) = 0;
    *(int *)(base + 4) = 0;
    *(int *)(base + 8) = 0;
    RegisterSeqAndInit(base + 0xc, &gOv071SaixLiE1PackPath, 1, ((unsigned char *)obj)[9] + 7);
    i = 0;
    slot = base + 0x120;
    zero = 0;
    do {
        RegisterSeqAndInit(slot, &gOv071SaixLiE0PackPath, 1, ((unsigned char *)obj)[9] + 7);
        *(int *)(base + 0x11c) = 0x1c - i;
        i++;
        *(int *)(base + 0x118) = zero;
        slot += 0x110;
        base += 0x110;
    } while (i < 6);
}
