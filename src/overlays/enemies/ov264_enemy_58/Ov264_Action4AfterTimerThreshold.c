/* AI step: advances the timer by the owner's frame step until it passes 0x6ee; then clears bit 7 of
 * the high flag byte, posts pose 0, sends a state update and installs the wait-for-animation step.
 */

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov264_AiStep_QueueAction5OnAnimEnd(void);

struct hw60 { unsigned short lo : 8, hi : 8; };

void Ov264_Action4AfterTimerThreshold(int *node) {
    int *state = (int *)node[1];
    int t = state[0x14] + *(int *)(*node + 0x2c);
    state[0x14] = t;
    if (t < 0x6ee) return;
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x80;
    Ov107_PostTagUpdate(*state, 0, 0);
    Ov107_BuildAndSendUpdate(*state, 0x15d, 4, state[4]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov264_AiStep_QueueAction5OnAnimEnd);
}
