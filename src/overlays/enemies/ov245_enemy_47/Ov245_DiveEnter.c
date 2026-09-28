/* Ov245_DiveEnter -- dive entry: resets the actor (020cce08), starts motion 0 of the +0x4c8
 * anchor, hands the +0x24 value to the +0x430 item (020d1dc8), then from the height gap (020ccda4, flat) computes the
 * fraction of 5.0 still to fall (clamped 0..5.0) and its ratio (FX_Inv against 5.0) scaled by
 * 0.925 into the +0x20 z speed (x/y zero), and hands the node to 020cd9f4. */
extern void Ov245_SetNodeMode3(int actor);
extern void Ov107_StartAnim(int item, int motion, int flag);
extern void Ov245_NodeUpdateTickForward_b(int item, int a);
extern int Ov245_TargetHeightGap(int *node, int flat);
extern int FX_Div(int num, int den);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov245_DiveTick(void);

void Ov245_DiveEnter(int *node) {
    int *state = (int *)node[1];
    int rest;

    Ov245_SetNodeMode3(*state);
    Ov107_StartAnim(*(int *)(*state + 0x4c8), 0, 1);
    Ov245_NodeUpdateTickForward_b(*(int *)(*state + 0x430), state[9]);
    rest = 0x5000 - Ov245_TargetHeightGap(node, 1);
    if (rest > 0x5000) {
        rest = 0x5000;
    } else if (rest < 0) {
        rest = 0;
    }
    rest = FX_Div(rest, 0x5000);
    state[6] = 0;
    state[7] = 0;
    state[8] = (int)(((long long)rest * 0xed0 + 0x800) >> 12);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov245_DiveTick);
}
