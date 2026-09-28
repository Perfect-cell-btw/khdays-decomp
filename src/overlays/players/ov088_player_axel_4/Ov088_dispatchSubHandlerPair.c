/* Updates the character's two sub-objects (and rebinds them when needed), then draws them. */

extern void Ov088_updateSubObjectsAndRebind(int a, int b, int c);
extern void Ov088_tickSubObjectsIfFlagged(int a, int b);

void Ov088_dispatchSubHandlerPair(int this) {
    Ov088_updateSubObjectsAndRebind(this, this + 0x2c2c, *(short *)(this + 0x2aba));
    Ov088_tickSubObjectsIfFlagged(this, this + 0x2c2c);
}
