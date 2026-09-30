/* Fade the sub-object in: advance the fade timer by the owner's per-frame delta and, past 0x400,
 * drive the alpha at +0x390 down from 0x1000 by the reciprocal of how far the timer has gone,
 * with a floor of 0xcc. Once the sub-object stops reporting busy, snap the alpha to that floor
 * and switch to action 7.
 *
 * Matched byte-exact 2026-07-23, first compile. One of three byte-identical siblings. */
extern int FX_Div(int a, int b);
extern void SetIndexedSlot(void *node, int idx, void *cb);

void Ov277_FadeInSubObject(int *node) {
    int *owner = (int *)node[0];
    int *state = (int *)node[1];

    state[0x11] = state[0x11] + *(int *)((int)owner + 0x2c);
    if (state[0x11] >= 0x400) {
        *(int *)(state[0] + 0x390) = 0x1000 - FX_Div(state[0x11] - 0x400, 0x2aa);
        if (*(int *)(state[0] + 0x390) < 0xcc) {
            *(int *)(state[0] + 0x390) = 0xcc;
        }
    }
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    *(int *)(state[0] + 0x390) = 0xcc;
    *(char *)(state[0] + 0x1c7) = 7;
    SetIndexedSlot(node, *(signed char *)((int)node + 0x20), 0);
}
