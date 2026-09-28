/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov081_DestroySlotsAndFree();extern void Ov022_DestroyRoot();extern int data_ov081_020b96e0;
void Ov081_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov081_DestroySlotsAndFree(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov081_020b96e0 = 0;
}
