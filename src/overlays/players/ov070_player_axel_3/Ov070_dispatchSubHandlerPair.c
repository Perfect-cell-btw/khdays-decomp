/* Updates the character's two sub-objects (and rebinds them when needed), then draws them. */

extern void Ov070_updateSubObjectsAndRebind(int a, int b, int c);
extern void Ov070_tickSubObjectsIfFlagged(int a, int b);

void Ov070_dispatchSubHandlerPair(int this) {
    Ov070_updateSubObjectsAndRebind(this, this + 0x2c2c, *(short *)(this + 0x2aba));
    Ov070_tickSubObjectsIfFlagged(this, this + 0x2c2c);
}
