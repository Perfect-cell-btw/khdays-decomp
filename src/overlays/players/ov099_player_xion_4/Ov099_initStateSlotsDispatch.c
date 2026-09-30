/* Initialises the character's effect state: links the owner, registers the two effect sequences
 * (the second one depends on the owner's mode), allocates the owner's slot class and initialises
 * the eight emitter objects. */

struct s5 { int a, b, c, d, e; };
extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern void Ov099_initEightSubSlots(int a);
extern int gOv099RoxasLiE1PackPath[];
extern int gOv099RoxasLiE2PackPath[];
extern int gOv099XionLiE0PackPath[];
extern struct s5 data_ov099_020bca74;
void Ov099_initStateSlotsDispatch(int p1, int state) {
    struct s5 buf;
    *(int *)(state + 0xdb4) = p1;
    *(int *)(state + 0xc) = 0;
    *(int *)(state + 0x14) = 0;
    *(int *)(state + 0x230) = 0;
    RegisterSeqAndInit(state + 0x18, gOv099RoxasLiE1PackPath, 1, *(unsigned char *)(p1 + 9) + 7);
    if (*(int *)(p1 + 0xc) == 0)
        RegisterSeqAndInit(state + 0x128, gOv099RoxasLiE2PackPath, 1, *(unsigned char *)(p1 + 9) + 7);
    else
        RegisterSeqAndInit(state + 0x128, gOv099XionLiE0PackPath, 1, *(unsigned char *)(p1 + 9) + 7);
    buf = data_ov099_020bca74;
    buf.b = 4;
    Ov022_AllocateSlotWithClass(p1 + 0x2648, *(unsigned char *)(p1 + 9), 5, &buf);
    Ov099_initEightSubSlots(state);
}
