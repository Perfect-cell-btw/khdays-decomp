/* Move dispatcher (brain slot 0) of the ov237 actor: a pending next move (+0x1c7) clears the per-move
 * state (+0x58 set; the actor's +0x4b4, +0x49e and the +0x57 hit mask cleared), becomes 0xd (separate)
 * when the pair is split (alone with +0x4b0 and no +0x494 grab once idle, or linked to a busy partner)
 * unless +0x4c0 forbids it, and becomes the current move (+0x1c6). A linked actor clears bits 1, 2, 6
 * and 7 of its +0x60 high byte and bit 0 of +0x1ae, sets bit 0 and clears bit 1 of the +0x488 rig's
 * flags and clears bit 6 of the brain's +0x60 byte. Brain slot 1 then runs the move's entry
 * (move 3 also drops +0x4c0), and the next move is cleared. */

#include "nitro/types.h"

typedef struct { unsigned f : 8; } B8;

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov237_stateSetFlagsClearBit(void);
extern void Ov237_StartMove(void);
extern void Ov237_AiEnterPlay(void);
extern void Ov237_AiEnterPoseChain(void);
extern void Ov237_AiEnterLungeWindup(void);
extern void Ov237_AiEnterThrow(void);
extern void Ov237_EnterCharge(void);
extern void Ov237_EnterMove7(void);
extern void Ov237_EnterStagger(void);
extern void Ov237_ReleaseGrab(void);
extern void Ov237_AiEnterCombo(void);
extern void Ov237_AiStep_SetFlags3AndEnd(void);

void Ov237_MoveDispatch(int *node)
{
    int *state = (int *)node[1];

    if (*(signed char *)(*state + 0x1c7) != -1) {
        state[0x16] = 1;
        *(int *)(*state + 0x4b4) = 0;
        *(u8 *)(*state + 0x49e) = 0;
        *((u8 *)state + 0x57) = 0;
        if (*(int *)(*state + 0x4c0) == 0) {
            if (*(int *)(*state + 0x4ac) == 0 && *(int *)(*state + 0x4b0) != 0 &&
                *(int *)(*state + 0x494) == 0 && *(u8 *)(state[1] + 0xad) == 0) {
                *(signed char *)(*state + 0x1c7) = 0xd;
            }
            if (*(int *)(*state + 0x4ac) != 0 && *(int *)(*state + 0x494) == 0 &&
                *(int *)(*(int *)(*state + 0x4a4) + 0x4b0) != 0) {
                *(signed char *)(*state + 0x1c7) = 0xd;
            }
        }
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        if (*(int *)(*state + 0x4ac) != 0) {
            {
                u16 hw = *(u16 *)(*state + 0x60);

                *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
                    (((unsigned int)(unsigned short)((((unsigned int)hw << 0x10) >> 0x18) & ~0xc6) << 0x18) >> 0x10);
            }
            *(u16 *)(*state + 0x1ae) &= ~1;
            ((B8 *)(*(int *)(*state + 0x488) + 8))->f |= 1;
            ((B8 *)(*(int *)(*state + 0x488) + 8))->f &= ~2;
            {
                u16 hw = *(u16 *)(state + 0x18);

                *(u16 *)(state + 0x18) = (hw & ~0xff00) |
                    (((unsigned int)(unsigned short)((((unsigned int)hw << 0x10) >> 0x18) & ~0x40) << 0x18) >> 0x10);
            }
        }
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov237_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov237_StartMove);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov237_AiEnterPlay);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov237_AiEnterPoseChain);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov237_AiEnterLungeWindup);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov237_AiEnterThrow);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov237_EnterCharge);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov237_EnterMove7);
            break;
        case 10:
            SetIndexedSlot(node, 1, Ov237_EnterStagger);
            break;
        case 12:
            SetIndexedSlot(node, 1, Ov237_ReleaseGrab);
            break;
        case 13:
            SetIndexedSlot(node, 1, Ov237_AiEnterCombo);
            break;
        case 3:
            *(int *)(*state + 0x4c0) = 0;
            SetIndexedSlot(node, 1, Ov237_AiStep_SetFlags3AndEnd);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
