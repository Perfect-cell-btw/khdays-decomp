/* State step: faces the target, posts the idle pose in action 7 or the attack pose with a state
 * update otherwise, and installs the aim-hold step. */

extern void Ov145_AimYawToTarget(int *state);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov145_AimHoldTick(void);

void Ov145_PoseThenAction4OrIdle(int *node) {
    int *state = (int *)node[1];
    int s;
    Ov145_AimYawToTarget(state);
    s = *state;
    if (*(signed char *)(s + 0x1c6) == 7) {
        Ov107_PostTagUpdate(s, 0, 1);
        SetIndexedSlot(node, *(signed char *)(node + 8), Ov145_AimHoldTick);
        return;
    }
    Ov107_PostTagUpdate(s, 8, 0);
    Ov107_BuildAndSendUpdate(*state, 0x124, 4, state[2]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov145_AimHoldTick);
}
