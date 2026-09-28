/* On a bounce flag reverses the velocity once and marks it. */

extern int ScaleVec3Fx12();

int Ov125_HandleBounce(char *a, int b, int *c) {
    char *s = *(char **)(a + 0x214);
    unsigned short v = (unsigned short)*c;
    if (v & 1) {
        if (*(int *)(s + 0x1c) != 0) {
            return 0;
        }
        ScaleVec3Fx12(-0x1000, s + 0xc, s + 0xc);
        *(int *)(s + 0x1c) = 1;
        *(int *)(s + 0x18) = 0;
        return 1;
    }
    return 0;
}
