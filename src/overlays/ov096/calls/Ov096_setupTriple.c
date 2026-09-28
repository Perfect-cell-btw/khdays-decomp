extern int NNSi_FndGetCurrentRootHeap();extern void Ov096_ReleaseThreeSubBlocks2c50();extern void Ov022_DestroyRoot();extern int data_ov096_020bc0c0;
void Ov096_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov096_ReleaseThreeSubBlocks2c50(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov096_020bc0c0 = 0;
}
