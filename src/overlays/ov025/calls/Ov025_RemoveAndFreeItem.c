extern int NNS_FndRemoveListObject();
extern void NNSi_FndFreeFromDefaultHeap();

void Ov025_RemoveAndFreeItem(int arg0, int arg1) {
    NNS_FndRemoveListObject(arg0 + 0x1cc, arg1);
    NNSi_FndFreeFromDefaultHeap(*(int *)(arg1 + 0x14));
    NNSi_FndFreeFromDefaultHeap(arg1);
}
