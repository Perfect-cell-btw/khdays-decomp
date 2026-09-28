/* Two-level lookup off the table at obj+0x8c: entry `i` must be non-zero, then the pointer at +0x10
 * + i*4 is indexed by `j`, dereferenced twice, and the halfword at +4 of the result is returned
 * shifted left 12 (Q12). */

int Obj_GetCellScaledField(int *obj, int idx, int idx2) {
    short *base = *(short **)((char *)obj + 0x8c);
    if (base[idx] == 0) {
        return 0;
    }
    {
        int *p = *(int **)((char *)base + idx * 4 + 0x10);
        int *q = (int *)p[idx2];
        int *r = (int *)q[2];
        return ((unsigned short *)r)[2] << 12;
    }
}
