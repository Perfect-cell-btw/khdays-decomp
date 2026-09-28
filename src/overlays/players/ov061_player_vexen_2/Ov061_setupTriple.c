/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov061_DestroySlotsAndFree();extern void Ov022_DestroyRoot();extern int data_ov061_020b7000;
void Ov061_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov061_DestroySlotsAndFree(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov061_020b7000 = 0;
}
