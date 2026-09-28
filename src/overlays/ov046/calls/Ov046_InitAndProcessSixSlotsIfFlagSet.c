extern void Ov046_DrawNodeWithOwnerPos3();
extern void Ov046_DrawNodeIfState2();

struct b1 { unsigned char b : 1; };

void Ov046_InitAndProcessSixSlotsIfFlagSet(int this_, int arg1) {
    int i;
    char *p;
    if (((struct b1 *)(this_ + 0x694))->b == 0) return;
    Ov046_DrawNodeWithOwnerPos3(this_, arg1);
    p = (char *)(arg1 + 0x128);
    for (i = 0; i < 6; i++) {
        Ov046_DrawNodeIfState2((int)p);
        p += 0x120;
    }
}
