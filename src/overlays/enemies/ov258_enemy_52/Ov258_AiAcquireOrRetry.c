/* Run 020cd028; unless busy, take the ready path only when +0x38 is idle and 020cd2cc confirms. */
extern int Ov258_AcquireTarget(int, int);
extern int Ov258_PickMove(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov258_AiEnterPlay(int);
void Ov258_AiAcquireOrRetry(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov258_AcquireTarget(param_1, 1);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    if (*(int *)(owner + 0x38) == 0 && Ov258_PickMove(param_1) != 0)
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
    else
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov258_AiEnterPlay);
}
