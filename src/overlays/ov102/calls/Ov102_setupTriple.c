/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov102_ReleaseGlobalAndSubObjectChannel();extern void Ov022_DestroyRoot();extern int data_ov102_020bb920;
void Ov102_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov102_ReleaseGlobalAndSubObjectChannel(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov102_020bb920 = 0;
}
