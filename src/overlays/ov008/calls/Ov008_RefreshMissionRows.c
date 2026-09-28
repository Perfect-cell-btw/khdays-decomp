/* Ov008_RefreshMissionRows -- Ov008_RefreshMissionRows: unless the list is animating,
 * fill the six visible rows from the mission entries in list order; then mark
 * the list dirty and queue the upload of the three surfaces of every row that
 * was left unfilled.
 */
typedef unsigned char u8;

#define ROW_COUNT 6

typedef struct TileSurface {
    u8 pad[0x3c];
} TileSurface;

typedef struct Ov008MissionListEntry Ov008MissionListEntry;

typedef struct Ov008MissionList {
    u8          pad_000[0x48];
    int         bDirty;                  /* 0x048 */
    u8          pad_04c[0x68 - 0x4c];
    int         bAnimating;              /* 0x068 */
    u8          pad_06c[0x84 - 0x6c];
    TileSurface aRowNameSurface[ROW_COUNT];   /* 0x084 */
    TileSurface aRowInfoSurface[ROW_COUNT];   /* 0x1ec */
    TileSurface aRowExtraSurface[ROW_COUNT];  /* 0x354 */
} Ov008MissionList;

extern Ov008MissionListEntry *Ov008_GetNextMissionEntry(Ov008MissionListEntry *pEntry); /* Ov008_GetNextMissionEntry */
extern void Ov008_DrawMissionRow(Ov008MissionList *pList, int nRow, Ov008MissionListEntry *pEntry);
extern void EnqueueObjGfxCommand(void *pSurface);                                   /* EnqueueObjGfxCommand */

void Ov008_RefreshMissionRows(Ov008MissionList *pList)
{
    int nRow = 0;
    Ov008MissionListEntry *pEntry;

    if (pList->bAnimating == 0) {
        for (pEntry = Ov008_GetNextMissionEntry(0); pEntry != 0; pEntry = Ov008_GetNextMissionEntry(pEntry)) {
            Ov008_DrawMissionRow(pList, nRow, pEntry);
            nRow++;
            if (nRow >= ROW_COUNT) {
                break;
            }
        }
    }
    pList->bDirty = 1;
    for (; nRow < ROW_COUNT; nRow++) {
        EnqueueObjGfxCommand(&pList->aRowNameSurface[nRow]);
        EnqueueObjGfxCommand(&pList->aRowInfoSurface[nRow]);
        EnqueueObjGfxCommand(&pList->aRowExtraSurface[nRow]);
    }
}
