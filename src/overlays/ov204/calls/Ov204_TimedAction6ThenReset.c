extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void Ov107_StartAnim(int a, int b, int c);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov204_ChargeTick1(void);

void Ov204_TimedAction6ThenReset(int *node) {
    int *state = (int *)node[1];
    int thr = 0x111;
    if (*(unsigned char *)((char *)state + 0x45) == 0) {
        int t = state[0xb] + *(int *)(*node + 0x2c);
        state[0xb] = t;
        if (t >= thr) {
            *(unsigned char *)((char *)state + 0x45) = 1;
            Ov107_BuildAndSendUpdate(*state, thr + 0x21, 6, state[9]);
        }
    }
    if (*(unsigned char *)state[10] != 0) return;
    Ov107_StartAnim(*(int *)(*state + 0x390), 5, 0);
    Ov107_PostTagUpdate(*state, 0xe, 0);
    state[0xb] = 0;
    *((char *)state + 0x44) = 0;
    state[0x16] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov204_ChargeTick1);
}
