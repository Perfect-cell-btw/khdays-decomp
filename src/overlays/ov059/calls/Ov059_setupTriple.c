/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov059_ReleaseThreeSubBlocks2c50();extern void Ov022_DestroyRoot();extern int data_ov059_020b7320;
void Ov059_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov059_ReleaseThreeSubBlocks2c50(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov059_020b7320 = 0;
}
