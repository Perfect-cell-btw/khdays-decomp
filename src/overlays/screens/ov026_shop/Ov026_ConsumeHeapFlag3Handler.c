/* Once the shop context's ready flag is set, clears it and returns the sub-scene wait step. */

extern int NNSi_FndGetCurrentRootHeap();
extern void Ov026_SubSceneWait();

int Ov026_ConsumeHeapFlag3Handler(void) {
    unsigned int *h = (unsigned int *)NNSi_FndGetCurrentRootHeap();
    if ((*h & 8) != 0) {
        *h &= 0xfffffff7;
        return (int)Ov026_SubSceneWait;
    }
    return 0;
}
