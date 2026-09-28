extern int NNSi_FndGetCurrentRootHeap();extern void Ov067_ReleaseThreeSubBlocks2c2c();extern void Ov022_DestroyRoot();extern int data_ov067_020b7380;
void Ov067_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov067_ReleaseThreeSubBlocks2c2c(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov067_020b7380 = 0;
}
