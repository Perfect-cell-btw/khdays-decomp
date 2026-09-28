extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov134_AiStep_WaitTimerThenTag8();
void Ov134_stIdlePose7ClearTimerAdvance(int param_1)
{
    int *state = *(int **)(param_1 + 4);
    if (*(unsigned char *)(state[1] + 0xad) != 0)
        return;
    Ov107_PostTagUpdate(state[0], 7, 1);
    state[0xc] = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), Ov134_AiStep_WaitTimerThenTag8);
}
