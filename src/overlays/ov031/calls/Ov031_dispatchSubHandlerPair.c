extern void Ov031_updateSubObjectsAndRebind(int a, int b, int c);
extern void Ov031_tickSubObjectsIfFlagged(int a, int b);

void Ov031_dispatchSubHandlerPair(int this) {
    Ov031_updateSubObjectsAndRebind(this, this + 0x2c2c, *(short *)(this + 0x2aba));
    Ov031_tickSubObjectsIfFlagged(this, this + 0x2c2c);
}
