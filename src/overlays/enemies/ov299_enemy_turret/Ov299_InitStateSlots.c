/* Initialises the actor's AI node: action 0, nothing pending, its position pointer and its three
 * step handlers. */

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov299_CommitSubStateAndReset(void);
extern void Ov299_AiSlot2NoOp(void);
extern void Ov299_AiStep_QueueStoredActionIfActive(void);

void Ov299_InitStateSlots(int *node)
{
    int *state = (int *)node[1];

    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    state[1] = *state + 0xb0;
    SetIndexedSlot(node, 1, Ov299_AiStep_QueueStoredActionIfActive);
    SetIndexedSlot(node, 0, Ov299_CommitSubStateAndReset);
    SetIndexedSlot(node, 2, Ov299_AiSlot2NoOp);
}
