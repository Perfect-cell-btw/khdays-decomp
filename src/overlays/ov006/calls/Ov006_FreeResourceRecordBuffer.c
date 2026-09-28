/* Twin of Ov026_FreeResourceRecordBuffer: free the buffer held at *param_1 (if any). */
extern void NNSi_FndFreeFromDefaultHeap(void *ptr);
void Ov006_FreeResourceRecordBuffer(void **param_1) {
    if (*param_1 != 0) {
        NNSi_FndFreeFromDefaultHeap(*param_1);
    }
}
