/* State step: sets bit 7 of the high flag byte, clears bit 0 of the model's flag byte and the
 * alpha, and installs the roll-variant step. */

struct bf { unsigned b : 8; };
extern void SetIndexedSlot(int obj, int idx, void *cb, int flag);
extern void Ov289_RollFlag38cCopySubStateThenAdvanceSlot(void);

void Ov289_SetHw60Bit15ClearSubBit0ThenAdvanceSlot(int this_) {
    int *state = *(int **)(this_ + 4);
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x80) << 0x18) >> 0x10));
    }
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
    *(int *)(*state + 0x394) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), Ov289_RollFlag38cCopySubStateThenAdvanceSlot, 0);
}
