/* While the character is shown, draws its three effect nodes. */

extern void Ov067_DrawNodeWhileActive();
extern void Ov067_DrawNodeWithYaw2();
extern void Ov067_DrawSubNodeWithYaw3();

struct b1 { unsigned char b : 1; };

void Ov067_RunThreeSubHandlersIfFlagSet(int this_, int arg1) {
    if (((struct b1 *)(this_ + 0x694))->b == 0) return;
    Ov067_DrawNodeWhileActive(this_, arg1);
    Ov067_DrawNodeWithYaw2(this_, arg1);
    Ov067_DrawSubNodeWithYaw3(this_, arg1);
}
