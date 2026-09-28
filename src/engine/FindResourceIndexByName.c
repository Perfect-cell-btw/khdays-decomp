/* Looks a name up in the model's G3D resource dictionary (the name is padded to 16 bytes first);
 * returns its index or -1. */

extern void MI_CpuFill8(void *dst, unsigned char val, unsigned int size);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned int size);
extern int strlen(void *p);
extern int NNS_G3dGetResDictIdxByName(void *p, void *q);

extern char data_0204ca98[];

int FindResourceIndexByName(void *a0, void *a1) {
    int sz;
    int r;
    void *p;
    void *q;

    MI_CpuFill8(data_0204ca98, 0, 0x10);
    sz = strlen(a1);
    MI_CpuCopy8(a1, data_0204ca98, sz);

    p = ((void **)((char **)a0)[0x88 / 4])[0x24 / 4];
    q = p ? (char *)p + 0x40 : (void *)0;
    if (q == (void *)0) {
        r = -1;
    } else {
        r = NNS_G3dGetResDictIdxByName(q, data_0204ca98);
    }
    if (r < 0) r = -1;
    return r;
}
