/* Ov279_AiDispatchAction -- ov279's move dispatcher.
 *
 * Same shape as Ov146_AiDispatchAction: the reset ORs 0x40 into the hw60 hi-byte and then clears 0x8e
 * from it, and only drops bit 0 of the halfword at +0x1ae. Unlike ov146 the id is copied to +0x1c6
 * LATE, after the flag work.
 *
 * Case 3 is out of order (after 4) as everywhere else.
 *
 * Form notes (codegen-cracks.md): `hi |= 0x40` has no lsl#0x10/lsr#0x10 trunc pair so it needs the
 * explicit extract/reassemble, while `hi &= ~0x8e` has one and takes the bitfield form -- the same
 * two opposite forms back to back as in ov146. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov279_stateSetFlagsClearBit(void);
extern void Ov279_SpawnEffect48SetTurnRate(void);
extern void Ov279_SetPoseThenAdvanceSlot(void);
extern void Ov279_FaceTargetLookAt(void);
extern void Ov279_SpawnEffect4aReconfigureFlags(void);
extern void Ov279_AiStep_PickLandingPoint(void);
extern void Ov279_SetPose4ThenAdvanceSlot(void);
extern void Ov279_SetPoseThenAdvanceSlot_2(void);
extern void Ov279_AiEnterBackOff(void);
extern void Ov279_EnterBite(void);
extern void Ov279_EnterLunge(void);
extern void Ov279_ConfigHw60Action49ThenAdvance(void);

void Ov279_AiDispatchAction(int self) {
    int *ctx;
    unsigned short v;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        v = *(unsigned short *)(ctx[0] + 0x60);
        *(unsigned short *)(ctx[0] + 0x60) =
            (unsigned short)((v & ~0xff00)
                             | (((((unsigned int)v << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0x8e;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~1;
        ((B8 *)(*(int *)(ctx[0] + 0x388) + 8))->f |= 1;
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov279_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov279_SpawnEffect48SetTurnRate);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov279_SetPoseThenAdvanceSlot);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov279_FaceTargetLookAt);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov279_SpawnEffect4aReconfigureFlags);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov279_AiStep_PickLandingPoint);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov279_SetPose4ThenAdvanceSlot);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov279_SetPoseThenAdvanceSlot_2);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov279_AiEnterBackOff);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov279_EnterBite);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov279_EnterLunge);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov279_ConfigHw60Action49ThenAdvance);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
