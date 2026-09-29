/* Sets the item the party holds (data_0204c4f0 + 4), or clears it to 0 when `held` is zero.
 * An item of kind 0xd is picked up this way, and fails while it is already held
 * (Ov022_ApplyActorAction); a pickup spot takes the player only while item 0xc is held, and clears
 * it (Ov015_SpotAssignPlayer). */

extern int data_0204c4f0;

void PartyState_SetHeldItem(short item, int held) {
    if (held != 0) *(short *)((char *)&data_0204c4f0 + 4) = item;
    else *(short *)((char *)&data_0204c4f0 + 4) = 0;
}
