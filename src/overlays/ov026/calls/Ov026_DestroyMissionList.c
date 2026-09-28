/* Tear down the manager: run the two release passes, then free the element buffer at
 * +0x14 if it is still allocated. */
extern void Ov026_FreeResourceRecordBuffer(int a);
extern void Ov026_DestroyAllListObjects_2(int a);
extern void NNSi_FndFreeFromDefaultHeap(int a);
void Ov026_DestroyMissionList(int param_1) {
    Ov026_FreeResourceRecordBuffer(param_1);
    Ov026_DestroyAllListObjects_2(param_1);
    if (*(int *)(param_1 + 0x14) == 0) return;
    NNSi_FndFreeFromDefaultHeap(*(int *)(param_1 + 0x14));
    *(int *)(param_1 + 0x14) = 0;
}
