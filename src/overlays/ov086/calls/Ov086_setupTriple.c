/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov086_ReleaseThreeSubBlocks2c2c();extern void Ov022_DestroyRoot();extern int data_ov086_020b9a60;
void Ov086_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov086_ReleaseThreeSubBlocks2c2c(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov086_020b9a60 = 0;
}
