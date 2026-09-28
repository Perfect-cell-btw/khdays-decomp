/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov079_ReleaseThreeSubBlocks2c50();extern void Ov022_DestroyRoot();extern int data_ov079_020b9a00;
void Ov079_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov079_ReleaseThreeSubBlocks2c50(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov079_020b9a00 = 0;
}
