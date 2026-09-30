/* Set flags 0x86 in the high byte of the u16 at obj+0x60, clear bit0 of the byte at
 * (obj+0x388)->+8, then dispatch. */

struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov301_ConfigSubStateThenAdvanceSlot(void);
void Ov301_stateSetFlagsClearBit(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10));
    }
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov301_ConfigSubStateThenAdvanceSlot);
}
