/* Frees the party state's 0x7e-byte record (gPartyState + 8) and clears the pointer; the
 * counterpart of PartyState_AllocRecord. */

extern void NNSi_FndFreeFromDefaultHeap();
extern int gPartyState;

void PartyState_FreeRecord(void) {
    if (*(int *)((char *)&gPartyState + 8) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(int *)((char *)&gPartyState + 8));
        *(int *)((char *)&gPartyState + 8) = 0;
    }
}
