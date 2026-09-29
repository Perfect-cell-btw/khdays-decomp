/* Clears the item the party holds (data_0204c4f0 + 4). */

extern int data_0204c4f0;

void PartyState_ClearHeldItem(void) {
    *(short *)((char *)&data_0204c4f0 + 4) = 0;
}
