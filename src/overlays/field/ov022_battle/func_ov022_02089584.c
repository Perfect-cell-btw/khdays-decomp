/* Stores bit 3 of the effect pool's flags. */

void func_ov022_02089584(int arg0, int arg1) {
    unsigned char *p = (unsigned char *)(*(int *)(arg0 + 0x20) + 1);
    unsigned char v = arg1;
    *p = (*p & ~8) | ((unsigned int)(v << 31) >> 28);
}
