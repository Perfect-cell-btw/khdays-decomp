extern void SetIndexedSlot(void *self, int idx, void *cb);
extern void Ov212_ReleaseSubObjectsAndAdvance(void);
extern void Ov212_AiDispatchAction(void);
extern void Ov212_FrameStep(void);

struct b8 { unsigned f : 8; };

/* Enter/reset this actor's state (and its byte-identical twins). Clear the give-up byte
 * (+0x1c6) and arm the target slot (+0x1c7 = -1 = none), then drop the "active"
 * bit 0 on each of the 3 tracked sub-objects (owner[0x4cc..0x4d4]), point the
 * work pointer at owner+0xb0, raise flags 6 in the hi byte of the hw60 word, and
 * register the three phase callbacks. */
void Ov212_BeginPhaseSequence(void *self) {
    int *ctx = *(int **)((char *)self + 4);
    int i;
    unsigned short v;

    *(char *)(*ctx + 0x1c6) = 0;
    *(signed char *)(*ctx + 0x1c7) = -1;
    for (i = 0; i < 3; i++) {
        /* 0x133 * 4 == 0x4cc: indexed off the owner base, which is what keeps the
         * scale in the load (`add r2,r2,r1,lsl #2`) instead of strength-reducing
         * it into a second byte-offset induction variable. */
        ((struct b8 *)(((int *)*ctx)[i + 0x133] + 8))->f &= ~1;
    }
    ctx[2] = *ctx + 0xb0;
    v = *(unsigned short *)(*ctx + 0x60);
    *(unsigned short *)(*ctx + 0x60) =
        (unsigned short)((v & ~0xff00) | (((((unsigned int)v << 0x10) >> 0x18 | 6) << 0x18) >> 0x10));
    SetIndexedSlot(self, 1, Ov212_ReleaseSubObjectsAndAdvance);
    SetIndexedSlot(self, 0, Ov212_AiDispatchAction);
    SetIndexedSlot(self, 2, Ov212_FrameStep);
}
