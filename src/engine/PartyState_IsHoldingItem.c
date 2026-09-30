/* Whether the party holds this item (gPartyState + 4). */

extern int gPartyState;

int PartyState_IsHoldingItem(int item) {
    return item == *(unsigned short *)((char *)&gPartyState + 4);
}
