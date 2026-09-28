/* Tear down the manager: run the two release passes, then free the element buffer at
 * +0x14 if it is still allocated. */
extern void Ov004_FreeResourceRecordBuffer(int a);
extern void Ov004_DestroyAllListObjects(int a);
extern void NNSi_FndFreeFromDefaultHeap(int a);
void Ov004_DestroyMissionList(int param_1) {
    Ov004_FreeResourceRecordBuffer(param_1);
    Ov004_DestroyAllListObjects(param_1);
    if (*(int *)(param_1 + 0x14) == 0) return;
    NNSi_FndFreeFromDefaultHeap(*(int *)(param_1 + 0x14));
    *(int *)(param_1 + 0x14) = 0;
}
