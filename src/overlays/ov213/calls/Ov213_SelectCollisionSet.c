/* Select the active collision set: set 0 raises bit 1 of the +0x38c handle's +0x5c word and
 * re-arms the four +0x388 slots (0, 2, 4, 1) with value 0; set 1 clears that bit and re-arms the
 * four +0x38c slots instead. `flag` is passed through as the slot flag. */
extern void SetSubitemState(void *sub, int channel, short value, int flag);

void Ov213_SelectCollisionSet(int self, int which, int flag) {
    if (which == 0) {
        *(int *)(*(int *)(self + 0x38c) + 0x5c) |= 2;
        SetSubitemState(*(void **)(self + 0x388), 0, 0, flag);
        SetSubitemState(*(void **)(self + 0x388), 2, 0, flag);
        SetSubitemState(*(void **)(self + 0x388), 4, 0, flag);
        SetSubitemState(*(void **)(self + 0x388), 1, 0, flag);
    } else if (which == 1) {
        *(int *)(*(int *)(self + 0x38c) + 0x5c) &= ~2;
        SetSubitemState(*(void **)(self + 0x38c), 0, 0, flag);
        SetSubitemState(*(void **)(self + 0x38c), 2, 0, flag);
        SetSubitemState(*(void **)(self + 0x38c), 4, 0, flag);
        SetSubitemState(*(void **)(self + 0x38c), 1, 0, flag);
    }
}
