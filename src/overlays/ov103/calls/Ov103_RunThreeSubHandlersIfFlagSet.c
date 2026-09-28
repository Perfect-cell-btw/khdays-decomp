extern void Ov103_DrawNodeWhileActive();
extern void Ov103_DrawNodeWithYaw2();
extern void Ov103_DrawSubNodeWithYaw3();

struct b1 { unsigned char b : 1; };

void Ov103_RunThreeSubHandlersIfFlagSet(int this_, int arg1) {
    if (((struct b1 *)(this_ + 0x694))->b == 0) return;
    Ov103_DrawNodeWhileActive(this_, arg1);
    Ov103_DrawNodeWithYaw2(this_, arg1);
    Ov103_DrawSubNodeWithYaw3(this_, arg1);
}
