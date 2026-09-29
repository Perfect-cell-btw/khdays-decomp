/* Copies the party equipment tables; returns 1. */

#include "game/engine.h"

int Ov013_CopyEquipTables(void) {
    PartyState_CopyEquipTables(1, 1);
    return 1;
}
