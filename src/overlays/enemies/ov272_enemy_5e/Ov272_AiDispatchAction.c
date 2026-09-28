/* Ov272_AiDispatchAction -- ov272's move dispatcher.
 *
 * Byte-identical reset and case order to Ov119_AiDispatchAction; only the handlers differ.
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
extern void Ov272_stateSetFlagsClearBit(void);
extern void Ov272_SpawnEffect48SetTurnRate(void);
extern void Ov272_SetPoseThenAdvanceSlot(void);
extern void Ov272_FaceTargetLookAt(void);
extern void Ov272_SpawnEffect4aReconfigureFlags(void);
extern void Ov272_AiStep_PickLandingPoint(void);
extern void Ov272_SetPose4ThenAdvanceSlot(void);
extern void Ov272_SetPoseThenAdvanceSlot_2(void);
extern void Ov272_AiEnterBackOff(void);
extern void Ov272_EnterBite(void);
extern void Ov272_EnterLunge(void);
extern void Ov272_ConfigHw60Action49ThenAdvance(void);

void Ov272_AiDispatchAction(int self) {
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
            SetIndexedSlot(self, 1, Ov272_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov272_SpawnEffect48SetTurnRate);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov272_SetPoseThenAdvanceSlot);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov272_FaceTargetLookAt);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov272_SpawnEffect4aReconfigureFlags);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov272_AiStep_PickLandingPoint);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov272_SetPose4ThenAdvanceSlot);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov272_SetPoseThenAdvanceSlot_2);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov272_AiEnterBackOff);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov272_EnterBite);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov272_EnterLunge);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov272_ConfigHw60Action49ThenAdvance);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
