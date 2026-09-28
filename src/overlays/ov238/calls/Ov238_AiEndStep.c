/* Tail-call SetIndexedSlot with param_1, its signed byte at +0x20, and flag 0. */
extern int SetIndexedSlot(int a, int b, int c);
int Ov238_AiEndStep(int param_1) {
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
