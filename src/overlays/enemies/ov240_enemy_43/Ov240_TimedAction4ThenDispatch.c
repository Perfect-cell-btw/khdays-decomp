/* AI step: sends the attack update (0x139, mode 4) once its time comes and, when the animation
 * ends, posts pose 6, starts animation 1 and continues. */

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov240_startAnim(int a, int b);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov240_stateFixedAngleMatrix(void);

void Ov240_TimedAction4ThenDispatch(int *node) {
    int *state = (int *)node[1];
    state[0xe] += *(int *)(*node + 0x2c);
    if (*(unsigned char *)((char *)state + 0x3e) == 0 && state[0xe] >= 0x440) {
        Ov107_BuildAndSendUpdate(*state, 0x139, 4, state[2]);
        *(unsigned char *)((char *)state + 0x3e) = 1;
    }
    if (*(unsigned char *)(state[1] + 0xad) != 0) return;
    Ov107_PostTagUpdate(*state, 6, 0);
    Ov240_startAnim(*state, 1);
    state[0xe] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov240_stateFixedAngleMatrix);
}
