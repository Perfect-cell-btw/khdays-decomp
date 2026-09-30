/* Ov235_AiDispatchAction -- ov235's move dispatcher.
 *
 * Its reset zeroes more than the others: the byte at ctx+0x64 and the word at ctx+0x80, and then a
 * three-word block on the owner at +0x64/+0x68/+0x6c seeded {0, 0x1800, 0} -- a vector whose
 * middle component is the only one set, so 0x1800 is a height or a Y speed.
 *
 * The "nothing queued" case RETURNS outright (a predicated `popeq`) rather than falling into the
 * shared -1 store, as in ov208/ov213/ov257.
 *
 * Case 3 is out of order (last) as everywhere else.
 *
 * The hw60 write HAS the lsl#0x10/lsr#0x10 trunc pair -> bitfield form; the +8 field is
 * byte-in-word. See codegen-cracks.md. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov235_stateSetFlagsClearBit(void);
extern void Ov235_EnterState1b(void);
extern void Ov235_AiEnterDecide(void);
extern void Ov235_AiEnterTakeOff(void);
extern void Ov235_CheckTarget(void);
extern void Ov235_AiEnterGlide(void);
extern void Ov235_AiEnterGlideB(void);
extern void Ov235_AiEnterBite(void);
extern void Ov235_EnterState10(void);
extern void Ov235_AiEnterGlideC(void);
extern void Ov235_EnterState15(void);
extern void Ov235_EnterState18(void);
extern void Ov235_KickMotionSetReadyFlags(void);

void Ov235_AiDispatchAction(int self) {
    int *ctx;
    int owner;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) == -1) {
        return;
    }

    *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
    *(unsigned char *)((char *)ctx + 0x64) = 0;
    ctx[0x20] = 0;

    /* The three stores go through a local. Written as `*(int *)(ctx[0] + 0x64) = 0;` etc. mwcc
     * re-reads ctx[0] before each one -- a store through ctx[0] could alias *ctx itself, so it
     * cannot keep the value. The ROM loads it once; a local says the address is fixed. */
    owner = ctx[0];
    *(int *)(owner + 0x64) = 0;
    *(int *)(owner + 0x68) = 0x1800;
    *(int *)(owner + 0x6c) = 0;
    ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xde;
    *(unsigned short *)(ctx[0] + 0x1ae) &= ~1;
    ((B8 *)(*(int *)(ctx[0] + 0x39c) + 8))->f |= 1;

    switch (*(signed char *)(ctx[0] + 0x1c6)) {
    case 0:
        SetIndexedSlot(self, 1, Ov235_stateSetFlagsClearBit);
        break;
    case 1:
        SetIndexedSlot(self, 1, Ov235_EnterState1b);
        break;
    case 2:
        SetIndexedSlot(self, 1, Ov235_AiEnterDecide);
        break;
    case 4:
        SetIndexedSlot(self, 1, Ov235_AiEnterTakeOff);
        break;
    case 5:
        SetIndexedSlot(self, 1, Ov235_CheckTarget);
        break;
    case 6:
        SetIndexedSlot(self, 1, Ov235_AiEnterGlide);
        break;
    case 7:
        SetIndexedSlot(self, 1, Ov235_AiEnterGlideB);
        break;
    case 8:
        SetIndexedSlot(self, 1, Ov235_AiEnterBite);
        break;
    case 9:
        SetIndexedSlot(self, 1, Ov235_EnterState10);
        break;
    case 10:
        SetIndexedSlot(self, 1, Ov235_AiEnterGlideC);
        break;
    case 11:
        SetIndexedSlot(self, 1, Ov235_EnterState15);
        break;
    case 12:
        SetIndexedSlot(self, 1, Ov235_EnterState18);
        break;
    case 3:
        SetIndexedSlot(self, 1, Ov235_KickMotionSetReadyFlags);
        break;
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
