/* Loads the archive file as kind 0xe, passes its CHAR sub-block to fp, then frees the file. */

extern int Archive_LoadFile();
extern int GetResourceSubBlock_CHAR();
extern int NNSi_FndFreeFromDefaultHeap();

int Ov008_WithCharBlock(int a0, int (*fp)()) {
    int *local;
    int *r4;
    int ret;

    r4 = (int *)Archive_LoadFile(a0, 0xe);
    GetResourceSubBlock_CHAR(r4, &local);
    ret = fp(local[5], 0, local[4]);
    if (r4 == 0) {
        return ret;
    }
    return NNSi_FndFreeFromDefaultHeap(r4);
}
