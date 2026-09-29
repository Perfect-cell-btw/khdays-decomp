/*
 * Ov002_RefreshSlotOccupancy - refresh the per-slot occupancy GameState flags (ids
 * 0x2001..0x2004) and the cached slot count. Called from the ov002 gameplay constructor
 * (Ov002_ConstructGameplayScene).
 *
 * First clears all four slot flags (0x2001+i, i=0..3). If the multiplayer bit (data_0204c240 &
 * 4) is not set, it marks slot 0 occupied (count byte at data_02042a1d = 1, data_02042a1c = 0,
 * GameState flag 0x2001 = 1). Otherwise it reads the slot count from the ROM accessor
 * (*(rom+4)), then for each slot polls Slot4_GetIfOccupied: sets flag 0x2001+j to 1 and counts
 * it when occupied, else clears it; the occupied count is written back to data_02042a1d.
 *
 * THUMB. `count` is int (a plain add increment; only the final store truncates to the byte),
 * and the occupancy loop is a for so the signed `j < count` entry test yields the ble guard.
 */

#include "nitro/types.h"
#include "game/engine.h"

extern int  Slot4_GetIfOccupied(int index);
extern u8   data_0204c240;
extern u8   data_02042a1c;
extern u8   data_02042a1d;

void Ov002_RefreshSlotOccupancy(void)
{
    int base = 0x2001;
    int i = 0;
    int rom;
    int count;
    int j;

    do {
        GameState_SetField(i + base, 1, 0);
        i++;
    } while (i < 4);

    if ((data_0204c240 & 4) == 0) {
        data_02042a1d = 1;
        data_02042a1c = 0;
        GameState_SetField(0x2001, 1, 1);
        return;
    }

    rom = Session_GetSlotTable();
    data_02042a1d = (u8)*(int *)(rom + 4);
    base = 0x2001;
    for (j = 0, count = 0; j < data_02042a1d; j++) {
        if (Slot4_GetIfOccupied(j) == 0) {
            GameState_SetField(j + base, 1, 0);
        } else {
            GameState_SetField(j + base, 1, 1);
            count++;
        }
    }
    data_02042a1d = count;
}
