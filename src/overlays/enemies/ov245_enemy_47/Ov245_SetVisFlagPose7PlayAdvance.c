/* AI step: sets stance bit 0x40, posts pose 7, starts the launch animation and continues with the
 * launch tick. */

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_StartAnim(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov245_LaunchTick(void);

struct hw60 { unsigned short lo : 8, hi : 8; };

void Ov245_SetVisFlagPose7PlayAdvance(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10);
    }
    Ov107_PostTagUpdate(*state, 7, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3a0), 1, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov245_LaunchTick);
}
