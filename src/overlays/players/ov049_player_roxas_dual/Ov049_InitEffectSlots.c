/* Initialises the character's effect slot: clears its state, registers its effect sequence for the
 * owner's palette slot, allocates its slot class and creates the sub-object. */

extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern void Ov049_CreateSubObject(int a);
extern int data_ov049_020b4d00;
extern int data_ov049_020b4c98;

typedef struct { int w[5]; } Params;
extern Params data_ov049_020b4b44;

void Ov049_InitEffectSlots(int self) {
    int base = *(int *)&data_ov049_020b4d00;
    Params p;
    char *blk;
    *(signed char *)(base + 0x2000 + 0xcfc) = 0;
    blk = (char *)(base + 0xfc + 0x2c00);
    RegisterSeqAndInit((int)(blk + 4), &data_ov049_020b4c98, 1,
                  *(unsigned char *)(base + 9) + 7);
    p = data_ov049_020b4b44;
    Ov022_AllocateSlotWithClass(self + 0x248 + 0x2400, *(unsigned char *)(self + 9), 5, &p);
    Ov049_CreateSubObject(base);
}
