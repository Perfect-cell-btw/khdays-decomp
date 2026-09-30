/* AI step: once the gate byte is clear, posts a pose and installs the queue-on-flag-clear step. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov120_AiStep_QueueAction2OnFlag48Clear_3();
void Ov120_stIdlePose10Advance(int param_1)
{
    int state = *(int *)(param_1 + 4);
    if (*(unsigned char *)*(int *)(state + 0x48) != 0)
        return;
    Ov107_PostTagUpdate(*(int *)state, 0xa, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), Ov120_AiStep_QueueAction2OnFlag48Clear_3);
}
