/* Draws the character's two sub-objects while the owner is shown. */

struct bit1 { unsigned char b : 1; };

extern void Ov088_configureSubObjectSlot(int this, int slot, int i);

void Ov088_tickSubObjectsIfFlagged(int this, int base) {
    int i;
    int slot;
    if (!((struct bit1 *)(this + 0x694))->b) return;
    slot = base + 0xc;
    i = 0;
    do {
        Ov088_configureSubObjectSlot(this, slot, i);
        i++;
        slot += 0x118;
    } while (i < 2);
}
