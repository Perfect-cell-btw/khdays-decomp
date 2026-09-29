/* Whether the party holds this item (PartyState_IsHoldingItem); the actor is not looked at. */

#include "game/engine.h"

int Ov022_IsHoldingItem(int actor, int item) { return PartyState_IsHoldingItem(item); }
