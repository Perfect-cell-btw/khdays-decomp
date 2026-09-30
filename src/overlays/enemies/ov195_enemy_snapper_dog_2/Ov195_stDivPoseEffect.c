/* State step: derives the speed from the owner's frame step, posts pose 2, clears the timer, starts
 * the child selector's animation and installs the chase step. */

extern void Ov107_PostTagUpdate();
extern void Ov107_StartAnim();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov195_ChaseTick(void);
void Ov195_stDivPoseEffect(int *node) {
    int v = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    state[5] = v / 15;
    Ov107_PostTagUpdate(*state, 2, 1, v);
    state[12] = 0;
    Ov107_StartAnim(*(int *)(*state + 0x3d0), 0, 1);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov195_ChaseTick);
}
