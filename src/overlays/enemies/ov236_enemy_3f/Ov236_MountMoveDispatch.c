/* Ov236_MountMoveDispatch -- the mount's move dispatcher. A pending move (+0x1c7 != -1) becomes current
 * (+0x1c6): bits 1-2 and 6-7 of the +0x60 high byte and bits 0-1 of +0x1ae clear, the +0x3a4 /
 * +0x3a8 shapes are armed (bit 0) with only the first flagged (bit 1), +0x54 clears, and the
 * move's handler is registered. Moves 2 and 4-8 also hand moves 2-7 to each rider controller
 * (+0x3b4 front / +0x3b8 rear) that is free (its +0x1ac bit 1 clear) and present (+0x3c0 / +0x3d4
 * bit 0); move 9 instead sends each free, absent rider move 8 with +0x1ae bit 0 set. The pending
 * slot is always reset to -1. */
#include "nitro/types.h"
typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;
typedef struct {
    unsigned f : 8;
} B8;
typedef struct {
    int b0 : 1;
} Flag1;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov236_stateSetFlagsClearBit(void);
extern void Ov236_AiEnterRest(void);
extern void Ov236_EnterRoll(void);
extern void Ov236_AiPrepareJump(void);
extern void Ov236_AiEnterTailSweep(void);
extern void Ov236_EnterCharge(void);
extern void Ov236_ChargeEnter(void);
extern void Ov236_AiEnterRoar(void);
extern void Ov236_AiEnterSurprised(void);
extern void Ov236_AiEnterDown(void);
extern void Ov236_AiHidePartsAndEnd(void);
extern void Ov236_AiEnterDash(void);
extern void Ov236_AiEnterLunge(void);

void Ov236_MountMoveDispatch(int self) {
    int *ctx;
    int front;
    int rear;
    int frontFree;
    int rearFree;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        front = *(int *)(ctx[0] + 0x3b4);
        rear = *(int *)(ctx[0] + 0x3b8);
        frontFree = (*(u16 *)(front + 0x1ac) & 2) == 0;
        rearFree = (*(u16 *)(rear + 0x1ac) & 2) == 0;
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xc6;
        *(u16 *)(ctx[0] + 0x1ae) &= ~3;
        ((B8 *)(*(int *)(ctx[0] + 0x3a4) + 8))->f |= 1;
        ((B8 *)(*(int *)(ctx[0] + 0x3a8) + 8))->f |= 1;
        ((B8 *)(*(int *)(ctx[0] + 0x3a4) + 8))->f |= 2;
        ((B8 *)(*(int *)(ctx[0] + 0x3a8) + 8))->f &= ~2;
        *(int *)(ctx[0] + 0x54) = 0;
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov236_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov236_AiEnterRest);
            break;
        case 2:
            if (frontFree && ((Flag1 *)(front + 0x3c0))->b0) {
                *(signed char *)(*(int *)(ctx[0] + 0x3b4) + 0x1c7) = 2;
            }
            if (rearFree && ((Flag1 *)(rear + 0x3d4))->b0) {
                *(signed char *)(*(int *)(ctx[0] + 0x3b8) + 0x1c7) = 2;
            }
            SetIndexedSlot(self, 1, Ov236_EnterRoll);
            break;
        case 4:
            if (frontFree && ((Flag1 *)(front + 0x3c0))->b0) {
                *(signed char *)(*(int *)(ctx[0] + 0x3b4) + 0x1c7) = 3;
            }
            if (rearFree && ((Flag1 *)(rear + 0x3d4))->b0) {
                *(signed char *)(*(int *)(ctx[0] + 0x3b8) + 0x1c7) = 3;
            }
            SetIndexedSlot(self, 1, Ov236_AiPrepareJump);
            break;
        case 5:
            if (frontFree && ((Flag1 *)(front + 0x3c0))->b0) {
                *(signed char *)(*(int *)(ctx[0] + 0x3b4) + 0x1c7) = 4;
            }
            if (rearFree && ((Flag1 *)(rear + 0x3d4))->b0) {
                *(signed char *)(*(int *)(ctx[0] + 0x3b8) + 0x1c7) = 4;
            }
            SetIndexedSlot(self, 1, Ov236_AiEnterTailSweep);
            break;
        case 6:
            if (frontFree && ((Flag1 *)(front + 0x3c0))->b0) {
                *(signed char *)(*(int *)(ctx[0] + 0x3b4) + 0x1c7) = 5;
            }
            if (rearFree && ((Flag1 *)(rear + 0x3d4))->b0) {
                *(signed char *)(*(int *)(ctx[0] + 0x3b8) + 0x1c7) = 5;
            }
            SetIndexedSlot(self, 1, Ov236_AiEnterDash);
            break;
        case 7:
            if (frontFree && ((Flag1 *)(front + 0x3c0))->b0) {
                *(signed char *)(*(int *)(ctx[0] + 0x3b4) + 0x1c7) = 6;
            }
            if (rearFree && ((Flag1 *)(rear + 0x3d4))->b0) {
                *(signed char *)(*(int *)(ctx[0] + 0x3b8) + 0x1c7) = 6;
            }
            SetIndexedSlot(self, 1, Ov236_AiEnterLunge);
            break;
        case 8:
            if (frontFree && ((Flag1 *)(front + 0x3c0))->b0) {
                *(signed char *)(*(int *)(ctx[0] + 0x3b4) + 0x1c7) = 7;
            }
            if (rearFree && ((Flag1 *)(rear + 0x3d4))->b0) {
                *(signed char *)(*(int *)(ctx[0] + 0x3b8) + 0x1c7) = 7;
            }
            SetIndexedSlot(self, 1, Ov236_EnterCharge);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov236_ChargeEnter);
            break;
        case 9:
            if (frontFree && !((Flag1 *)(front + 0x3c0))->b0) {
                *(u16 *)(*(int *)(ctx[0] + 0x3b4) + 0x1ae) |= 1;
                *(signed char *)(*(int *)(ctx[0] + 0x3b4) + 0x1c7) = 8;
            }
            if (rearFree && !((Flag1 *)(rear + 0x3d4))->b0) {
                *(u16 *)(*(int *)(ctx[0] + 0x3b8) + 0x1ae) |= 1;
                *(signed char *)(*(int *)(ctx[0] + 0x3b8) + 0x1c7) = 8;
            }
            SetIndexedSlot(self, 1, Ov236_AiEnterRoar);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov236_AiEnterSurprised);
            break;
        case 12:
            SetIndexedSlot(self, 1, Ov236_AiEnterDown);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov236_AiHidePartsAndEnd);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
