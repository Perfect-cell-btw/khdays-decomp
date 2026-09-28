/* Ov025_MissionListSelectCurrent -- Ov008_MissionListSelectCurrent: re-select the mission the
 * context currently names (field 0x967c).  If that mission is not listed, or is
 * not found in the entry chain, fall back to the first open mission.  Otherwise
 * restore the remembered scroll (field 0x35df, 8 bits: (v + 16) / 32 rows) when
 * one is stored and select the found row.
 */

#include "nitro/types.h"

typedef struct Ov008MissionList Ov008MissionList;

typedef struct Ov008MissionListEntry {
    u8  pad_00[2];
    u16 missionId;            /* 0x02 */
} Ov008MissionListEntry;

#define FIELD_SCROLL_B 0x35df
#define ROW_UNITS      32

extern u32 Ov025_GetCtxField967c(void);                                    /* Ov008_GetCtxField967c: current mission id */
extern int Ov025_GetNextMissionEntry_5(u32 nMissionId);                          /* is the mission listed */
extern void Ov025_MissionListSelectFirstOpen(Ov008MissionList *pList);                /* Ov008_MissionListSelectFirstOpen */
extern Ov008MissionListEntry *Ov025_GetNextMissionEntry(Ov008MissionListEntry *pEntry); /* Ov008_GetNextMissionEntry */
extern u16 Ov025_GetCurrentListId(void);                                    /* mission entry count */
extern int GameState_GetField(int nField, int nBits);                         /* GameState_GetField */
extern void Ov025_MissionListSelectRow(Ov008MissionList *pList, u32 nWord, int nTarget);

void Ov025_MissionListSelectCurrent(Ov008MissionList *pList)
{
    int nRow;
    Ov008MissionListEntry *pEntry;
    int nScroll;

    if (Ov025_GetNextMissionEntry_5(Ov025_GetCtxField967c()) == 0) {
        Ov025_MissionListSelectFirstOpen(pList);
        return;
    }
    nRow = 0;
    for (pEntry = Ov025_GetNextMissionEntry(0); pEntry != 0; pEntry = Ov025_GetNextMissionEntry(pEntry)) {
        if (pEntry->missionId == Ov025_GetCtxField967c()) {
            break;
        }
        nRow++;
    }
    if (nRow < Ov025_GetCurrentListId()) {
        nScroll = GameState_GetField(FIELD_SCROLL_B, 8);
        if (nScroll >= 0) {
            Ov025_MissionListSelectRow(pList, (nScroll + ROW_UNITS / 2) / ROW_UNITS, -1);
        }
        Ov025_MissionListSelectRow(pList, nRow, -1);
    } else {
        Ov025_MissionListSelectFirstOpen(pList);
    }
}
