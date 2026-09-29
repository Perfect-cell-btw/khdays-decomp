/* Moves the mission cell with the tag to the position and runs its callback. */

#include "nitro/types.h"

typedef struct {
    u8 bytes[1];
} MissionCellList;

typedef struct {
    u8 pad_000[8];
    MissionCellList cell_list;
} Ov006RootContext;

extern Ov006RootContext *data_ov008_02090fa4;
extern void *Ov008_FindEntryByTag(MissionCellList *list, unsigned int tag);
extern void Ov008_Elem_SetPos(MissionCellList *list, void *cell, int x, int y);
extern void Ov008_TagTracker_InvokeCallback(MissionCellList *list, void *cell);

void Ov008_MissionRetargetCellByTag(u32 tag, int x, int y) {
    void *cell;

    cell = Ov008_FindEntryByTag(&data_ov008_02090fa4->cell_list, (u16)tag);
    Ov008_Elem_SetPos(&data_ov008_02090fa4->cell_list, cell, x, y);
    /* Written as a mask where another call truncates with a cast: mwcc would otherwise compute the
     * truncation once and keep it, while the ROM truncates again at each call. */
    cell = Ov008_FindEntryByTag(&data_ov008_02090fa4->cell_list, tag & 0xffff);
    Ov008_TagTracker_InvokeCallback(&data_ov008_02090fa4->cell_list, cell);
}
