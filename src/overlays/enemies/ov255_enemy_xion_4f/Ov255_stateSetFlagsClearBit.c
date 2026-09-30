/* State step: sets the stance bits in the high byte of the actor's flags (+0x60), clears bit 0 of
 * the part's flag byte and installs the wake-check step. */

struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov255_WakeCheck(void);
void Ov255_stateSetFlagsClearBit(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10));
    }
    ((struct bf *)(*(int *)(*state + 0x394) + 8))->b &= ~1;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov255_WakeCheck);
}
