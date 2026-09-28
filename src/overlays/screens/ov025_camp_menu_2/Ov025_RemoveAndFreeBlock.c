/* Removes the block from the object's list and frees it. */

extern int NNS_FndRemoveListObject();
extern void NNSi_FndFreeFromDefaultHeap();

void Ov025_RemoveAndFreeBlock(int arg0, int arg1) {
    NNS_FndRemoveListObject(arg0 + 0x1e7c, arg1);
    if (arg1 == 0) {
        return;
    }
    NNSi_FndFreeFromDefaultHeap(arg1);
}
