/* Start of the ov259 actor's brain: no move is current or pending (+0x1c6 = 0, +0x1c7 = -1), the
 * +0x404 shape hides, +0x10 points at the actor's +0xb0 anchor, +0x88 = 0x900, +0x8c = 0x1de20,
 * +0x94 = 30 and +0x64 = 0x5fa0, no move is queued (+0xad = -1), the jump is charged (+0x5c bit 0),
 * +0xa0 and +0x44 clear, bits 1-2 of the +0x60 high byte are set and the three slots take the
 * idle (020ce2a8), think (020cdef8) and watch (020ce184) handlers. */
typedef struct { unsigned f : 8; } B8;
struct Flags5c { unsigned charged : 1; };

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov259_stateSetFlagsClearBit(void);
extern void Ov259_AiDispatchAction(void);
extern void Ov259_WatchSlot(void);

void Ov259_StartBrain(int *node)
{
    int *state = (int *)node[1];

    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    ((B8 *)(*(int *)(*state + 0x404) + 8))->f &= ~1;
    state[4] = *state + 0xb0;
    state[0x22] = 0x900;
    *((signed char *)state + 0xad) = -1;
    state[0x23] = 0x1de20;
    state[0x25] = 0x1e;
    ((struct Flags5c *)(state + 0x17))->charged = 1;
    state[0x19] = 0x5fa0;
    state[0x28] = 0;
    state[0x11] = 0;
    {
        unsigned short hw = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 6) << 0x18) >> 0x10);
    }
    SetIndexedSlot(node, 1, Ov259_stateSetFlagsClearBit);
    SetIndexedSlot(node, 0, Ov259_AiDispatchAction);
    SetIndexedSlot(node, 2, Ov259_WatchSlot);
}
