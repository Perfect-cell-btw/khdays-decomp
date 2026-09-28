/* State step: posts pose 5, clears flag 0x40 in the high byte of the actor's flags, faces the
 * target when one is set and installs the damped-move step. */

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void VEC_Subtract(void *a, void *b, void *out);
extern int func_020050b4(int x, int y);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov140_CopyScaleVec3GuardedThenAdvance(void);

struct hw60 { unsigned short lo : 8, hi : 8; };

void Ov140_Pose5ClearHitFlagAimAdvance(int *node) {
    int *state = (int *)node[1];
    int local[3];
    Ov107_PostTagUpdate(*state, 5, 0);
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x40;
    if (state[0x11] != 0) {
        VEC_Subtract((void *)(state[0x11] + 400), (void *)(*state + 0xb0), local);
        int r = func_020050b4(local[0], local[2]);
        state[3] = r;
        state[2] = r;
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov140_CopyScaleVec3GuardedThenAdvance);
}
