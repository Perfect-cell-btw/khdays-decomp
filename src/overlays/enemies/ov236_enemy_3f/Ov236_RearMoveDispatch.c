/* Ov236_RearMoveDispatch -- the second rider set's move dispatcher (the twin of 020d1d98 for the
 * owner whose two sub-objects sit at +0x3c0, with the paired heights at +0x3d0 and the override
 * flag at +0x3d4). A pending move (+0x1c7 != -1) becomes current (+0x1c6), bits 1-2 and 6-7 of
 * the +0x60 high byte and bits 0-1 of +0x1ae clear, each sub-object's visibility is recomputed
 * (bit 1 forced by the flag or cleared by a positive height; bit 0 shown for a positive height,
 * else hidden with bit 1) and the move's handler is registered; move 8 also puts +0x1ae bit 0
 * back. The pending slot is always reset to -1. */
typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

typedef struct {
    char reserved[0x3c0];
    int slots[2];
    int reserved2[2];
    short heights[2];
    int useAlt : 1;
} Owner;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov236_SetFlagsC6ClearBits_b(void);
extern void Ov236_RidersB_AiEnterInert(void);
extern void Ov236_RidersB_AiPlayIdleAndEnd(void);
extern void Ov236_RidersB_AiEnterFire(void);
extern void Ov236_RidersB_AiPlayAnim12AndEnd(void);
extern void Ov236_SetPose4ThenAdvanceSlot_2(void);
extern void Ov236_RidersB_AiEnterSeek(void);
extern void Ov236_RidersB_AiEnterStalk(void);
extern void Ov236_EnterBuckB(void);
extern void Ov236_ReleaseRiderB(void);
extern void Ov236_RidersB_AiEnterStampWalk(void);
extern void Ov236_RidersB_AiEnterFinish(void);

void Ov236_RearMoveDispatch(int self) {
    int *ctx;
    int i;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~3;

        for (i = 0; i < 2; i++) {
            if (((Owner *)ctx[0])->useAlt) {
                ((B8 *)(((Owner *)ctx[0])->slots[i] + 8))->f |= 2;
            } else if (((Owner *)ctx[0])->heights[i] > 0) {
                ((B8 *)(((Owner *)ctx[0])->slots[i] + 8))->f &= ~2;
            }

            if (((Owner *)ctx[0])->heights[i] > 0) {
                ((B8 *)(((Owner *)ctx[0])->slots[i] + 8))->f |= 1;
            } else {
                ((B8 *)(((Owner *)ctx[0])->slots[i] + 8))->f &= ~1;
                ((B8 *)(((Owner *)ctx[0])->slots[i] + 8))->f |= 2;
            }
        }

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov236_SetFlagsC6ClearBits_b);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov236_RidersB_AiEnterInert);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov236_RidersB_AiPlayIdleAndEnd);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov236_RidersB_AiEnterFire);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov236_RidersB_AiPlayAnim12AndEnd);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov236_RidersB_AiEnterStampWalk);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov236_RidersB_AiEnterFinish);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov236_SetPose4ThenAdvanceSlot_2);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov236_RidersB_AiEnterSeek);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov236_RidersB_AiEnterStalk);
            break;
        case 8:
            *(unsigned short *)(ctx[0] + 0x1ae) |= 1;
            SetIndexedSlot(self, 1, Ov236_EnterBuckB);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov236_ReleaseRiderB);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
