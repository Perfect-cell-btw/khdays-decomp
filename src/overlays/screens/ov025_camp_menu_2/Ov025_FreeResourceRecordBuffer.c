/* Frees the record's buffer when it has one. */

extern void NNSi_FndFreeFromDefaultHeap();

void Ov025_FreeResourceRecordBuffer(int arg0) {
    int p = *(int *)arg0;
    if (p != 0) {
        NNSi_FndFreeFromDefaultHeap(p);
    }
}
