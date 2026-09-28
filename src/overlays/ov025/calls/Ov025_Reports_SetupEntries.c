/* Ov025_Reports_SetupEntries -- Ov025_Reports_SetupEntries: bind the reports / enemy profiles page's
 * sprites for its set (data_ov025_020b4228 row picked by the mode word +0x258).  The page's tag
 * tracker (+0xb4) and the shared tracker (Ov008_GetCtxBlock954c 02084a64) load the set's
 * tracker member (Ov008_PackSlotTag 02084d18; 020891dc); cell 2 is invoked (02089544) and
 * cells 3 / 4 kept (+0x260 / +0x264; 020894b0) with cell 6 as the selection marker (+0x268) for
 * the reports and cell 3 for the enemies.  The entry context (+0xb8) takes the layout template
 * data_ov025_020b4240 with the set's layout member (020883f8), binds the resource named by
 * data_ov025_020b4218 (02084d94 / 02088410), loads the set's 0x5c entries (0208832c) and
 * releases the list slots in mode 2 (02088a7c); entries 3, 4 and 1 become the up arrow, the
 * down arrow and the scroll knob (+0x26c / +0x270 / +0x274) and the knob is shown (0208884c).
 * The ten rows (+0xd0, seven entries each: ids 0x33 / 0x3d / 0x47 / 0x51 / 0x5b / 0x6f / 0x65
 * plus the row) release the second pair of four of their cells (020888b0), and entries
 * 0x65..0x6e resolve through Ov025_Reports_OnRowPressed (02088420). */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Ov008LayoutTemplate {
    u32  words[4];
} Ov008LayoutTemplate;

typedef struct Ov025ReportsRow {
    void *pTitle;             /* 0x00: entry 0x33 + row */
    void *pMark1;             /* 0x04: entry 0x3d + row */
    void *pMark2;             /* 0x08: entry 0x47 + row */
    void *pMark3;             /* 0x0c: entry 0x51 + row */
    void *pMark4;             /* 0x10: entry 0x5b + row */
    void *pBadge;             /* 0x14: entry 0x6f + row */
    void *pNumber;            /* 0x18: entry 0x65 + row */
} Ov025ReportsRow;            /* 0x1c */

typedef struct Ov025ReportsPage {
    u8   pad_000[0x6c];
    u8   text[0xc];           /* 0x06c: the report / enemy strings */
    u8   surface[0x3c];       /* 0x078 */
    int  nTracker;            /* 0x0b4: the tag tracker */
    int  nCtx;                /* 0x0b8: the entry context */
    u8   pad_0bc[0xc8 - 0xbc];
    int  nState;              /* 0x0c8 */
    u8   pad_0cc[0xd0 - 0xcc];
    Ov025ReportsRow aRow[10]; /* 0x0d0 */
    void *pEntries;           /* 0x1e8: the per-report records (0x40 bytes each) */
    u8   pad_1ec[0x230 - 0x1ec];
    void *pTable;             /* 0x230: the report table file */
    void *pSpriteFile;        /* 0x234: the report sprite file */
    u8   pad_238[0x248 - 0x238];
    u16  aSeen[8];            /* 0x248: the seen bits per group */
    int  bMissionMode;        /* 0x258: enemy profiles rather than reports */
    int  nField25c;           /* 0x25c */
    void *pCell3;             /* 0x260 */
    void *pCell4;             /* 0x264 */
    void *pSelectCell;        /* 0x268 */
    void *pUpArrow;           /* 0x26c */
    void *pDownArrow;         /* 0x270 */
    void *pKnob;              /* 0x274 */
} Ov025ReportsPage;           /* 0x278: a view of page A (Ov008_GetPageA) */

typedef struct Ov025ReportsSet {
    u8   nBgMember;           /* 0x00: the background archive member */
    u8   nLayoutMember;       /* 0x01 */
    u8   nTrackerMember;      /* 0x02 */
    u8   nEntriesMember;      /* 0x03 */
    u8   nField04;            /* 0x04 */
} Ov025ReportsSet;

extern Ov025ReportsPage *Ov025_GetPageA(void);                 /* Ov008_GetPageA */
extern u32   Ov025_PackSlotTag(int nMember);                      /* Ov008_PackSlotTag */
extern void  Ov025_LoadBlockDispatchThreeThenFree(int nTracker, u32 nTag);           /* Ov008_TagTracker_Load */
extern int   Ov025_GetCtxBlock954c(void);                             /* Ov008_GetCtxBlock954c */
extern void *Ov025_FindEntryByTag(int nTracker, int nTag);           /* Ov008_TagTracker_FindCell */
extern void  Ov025_TagTracker_InvokeCallback(int nTracker, void *pCell);        /* Ov008_TagTracker_InvokeCallback */
extern void  Ov025_InitFromDescAndMark(int nCtx, Ov008LayoutTemplate *pLayout); /* Ov008_SetLayout */
extern void *Ov025_PackHandleTagB(int nIndex);                       /* resource by index */
extern void  func_ov025_02088410(int nCtx, void *pResource);        /* ForwardTo_02031d90 */
extern void  Ov025_LoadBlockProcessAndFree(int nCtx, u32 nTag, int nCount);   /* Ov008_LoadBlockProcessAndFree */
extern void  Ov025_ReleaseAllListSlots(int nCtx, int nMode);              /* Ov008_ForEachListNode */
extern void *Ov025_FindEntryById(int nCtx, int nId);                /* FindEntryById */
extern void  Ov025_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible); /* SetEntrySlotsVisible */
extern void  Ov025_ReleaseTwoSlots(int nCtx, void *pEntry);           /* Ov008_ReleaseTwoSlots */
extern void  Ov025_ResolveEntryStoreWord(int nCtx, int nId, void *pCallback); /* Ov008_ResolveEntryStoreWord */
extern void  Ov025_Reports_OnRowPressed(void);
extern Ov008LayoutTemplate data_ov025_020b4240;
extern const Ov025ReportsSet data_ov025_020b4228[];                 /* per mode */
extern const u8 data_ov025_020b4218[];                              /* the resource index per mode */

void Ov025_Reports_SetupEntries(void)
{
    Ov008LayoutTemplate layout;
    Ov025ReportsPage *pPage;
    int nShared;
    int i;
    Ov025ReportsRow *pRow;

    layout = data_ov025_020b4240;
    pPage = Ov025_GetPageA();
    Ov025_LoadBlockDispatchThreeThenFree(pPage->nTracker, Ov025_PackSlotTag(data_ov025_020b4228[pPage->bMissionMode].nTrackerMember));
    nShared = Ov025_GetCtxBlock954c();
    Ov025_LoadBlockDispatchThreeThenFree(nShared, Ov025_PackSlotTag(data_ov025_020b4228[pPage->bMissionMode].nTrackerMember));
    Ov025_TagTracker_InvokeCallback(pPage->nTracker, Ov025_FindEntryByTag(pPage->nTracker, 2));
    pPage->pCell3 = Ov025_FindEntryByTag(pPage->nTracker, 3);
    pPage->pCell4 = Ov025_FindEntryByTag(pPage->nTracker, 4);
    if (pPage->bMissionMode == 0) {
        pPage->pSelectCell = Ov025_FindEntryByTag(pPage->nTracker, 6);
    } else {
        pPage->pSelectCell = pPage->pCell3;
    }
    layout.words[0] = Ov025_PackSlotTag(data_ov025_020b4228[pPage->bMissionMode].nLayoutMember);
    Ov025_InitFromDescAndMark(pPage->nCtx, &layout);
    func_ov025_02088410(pPage->nCtx, Ov025_PackHandleTagB(data_ov025_020b4218[pPage->bMissionMode]));
    Ov025_LoadBlockProcessAndFree(pPage->nCtx, Ov025_PackSlotTag(data_ov025_020b4228[pPage->bMissionMode].nEntriesMember), 0x5c);
    Ov025_ReleaseAllListSlots(pPage->nCtx, 2);
    pPage->pUpArrow = Ov025_FindEntryById(pPage->nCtx, 3);
    pPage->pDownArrow = Ov025_FindEntryById(pPage->nCtx, 4);
    pPage->pKnob = Ov025_FindEntryById(pPage->nCtx, 1);
    Ov025_SetEntrySlotsVisible(pPage->nCtx, Ov025_FindEntryById(pPage->nCtx, 1), 1);
    i = 0;
    pRow = pPage->aRow;
    for (; i < 10; i++) {
        pRow->pTitle = Ov025_FindEntryById(pPage->nCtx, i + 0x33);
        pRow->pMark1 = Ov025_FindEntryById(pPage->nCtx, i + 0x3d);
        pRow->pMark2 = Ov025_FindEntryById(pPage->nCtx, i + 0x47);
        pRow->pMark3 = Ov025_FindEntryById(pPage->nCtx, i + 0x51);
        pRow->pMark4 = Ov025_FindEntryById(pPage->nCtx, i + 0x5b);
        pRow->pBadge = Ov025_FindEntryById(pPage->nCtx, i + 0x6f);
        pRow->pNumber = Ov025_FindEntryById(pPage->nCtx, i + 0x65);
        Ov025_ReleaseTwoSlots(pPage->nCtx, pRow->pMark1);
        Ov025_ReleaseTwoSlots(pPage->nCtx, pRow->pMark2);
        Ov025_ReleaseTwoSlots(pPage->nCtx, pRow->pMark3);
        Ov025_ReleaseTwoSlots(pPage->nCtx, pRow->pBadge);
        pRow++;
    }
    Ov025_ResolveEntryStoreWord(pPage->nCtx, 0x65, Ov025_Reports_OnRowPressed);
    Ov025_ResolveEntryStoreWord(pPage->nCtx, 0x66, Ov025_Reports_OnRowPressed);
    Ov025_ResolveEntryStoreWord(pPage->nCtx, 0x67, Ov025_Reports_OnRowPressed);
    Ov025_ResolveEntryStoreWord(pPage->nCtx, 0x68, Ov025_Reports_OnRowPressed);
    Ov025_ResolveEntryStoreWord(pPage->nCtx, 0x69, Ov025_Reports_OnRowPressed);
    Ov025_ResolveEntryStoreWord(pPage->nCtx, 0x6a, Ov025_Reports_OnRowPressed);
    Ov025_ResolveEntryStoreWord(pPage->nCtx, 0x6b, Ov025_Reports_OnRowPressed);
    Ov025_ResolveEntryStoreWord(pPage->nCtx, 0x6c, Ov025_Reports_OnRowPressed);
    Ov025_ResolveEntryStoreWord(pPage->nCtx, 0x6d, Ov025_Reports_OnRowPressed);
    Ov025_ResolveEntryStoreWord(pPage->nCtx, 0x6e, Ov025_Reports_OnRowPressed);
}
