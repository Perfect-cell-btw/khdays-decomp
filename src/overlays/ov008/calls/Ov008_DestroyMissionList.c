/* Tear down the manager: run the two release passes, then free the element buffer at +0x14 if it is
 * still allocated. */

extern void Ov008_FreeResourceRecordBuffer(void *object);
extern void Ov008_DestroyAllListObjects_2(void *object);
extern void NNSi_FndFreeFromDefaultHeap(void *block);

void Ov008_DestroyMissionList(void *object)
{
    Ov008_FreeResourceRecordBuffer(object);
    Ov008_DestroyAllListObjects_2(object);

    if (*(void **)((char *)object + 0x14) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(void **)((char *)object + 0x14));
        *(int *)((char *)object + 0x14) = 0;
    }
}
