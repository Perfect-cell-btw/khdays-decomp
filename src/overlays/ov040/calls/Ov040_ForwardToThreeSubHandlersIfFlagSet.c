extern void Ov040_RecenterSubObjectAndCopyVec();
extern void Ov040_DrawSubNodeWithYaw();
extern void Ov040_DrawSubNodeWithYaw2();

struct b1 { unsigned char b : 1; };

void Ov040_ForwardToThreeSubHandlersIfFlagSet(int this_, int arg1) {
    if (((struct b1 *)(this_ + 0x694))->b == 0) return;
    Ov040_RecenterSubObjectAndCopyVec(this_, arg1 + 8);
    Ov040_DrawSubNodeWithYaw(this_, arg1);
    Ov040_DrawSubNodeWithYaw2(this_, arg1);
}
