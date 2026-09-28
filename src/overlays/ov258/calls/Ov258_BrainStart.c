/* Brain start of the ov258 actor: move 1 with no next move, the +0x38 timer rolls between the +0x224
 * and +0x228 bounds, the +0xc point is the actor's +0xb0 pose, the +0x58 sound bank is 0x180 with a
 * +0x460 partner (else 0x17b), +0x56 is cleared to -1 and the three brain slots get 020cd748 (0),
 * 020cdbb8 (1) and 020cd9b0 (2). */
extern int RandNextScaled(int bound);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov258_MoveDispatch(void);
extern void Ov258_AiFinishWithParts(void);
extern void Ov258_TurnTick(void);

void Ov258_BrainStart(int *node)
{
    int *state = (int *)node[1];

    *(signed char *)(*state + 0x1c6) = 1;
    *(signed char *)(*state + 0x1c7) = -1;
    {
        int lo = *(int *)(*state + 0x224);
        int span = *(int *)(*state + 0x228) - lo;

        if (span < 0) {
            span = -span;
        }
        state[0xe] = lo + RandNextScaled(span + 1);
    }
    state[3] = *state + 0xb0;
    *(short *)(state + 0x16) = *(int *)(*state + 0x460) != 0 ? 0x180 : 0x17b;
    *((signed char *)state + 0x56) = -1;
    SetIndexedSlot(node, 0, Ov258_MoveDispatch);
    SetIndexedSlot(node, 1, Ov258_AiFinishWithParts);
    SetIndexedSlot(node, 2, Ov258_TurnTick);
}
