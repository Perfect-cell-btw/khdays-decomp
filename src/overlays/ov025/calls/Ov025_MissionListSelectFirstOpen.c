/* Ov025_MissionListSelectFirstOpen -- Ov008_MissionListSelectFirstOpen: select the first
 * mission whose 3-bit status field (0x28e4 + 3 * id) is below 2 (not yet
 * cleared); with a modal object up or touch enabled the selection is entry 0.
 * Then clears the two 8-bit scroll memories (0x35cd, 0x35df).
 *
 * When every mission is cleared nSel is never written: the ROM hands whatever
 * r4 held to the commit -- an original bug, kept as is.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Ov008MissionList {
    u8  pad_000[0x38];
    int bTouchEnabled;        /* 0x038 */
} Ov008MissionList;

typedef struct Ov008MissionListEntry {
    u8  pad_00[2];
    u16 missionId;            /* 0x02 */
} Ov008MissionListEntry;

#define FIELD_MISSION_STATUS 0x28e4
#define FIELD_SCROLL_A       0x35cd
#define FIELD_SCROLL_B       0x35df

extern int Ov025_GetCtxObject9630(void);                                    /* Ov008_GetCtxObject9630 */
extern u16 Ov025_GetCurrentListId(void);                                    /* mission entry count */
extern Ov008MissionListEntry *Ov025_GetNextMissionEntry_2(int nIndex);
extern u32 GameState_GetField(int nField, int nBits);                         /* GameState_GetField */
extern void GameState_SetField(int nField, int nBits, int nValue);            /* GameState_SetField */
extern void Ov025_MissionListSelectRow(Ov008MissionList *pList, u32 nWord, int nTarget);

static inline int Ov008_IsMissionCleared(Ov008MissionListEntry *pEntry)
{
    return GameState_GetField(pEntry->missionId * 3 + FIELD_MISSION_STATUS, 3) >= 2;
}

void Ov025_MissionListSelectFirstOpen(Ov008MissionList *pList)
{
    int nSel;
    int i;

    if (Ov025_GetCtxObject9630() != 0) {
        nSel = 0;
    } else if (pList->bTouchEnabled != 0) {
        nSel = 0;
    } else {
        for (i = 0; i <= (int)Ov025_GetCurrentListId(); i++) {
            if (!Ov008_IsMissionCleared(Ov025_GetNextMissionEntry_2(i))) {
                nSel = i;
                break;
            }
        }
    }
    Ov025_MissionListSelectRow(pList, nSel, -1);
    GameState_SetField(FIELD_SCROLL_A, 8, 0);
    GameState_SetField(FIELD_SCROLL_B, 8, 0);
}
