extern void NNS_G3dMdlSetMdlPolygonID(int a, int b, int c);
extern void Ov022_DrawShot(int e);

void Ov100_ReleaseSlotHandles(int self) {
    int i;
    for (i = 0; i < (int)*(unsigned char *)(self + 0x19); i++) {
        int e = *(int *)(self + 0xc) + i * 0x1c8;
        int t = *(signed char *)(e + 2);
        if (t != 0 && t != 3) {
            NNS_G3dMdlSetMdlPolygonID(*(int *)(e + 0xa0), 2, 0x1c - i);
            Ov022_DrawShot(e);
        }
    }
}
