/* State step: sets bits 0x82 and clears 0xc in the high byte of the actor's flags (+0x60), sets bit
 * 0 of +0x1ae, clears bit 0 of the model's flag byte, sends a state update, clears the timer and
 * installs the aiming timer step. */

struct hw60 { unsigned short lo : 8, hi : 8; };
struct bf { unsigned b : 8; };
extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov196_stTickAimTimerC(void);

void Ov196_stSetFlags82ClearC(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x82) << 0x18) >> 0x10));
    }
    ((struct hw60 *)(*state + 0x60))->hi &= ~0xc;
    *(unsigned short *)(*state + 0x1ae) |= 1;
    ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x48, state[0x10]);
    state[0xc] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov196_stTickAimTimerC);
}
