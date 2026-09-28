/* While the character is shown, draws its three effect nodes at the locked target's point. */

extern void Ov079_RecenterSubObjectAndCopyVec();
extern void Ov079_DrawSubNodeWithYaw();
extern void Ov079_DrawSubNodeWithYaw2();

struct b1 { unsigned char b : 1; };

void Ov079_ForwardToThreeSubHandlersIfFlagSet(int this_, int arg1) {
    if (((struct b1 *)(this_ + 0x694))->b == 0) return;
    Ov079_RecenterSubObjectAndCopyVec(this_, arg1 + 8);
    Ov079_DrawSubNodeWithYaw(this_, arg1);
    Ov079_DrawSubNodeWithYaw2(this_, arg1);
}
