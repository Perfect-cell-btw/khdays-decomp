/* Makes the party hold an item or stop holding it (PartyState_SetHeldItem); the actor is not
 * looked at. */

extern void PartyState_SetHeldItem(unsigned short actor, int item);
void Ov022_SetHeldItem(int actor, unsigned short item, int held) {
    if (held != 0) PartyState_SetHeldItem(item, 1);
    else PartyState_SetHeldItem(item, 0);
}
