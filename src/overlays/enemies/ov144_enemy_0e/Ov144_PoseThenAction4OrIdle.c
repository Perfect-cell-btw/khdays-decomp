extern void Ov144_AimYawToTarget(int *state);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov144_AimHoldTick(void);

void Ov144_PoseThenAction4OrIdle(int *node) {
    int *state = (int *)node[1];
    int s;
    Ov144_AimYawToTarget(state);
    s = *state;
    if (*(signed char *)(s + 0x1c6) == 7) {
        Ov107_PostTagUpdate(s, 0, 1);
        SetIndexedSlot(node, *(signed char *)(node + 8), Ov144_AimHoldTick);
        return;
    }
    Ov107_PostTagUpdate(s, 8, 0);
    Ov107_BuildAndSendUpdate(*state, 0x123, 4, state[2]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov144_AimHoldTick);
}
