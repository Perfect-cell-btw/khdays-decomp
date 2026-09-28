/* While the character is shown, draws its three effect nodes at the locked target's point. */

extern void Ov059_RecenterSubObjectAndCopyVec();
extern void Ov059_DrawSubNodeWithYaw();
extern void Ov059_DrawSubNodeWithYaw2();

struct b1 { unsigned char b : 1; };

void Ov059_ForwardToThreeSubHandlersIfFlagSet(int this_, int arg1) {
    if (((struct b1 *)(this_ + 0x694))->b == 0) return;
    Ov059_RecenterSubObjectAndCopyVec(this_, arg1 + 8);
    Ov059_DrawSubNodeWithYaw(this_, arg1);
    Ov059_DrawSubNodeWithYaw2(this_, arg1);
}
