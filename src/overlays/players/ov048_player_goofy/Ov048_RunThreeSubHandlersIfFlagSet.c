extern void Ov048_DrawNodeWhileActive();
extern void Ov048_DrawNodeWithYaw2();
extern void Ov048_DrawSubNodeWithYaw3();

struct b1 { unsigned char b : 1; };

void Ov048_RunThreeSubHandlersIfFlagSet(int this_, int arg1) {
    if (((struct b1 *)(this_ + 0x694))->b == 0) return;
    Ov048_DrawNodeWhileActive(this_, arg1);
    Ov048_DrawNodeWithYaw2(this_, arg1);
    Ov048_DrawSubNodeWithYaw3(this_, arg1);
}
