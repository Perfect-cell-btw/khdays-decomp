extern void Ov096_RecenterSubObjectAndCopyVec();
extern void Ov096_DrawSubNodeWithYaw();
extern void Ov096_DrawSubNodeWithYaw2();

struct b1 { unsigned char b : 1; };

void Ov096_ForwardToThreeSubHandlersIfFlagSet(int this_, int arg1) {
    if (((struct b1 *)(this_ + 0x694))->b == 0) return;
    Ov096_RecenterSubObjectAndCopyVec(this_, arg1 + 8);
    Ov096_DrawSubNodeWithYaw(this_, arg1);
    Ov096_DrawSubNodeWithYaw2(this_, arg1);
}
