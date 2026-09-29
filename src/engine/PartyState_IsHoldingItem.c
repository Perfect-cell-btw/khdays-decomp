/* Whether the party holds this item (data_0204c4f0 + 4). */

extern int data_0204c4f0;

int PartyState_IsHoldingItem(int item) {
    return item == *(unsigned short *)((char *)&data_0204c4f0 + 4);
}
