/* Draws the character's effect block while the owner is shown: the six secondary slots, then the
 * main effect when it is active. */

extern void Ov033_DispatchWhenStateActive(int a);
extern void Gfx_SubmitCachedCommandBlock(void);
extern void GX_SendFifoWords(int a, int b, int c);
extern void Obj_InitChannelsAndRun(int a);

typedef struct { unsigned char b0 : 1; } Flags;

void Ov033_UpdateSlotsAndFlush(int self, int blk) {
    int i;
    char *p;
    if (!((Flags *)(self + 0x694))->b0) return;
    p = (char *)(blk + 0x118);
    for (i = 0; i < 6; i++, p += 0x110) {
        Ov033_DispatchWhenStateActive((int)p);
    }
    if (*(int *)blk != 1) return;
    Gfx_SubmitCachedCommandBlock();
    GX_SendFifoWords(0x17, blk + 0x8c, 0xc);
    Obj_InitChannelsAndRun(blk + 0x2c);
}
