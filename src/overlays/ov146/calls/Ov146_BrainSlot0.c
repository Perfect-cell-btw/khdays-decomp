/* Brain slot 0 of the ov146 actor: a pending visibility change (+0x18) is applied (1: guard flag set,
 * bit 7 of the +0x60 high byte clears and the +0x3ac shape shows; 0: the reverse, with next move 0)
 * and cleared; a queued next move becomes current and starts its slot-1 routine (0: 020cec08,
 * 1: 020cec24, 2: 020ceca0, 3: 020ced1c). The next move always clears. */
typedef unsigned short u16;
typedef struct { unsigned f : 8; } B8;

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov146_AiClearMoveVector(void);
extern void Ov146_stAdvanceState_ccedc(void);
extern void Ov146_SetPose4ThenAdvanceSlot_2(void);
extern void Ov146_stAdvanceState_ccedc_2(void);

void Ov146_BrainSlot0(int *node)
{
    int *state = (int *)node[1];

    switch (*((signed char *)state + 0x18)) {
    case 1:
        {
            u16 hw = *(u16 *)(*state + 0x60);
            *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
                ((((((unsigned int)hw << 0x10) >> 0x18) | 1) << 0x18) >> 0x10);
        }
        {
            u16 hw = *(u16 *)(*state + 0x60);
            *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
                (((unsigned int)(u16)((((unsigned int)hw << 0x10) >> 0x18) & ~0x80) << 0x18) >> 0x10);
        }
        ((B8 *)(*(int *)(*state + 0x3ac) + 8))->f |= 1;
        break;
    case 0:
        {
            u16 hw = *(u16 *)(*state + 0x60);
            *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
                (((unsigned int)(u16)((((unsigned int)hw << 0x10) >> 0x18) & ~1) << 0x18) >> 0x10);
        }
        {
            u16 hw = *(u16 *)(*state + 0x60);
            *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
                ((((((unsigned int)hw << 0x10) >> 0x18) | 0x80) << 0x18) >> 0x10);
        }
        ((B8 *)(*(int *)(*state + 0x3ac) + 8))->f &= ~1;
        *(signed char *)(*state + 0x1c7) = 0;
        break;
    }
    *((signed char *)state + 0x18) = -1;
    if (*(signed char *)(*state + 0x1c7) != -1) {
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov146_AiClearMoveVector);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov146_stAdvanceState_ccedc);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov146_SetPose4ThenAdvanceSlot_2);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov146_stAdvanceState_ccedc_2);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
