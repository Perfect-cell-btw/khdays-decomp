extern void NNS_G3dRenderObjRemoveAnmObj(int a, int b);

typedef struct { int a[3]; } Idx3;
extern Idx3 data_ov034_020b5570;

void Ov034_ReleaseIndexedHandles(int self) {
    char *blk = (char *)(self + 0xf10);
    Idx3 idx = data_ov034_020b5570;
    int i;
    for (i = 0; i < 3; i++) {
        if (*(int *)(blk + idx.a[i] * 4 + 0xc) != 0) {
            NNS_G3dRenderObjRemoveAnmObj((int)(blk + 0x20), *(int *)(blk + idx.a[i] * 4 + 0xc));
            *(int *)(blk + idx.a[i] * 4 + 0xc) = 0;
        }
        *(short *)(blk + idx.a[i] * 2 + 2) = -1;
    }
}
