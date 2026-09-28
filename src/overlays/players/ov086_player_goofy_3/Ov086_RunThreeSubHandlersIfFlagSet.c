extern void Ov086_DrawNodeWhileActive();
extern void Ov086_DrawNodeWithYaw2();
extern void Ov086_DrawSubNodeWithYaw3();

struct b1 { unsigned char b : 1; };

void Ov086_RunThreeSubHandlersIfFlagSet(int this_, int arg1) {
    if (((struct b1 *)(this_ + 0x694))->b == 0) return;
    Ov086_DrawNodeWhileActive(this_, arg1);
    Ov086_DrawNodeWithYaw2(this_, arg1);
    Ov086_DrawSubNodeWithYaw3(this_, arg1);
}
