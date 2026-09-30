/* AI dispatcher: when an action is pending, makes it current and installs its step handler. */

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov299_AiStep_QueueStoredActionIfActive(void);
extern void Ov299_SetRandomFieldFromScaled390(void);

void Ov299_CommitSubStateAndReset(int *node)
{
    int *state = (int *)node[1];
    signed char next = *(signed char *)(*state + 0x1c7);

    if (next == -1) {
        return;
    }
    *(signed char *)(*state + 0x1c6) = next;
    switch (*(signed char *)(*state + 0x1c6)) {
    case 0:
        SetIndexedSlot(node, 1, Ov299_AiStep_QueueStoredActionIfActive);
        break;
    case 2:
        SetIndexedSlot(node, 1, Ov299_SetRandomFieldFromScaled390);
        break;
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
