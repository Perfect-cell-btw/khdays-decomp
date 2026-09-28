/* Build the transient blob, hand it to 02055a24, then free it. */
extern int Archive_LoadFile(int data, int kind);
extern void Ov026_InstantiateAndLinkElements(int self, int obj, int arg);
extern void NNSi_FndFreeFromDefaultHeap(void *obj);
void Ov026_LoadBlockProcessAndFree(int param_1, int param_2, int param_3) {
    int obj = Archive_LoadFile(param_2, 0xe);
    Ov026_InstantiateAndLinkElements(param_1, obj, param_3);
    if (obj != 0) NNSi_FndFreeFromDefaultHeap((void *)obj);
}
