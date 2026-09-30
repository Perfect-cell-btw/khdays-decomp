/* State step: sets and clears state bits in the high byte of the actor's flags (+0x60), sets bit 0
 * of the flags at +0x1ae, clears bit 0 of its model's flag byte, sends a state update, resets the
 * timer and installs the timed turn-toward-target step. */

struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov115_stateTimerRebuildTransform(void);
void Ov115_stateSetFlagsInitAnim(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x82) << 0x18) >> 0x10));
    }
    ((struct hw60 *)(*state + 0x60))->hi &= ~0xc;
    *(unsigned short *)(*state + 0x1ae) |= 1;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x48, state[2]);
    state[0x12] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov115_stateTimerRebuildTransform);
}
