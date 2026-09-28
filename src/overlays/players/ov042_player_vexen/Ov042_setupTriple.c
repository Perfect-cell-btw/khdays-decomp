/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov042_DestroySlotsAndFree();extern void Ov022_DestroyRoot();extern int data_ov042_020b4800;
void Ov042_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov042_DestroySlotsAndFree(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov042_020b4800 = 0;
}
