/*
 * Ov002_ResetNineSlots - notify EntityMgr_AllocRecords(9) then push a zero-initialised 4-byte record for
 * each of the nine indices 0..8 via StoreToGlobalIndexedIfSet(index, &record). Part of the ov002 gameplay
 * bootstrap (dep of the constructor Ov002_ConstructGameplayScene).
 *
 * ARM. The record is a 4-byte stack int cleared byte-by-byte through a pointer (so mwcc keeps its
 * address in a register and clears via [reg]); the per-iteration low-byte write goes through the
 * plain stack slot ([sp]) instead, matching the original's split addressing.
 */

#include "nitro/types.h"
#include "game/engine.h"

void Ov002_ResetNineSlots(void)
{
    int buf;
    u8 *p;
    int i;

    EntityMgr_AllocRecords(9);
    p = (u8 *)&buf;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    for (i = 0; i < 9; i++) {
        *(u8 *)&buf = i & 0xff;
        StoreToGlobalIndexedIfSet(i & 0xff, &buf);
    }
}
