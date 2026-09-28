/* ov node state callback: stores object[+0x2c]*30/30 into a state field (magic-multiply divide),
 * then advances/guards the node state slot. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov203_AiLoopAnim2OnFlagClear(void);
void Ov203_stDiv30Store_2(int *node) {
    int v = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    state[4] = v / 30;
    Ov107_PostTagUpdate(*state, 8, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov203_AiLoopAnim2OnFlagClear);
}
