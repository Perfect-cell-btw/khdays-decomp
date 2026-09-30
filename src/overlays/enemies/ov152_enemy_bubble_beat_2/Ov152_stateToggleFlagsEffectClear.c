/* State step: clears bit 0 and sets the stance bits in the high byte of the actor's flags (+0x60),
 * clears bit 0 of its model's flag byte, sends a state update, clears the pending action and clears
 * the step handler. */

struct hw60 { unsigned short lo : 8, hi : 8; };
struct bf { unsigned b : 8; };
extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
void Ov152_stateToggleFlagsEffectClear(int *node) {
    int *state = (int *)node[1];
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10));
    }
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x49, state[0x11]);
    *(signed char *)(*state + 0x1c7) = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), 0);
}
