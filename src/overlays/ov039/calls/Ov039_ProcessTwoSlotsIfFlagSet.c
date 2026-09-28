extern void Ov039_DrawNodeWithResolvedPos();

struct b1 { unsigned char b : 1; };

void Ov039_ProcessTwoSlotsIfFlagSet(int this_, int arg1) {
    int i;
    char *p;
    if (((struct b1 *)(this_ + 0x694))->b == 0) return;
    p = (char *)(arg1 + 0x18);
    for (i = 0; i < 2; i++, p += 0x10c) {
        Ov039_DrawNodeWithResolvedPos(this_, (int)p);
    }
}
