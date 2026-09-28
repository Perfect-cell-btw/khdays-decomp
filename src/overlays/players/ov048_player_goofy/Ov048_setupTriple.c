/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov048_ReleaseThreeSubBlocks2c2c();extern void Ov022_DestroyRoot();extern int data_ov048_020b4b80;
void Ov048_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov048_ReleaseThreeSubBlocks2c2c(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov048_020b4b80 = 0;
}
