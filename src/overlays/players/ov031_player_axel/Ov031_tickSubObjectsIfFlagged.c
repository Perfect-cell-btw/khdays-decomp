struct bit1 { unsigned char b : 1; };

extern void Ov031_configureSubObjectSlot(int this, int slot, int i);

void Ov031_tickSubObjectsIfFlagged(int this, int base) {
    int i;
    int slot;
    if (!((struct bit1 *)(this + 0x694))->b) return;
    slot = base + 0xc;
    i = 0;
    do {
        Ov031_configureSubObjectSlot(this, slot, i);
        i++;
        slot += 0x118;
    } while (i < 2);
}
