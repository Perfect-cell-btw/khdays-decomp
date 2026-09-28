/* Ov025_ScrollList_BuildRows -- Ov025_ScrollList_BuildRows: build the day rows of the scrolling list
 * (+4, 16 bytes each, one per entry of the day table: 0208df94 entries, first day 0208df9c, name
 * string 0208dfb0).  The days go up to the current day (game-state field 9; 400 once the story
 * chapter, field 3, has reached 6; at least 8): each table entry whose successor starts within
 * the limit becomes the span first day .. next first day - 1, kept (with its name from the
 * string set +0x1c, 02089894) only when a visible mission falls inside it
 * (Ov025_MissionList_HasVisibleMissionInDays through 0208dd20); +8 counts the rows kept. */
#include "nitro/types.h"

typedef struct Ov025ScrollRow {
    int  nFirstDay;           /* 0x00: the day span of the row */
    int  nLastDay;            /* 0x04 */
    const u16 *pName;         /* 0x08 */
    int  nField0c;            /* 0x0c */
} Ov025ScrollRow;             /* 0x10 */

typedef struct Ov025ScrollList {
    int  nField000;           /* 0x000 */
    Ov025ScrollRow *pRows;    /* 0x004: the day rows */
    int  nCount;              /* 0x008 */
    int  bTouching;           /* 0x00c: the stylus holds the scroll bar */
    int  bPressed;            /* 0x010 */
    int  bRowsDirty;          /* 0x014: re-upload the row surfaces */
    int  bMarkersDirty;       /* 0x018: re-upload the marker screen */
    u8   strings[0x10];       /* 0x01c: the row name strings */
    void *pNode;              /* 0x02c: the shared UI list node */
} Ov025ScrollList;

extern int   Ov025_GetScrollListCapacity(void);                             /* Ov025_DayTable_Count */
extern u16   Ov025_GetTableValue(u16 nEntry);                       /* Ov025_DayTable_FirstDay */
extern u16   Ov025_GetTableValueB(u16 nEntry);                       /* Ov025_DayTable_NameString */
extern void *NNSi_FndAllocFromDefaultExpHeap(u32 nSize);
extern u32   GameState_GetField(int nField, int nBits);                  /* GameState_GetField */
extern int   Ov025_MissionList_HasVisibleInDays(u16 nFirstDay, u16 nLastDay);      /* Ov025_HasVisibleMissionInDays */
extern const u16 *Ov025_GetVarRecordByIndex(void *pStrings, int nIndex);  /* Ov025_GetString */

void Ov025_ScrollList_BuildRows(Ov025ScrollList *pList)
{
    int nEntries;
    Ov025ScrollRow *pRow;
    int i;
    int nDayLimit;
    int nNextDay;

    nEntries = Ov025_GetScrollListCapacity();
    pList->nCount = 0;
    pList->pRows = NNSi_FndAllocFromDefaultExpHeap(nEntries * sizeof(Ov025ScrollRow));
    if (GameState_GetField(0x44e, 3) < 6) {
        nDayLimit = GameState_GetField(0, 9);
    } else {
        nDayLimit = 400;
    }
    pRow = pList->pRows;
    if (nDayLimit < 8) {
        nDayLimit = 8;
    }
    for (i = 0; i < nEntries - 1; i++) {
        nNextDay = Ov025_GetTableValue(i + 1);
        if (nDayLimit < nNextDay) {
            return;
        }
        pRow->nFirstDay = Ov025_GetTableValue(i);
        pRow->nLastDay = nNextDay - 1;
        if (Ov025_MissionList_HasVisibleInDays(pRow->nFirstDay, pRow->nLastDay) != 0) {
            pRow->pName = Ov025_GetVarRecordByIndex(pList->strings, Ov025_GetTableValueB(i));
            pRow++;
            pList->nCount++;
        }
    }
}
