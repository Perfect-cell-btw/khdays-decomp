extern void Slot_UnlinkIfLinked();
extern void NNS_FndRemoveListObject();
extern void NNSi_FndFreeFromDefaultHeap();

void Ov025_DestroyEntry(int *arg0, int arg1) {
    if (*(int *)((int)arg0 + 0x4a70) == arg1)
        *(int *)((int)arg0 + 0x4a70) = 0;
    int i = 0;
    do {
        int v = ((int *)arg1)[i + 5];
        if (v != -1) Slot_UnlinkIfLinked(arg0, v);
        i++;
    } while (i < 2);
    NNS_FndRemoveListObject((void *)((int)arg0 + 0x4a38), arg1);
    if (arg1 != 0) NNSi_FndFreeFromDefaultHeap(arg1);
}
