/* Sets the party's interaction state (data_0204c4f0 + 4), or clears it to 0 when `set` is zero.
 * Item kind 0xd sets it; a pickup spot clears state 0xc when it takes the player
 * (Ov015_SpotAssignPlayer); IsArgEqualGlobalHalf4 tests it. */

extern int data_0204c4f0;

void PartyState_SetInteraction(short state, int set) {
    if (set != 0) *(short *)((char *)&data_0204c4f0 + 4) = state;
    else *(short *)((char *)&data_0204c4f0 + 4) = 0;
}
