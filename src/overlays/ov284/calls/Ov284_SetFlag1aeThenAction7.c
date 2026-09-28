extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov284_AiRollTimerQueue2WhenReady(void);

void Ov284_SetFlag1aeThenAction7(int *node) {
    int *state = (int *)node[1];
    *(unsigned short *)(*state + 0x1ae) |= 1;
    Ov107_PostTagUpdate(*state, 2, 0);
    Ov107_BuildAndSendUpdate(*state, 0x16c, 7, state[1]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov284_AiRollTimerQueue2WhenReady);
}
