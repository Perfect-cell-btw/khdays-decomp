/* Zero the global object slot header (base=*data_ov033_020b4b80+0x2c2c) and init the 6+1 sub-object
 * slots (base+0xc, then 6x stride 0x110) via RegisterSeqAndInit, seeding per-slot counter 0x1c-i.
 * x4 ov033/051/071/089. */

extern void RegisterSeqAndInit();
extern void *data_ov051_020b7380;
extern void *data_ov051_020b734c;
extern void *data_ov051_020b7360;

void Ov051_initSubObjectSlots(void)
{
    int i;
    char *slot;
    char *base;
    int zero;
    char *obj = (char *)*(int *)&data_ov051_020b7380;
    base = obj + 0x2c2c;
    *(int *)(obj + 0x2c2c) = 0;
    *(int *)(base + 4) = 0;
    *(int *)(base + 8) = 0;
    RegisterSeqAndInit(base + 0xc, &data_ov051_020b734c, 1, ((unsigned char *)obj)[9] + 7);
    i = 0;
    slot = base + 0x120;
    zero = 0;
    do {
        RegisterSeqAndInit(slot, &data_ov051_020b7360, 1, ((unsigned char *)obj)[9] + 7);
        *(int *)(base + 0x11c) = 0x1c - i;
        i++;
        *(int *)(base + 0x118) = zero;
        slot += 0x110;
        base += 0x110;
    } while (i < 6);
}
