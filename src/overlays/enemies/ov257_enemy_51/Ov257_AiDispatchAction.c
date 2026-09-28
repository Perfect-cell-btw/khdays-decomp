/* Ov257_AiDispatchAction -- ov257's move dispatcher.
 *
 * Case 1 rewrites the id to 2 and FALLS THROUGH into case 2 -- the case-2 table entry points 8
 * bytes into case 1's body, past the store. Unlike ov213's equivalent, this store is NOT dead: the
 * copy at +0x1c6 is what everything downstream reads, and only +0x1c7 gets cleared at the end. So
 * move 1 really does become move 2.
 *
 * The "nothing queued" case RETURNS outright (a predicated `popeq`) rather than falling into the
 * shared -1 store, as in ov208/ov213.
 *
 * The reset clears the byte at ctx+0x77 and the word at ctx+0x58, drops 0xce from the hw60
 * hi-byte and bit 0 of the halfword at +0x1ae, and sets bit 0 on the sub-object at ctx[0]+0x3b4.
 *
 * The hw60 write HAS the lsl#0x10/lsr#0x10 trunc pair -> bitfield form; the +8 field is
 * byte-in-word. See codegen-cracks.md.
 */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

/* The move slots are real fields: +0x1c6 has TWO writers (the reset copy and case 1s rewrite) and
 * pointer arithmetic makes mwcc CSE a partial address and hoist it out of the switch. */
typedef struct {
    char reserved[0x1c6];
    signed char cur;
    signed char queued;
} Owner;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov257_stateSetFlagsClearBit(void);
extern void Ov257_AiEnterDecide(void);
extern void Ov257_AiEnterTakeOff(void);
extern void Ov257_DiveEnterTick(void);
extern void Ov257_AiEnterGlide(void);
extern void Ov257_AiEnterGlideB(void);
extern void Ov257_AiEnterBite(void);
extern void Ov257_GroundStrikeEnterTick(void);
extern void Ov257_AiEnterWhirlFinish(void);
extern void Ov257_EnterTick(void);
extern void Ov257_SwoopEnterTick(void);
extern void Ov257_TakeOffEnterTick(void);
extern void Ov257_KickMotionSetReadyFlags(void);

void Ov257_AiDispatchAction(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (((Owner *)ctx[0])->queued == -1) {
        return;
    }

    *(unsigned char *)((char *)ctx + 0x77) = 0;
    ctx[0x16] = 0;
    ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xce;
    *(unsigned short *)(ctx[0] + 0x1ae) &= ~1;
    ((B8 *)(*(int *)(ctx[0] + 0x3b4) + 8))->f |= 1;
    ((Owner *)ctx[0])->cur = ((Owner *)ctx[0])->queued;

    switch (((Owner *)ctx[0])->cur) {
    case 0:
        SetIndexedSlot(self, 1, Ov257_stateSetFlagsClearBit);
        break;
    case 1:
        ((Owner *)ctx[0])->cur = 2;
        /* fall through */
    case 2:
        SetIndexedSlot(self, 1, Ov257_AiEnterDecide);
        break;
    case 4:
        SetIndexedSlot(self, 1, Ov257_AiEnterTakeOff);
        break;
    case 5:
        SetIndexedSlot(self, 1, Ov257_DiveEnterTick);
        break;
    case 6:
        SetIndexedSlot(self, 1, Ov257_AiEnterGlide);
        break;
    case 7:
        SetIndexedSlot(self, 1, Ov257_AiEnterGlideB);
        break;
    case 8:
        SetIndexedSlot(self, 1, Ov257_AiEnterBite);
        break;
    case 9:
        SetIndexedSlot(self, 1, Ov257_GroundStrikeEnterTick);
        break;
    case 10:
        SetIndexedSlot(self, 1, Ov257_AiEnterWhirlFinish);
        break;
    case 11:
        SetIndexedSlot(self, 1, Ov257_EnterTick);
        break;
    case 12:
        SetIndexedSlot(self, 1, Ov257_SwoopEnterTick);
        break;
    case 13:
        SetIndexedSlot(self, 1, Ov257_TakeOffEnterTick);
        break;
    case 3:
        SetIndexedSlot(self, 1, Ov257_KickMotionSetReadyFlags);
        break;
    }

    ((Owner *)ctx[0])->queued = -1;
}
