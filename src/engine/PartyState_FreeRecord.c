/* Frees the party state's 0x7e-byte record (data_0204c4f0 + 8) and clears the pointer; the
 * counterpart of PartyState_AllocRecord. */

extern void NNSi_FndFreeFromDefaultHeap();
extern int data_0204c4f0;

void PartyState_FreeRecord(void) {
    if (*(int *)((char *)&data_0204c4f0 + 8) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(int *)((char *)&data_0204c4f0 + 8));
        *(int *)((char *)&data_0204c4f0 + 8) = 0;
    }
}
