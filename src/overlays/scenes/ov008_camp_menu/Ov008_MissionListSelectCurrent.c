/* Ov008_MissionListSelectCurrent -- Ov008_MissionListSelectCurrent: re-select the mission the
 * context currently names (field 0x967c).  If that mission is not listed, or is
 * not found in the entry chain, fall back to the first open mission.  Otherwise
 * restore the remembered scroll (field 0x35df, 8 bits: (v + 16) / 32 rows) when
 * one is stored and select the found row.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Ov008MissionList Ov008MissionList;

typedef struct Ov008MissionListEntry {
    u8  pad_00[2];
    u16 missionId;            /* 0x02 */
} Ov008MissionListEntry;

#define FIELD_SCROLL_B 0x35df
#define ROW_UNITS      32

extern u32 Ov008_GetCtxField967c(void);                                    /* Ov008_GetCtxField967c: current mission id */
extern int Ov008_GetNextMissionEntry_5(u32 nMissionId);                          /* is the mission listed */
extern void Ov008_MissionListSelectFirstOpen(Ov008MissionList *pList);                /* Ov008_MissionListSelectFirstOpen */
extern Ov008MissionListEntry *Ov008_GetNextMissionEntry(Ov008MissionListEntry *pEntry); /* Ov008_GetNextMissionEntry */
extern u16 Ov008_GetCurrentListId(void);                                    /* mission entry count */
extern int GameState_GetField(int nField, int nBits);                         /* GameState_GetField */
extern void Ov008_MissionListSelectRow(Ov008MissionList *pList, u32 nWord, int nTarget);

void Ov008_MissionListSelectCurrent(Ov008MissionList *pList)
{
    int nRow;
    Ov008MissionListEntry *pEntry;
    int nScroll;

    if (Ov008_GetNextMissionEntry_5(Ov008_GetCtxField967c()) == 0) {
        Ov008_MissionListSelectFirstOpen(pList);
        return;
    }
    nRow = 0;
    for (pEntry = Ov008_GetNextMissionEntry(0); pEntry != 0; pEntry = Ov008_GetNextMissionEntry(pEntry)) {
        if (pEntry->missionId == Ov008_GetCtxField967c()) {
            break;
        }
        nRow++;
    }
    if (nRow < Ov008_GetCurrentListId()) {
        nScroll = GameState_GetField(FIELD_SCROLL_B, 8);
        if (nScroll >= 0) {
            Ov008_MissionListSelectRow(pList, (nScroll + ROW_UNITS / 2) / ROW_UNITS, -1);
        }
        Ov008_MissionListSelectRow(pList, nRow, -1);
    } else {
        Ov008_MissionListSelectFirstOpen(pList);
    }
}
