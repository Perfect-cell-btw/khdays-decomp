/* Clears the item the party holds (gPartyState + 4). */

extern int gPartyState;

void PartyState_ClearHeldItem(void) {
    *(short *)((char *)&gPartyState + 4) = 0;
}
