/* If the 1-bit flag at this[0x694] is set: runs Ov046_DrawNodeWithOwnerPos3(this, arg1), then calls
 * Ov046_DrawNodeIfState2 over 6 slots at arg1+0x128 stride 0x120. */

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
