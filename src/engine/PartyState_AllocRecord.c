/* Allocates the 0x7e-byte party record once. */

extern void *NNSi_FndAllocFromDefaultExpHeap(int size);
extern void *gPartyState[];

void PartyState_AllocRecord(void) {
    if (gPartyState[2] != 0) return;
    gPartyState[2] = NNSi_FndAllocFromDefaultExpHeap(0x7e);
}
