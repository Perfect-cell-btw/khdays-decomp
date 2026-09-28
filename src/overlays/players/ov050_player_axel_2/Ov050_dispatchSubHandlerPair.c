/* Updates the character's two sub-objects (and rebinds them when needed), then draws them. */

extern void Ov050_updateSubObjectsAndRebind(int a, int b, int c);
extern void Ov050_tickSubObjectsIfFlagged(int a, int b);

void Ov050_dispatchSubHandlerPair(int this) {
    Ov050_updateSubObjectsAndRebind(this, this + 0x2c2c, *(short *)(this + 0x2aba));
    Ov050_tickSubObjectsIfFlagged(this, this + 0x2c2c);
}
