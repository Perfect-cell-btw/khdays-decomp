/* Mark state 2, force +0x54 flags, run 020cfd20 on both sub-refs, then dispatch. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov258_ForwardToAiTaskWhenReady(int);
void Ov258_AiFinishWithParts(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(signed char *)(*(int *)owner + 0x1c7) = 2;
    *(unsigned char *)(owner + 0x54) |= 0xf0;
    Ov258_ForwardToAiTaskWhenReady(*(int *)(*(int *)owner + 0x458));
    Ov258_ForwardToAiTaskWhenReady(*(int *)(*(int *)owner + 0x45c));
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
