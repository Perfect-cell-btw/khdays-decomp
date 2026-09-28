extern int NNSi_FndGetCurrentRootHeap();extern void Ov040_ReleaseThreeSubBlocks2c50();extern void Ov022_DestroyRoot();extern int data_ov040_020b4b20;
void Ov040_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov040_ReleaseThreeSubBlocks2c50(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov040_020b4b20 = 0;
}
