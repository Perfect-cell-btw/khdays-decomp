extern int ScaleVec3Fx12();

int Ov246_HandleBounce(char *a, int b, int *c) {
    char *s = *(char **)(a + 0x214);
    unsigned short v = (unsigned short)*c;
    if (v & 1) {
        if (*(int *)(s + 0x24) != 0) {
            return 0;
        }
        ScaleVec3Fx12(-0x1000, s + 0x14, s + 0x14);
        *(int *)(s + 0x24) = 1;
        *(int *)(s + 0x28) = 0;
        return 1;
    }
    return 0;
}
