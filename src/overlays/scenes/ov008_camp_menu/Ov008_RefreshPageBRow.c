/* Ov008_RefreshPageBRow -- Ov008_RefreshPageBRow: redraw page B's current row
 * and re-arm its scroll trackers.  Slot 0x1a's 32 x 24 grid and the sub BG2
 * screen are cleared, the row graphics uploaded, and the tag-tracker nodes
 * 0x15 (up), 0x16 (down) and 0x17 (select) of block 954c disarmed.  With a
 * cue request pending (word 3) both scroll nodes are rewound and re-armed
 * when the ov025 list (+0x200) holds more than one entry.  Otherwise the up
 * node is rewound and armed when the row (+0x1e8) is not the first, the
 * select node armed when it is the last, or the down node rewound and armed
 * when more rows follow.
 */

#include "nitro/types.h"

#define TAG_UP     0x15
#define TAG_DOWN   0x16
#define TAG_SELECT 0x17

typedef struct Ov008CueRequest {
    int aWord[4];
} Ov008CueRequest;

typedef struct Ov008PageB {
    u8  pad_000[0x1e8];
    int nRow;                 /* 0x1e8 */
    u8  pad_1ec[0x200 - 0x1ec];
    u8  list[4];              /* 0x200: ov025 list */
} Ov008PageB;

extern Ov008PageB *Ov008_GetPageB(void);                             /* Ov008_GetPageB */
extern int   Ov008_GetCtxBlock954c(void);                                   /* Ov008_GetCtxBlock954c */
extern void  Ov008_ClearGridRows(int nSlot, int nX, int nY, int nW, int nH); /* Ov008_ClearGridRows */
extern void *G2S_GetBG2ScrPtr(void);
extern void  MIi_CpuClearFast(u32 nValue, void *pDst, u32 nSize);
extern void  Ov008_LoadPageBRowGraphics(void);                                   /* Ov008_LoadPageBRowGraphics */
extern int   Ov008_FindActiveEntryByTag(int nOwner, u32 nTag);                   /* ov008_FindActiveEntryByTag */
extern void  Ov008_SetTagTrackerNodeArmed(int nOwner, int nEntry, int bArmed);     /* SetTagTrackerNodeArmed */
extern void  Ov008_RewindTagTrackerNode(int nOwner, int nEntry);                 /* RewindTagTrackerNode */
extern short Ov025_Res_GetCount(void *pList);                            /* list entry count */
extern Ov008CueRequest *Ov008_GetCueRequest(void);                        /* Ov008_GetCueRequest */

void Ov008_RefreshPageBRow(void)
{
    int nOwner;
    u32 nCount;
    Ov008PageB *pPage;

    pPage = Ov008_GetPageB();
    nOwner = Ov008_GetCtxBlock954c();
    Ov008_ClearGridRows(0x1a, 0, 0, 0x20, 0x18);
    MIi_CpuClearFast(0, G2S_GetBG2ScrPtr(), 0x800);
    Ov008_LoadPageBRowGraphics();
    Ov008_SetTagTrackerNodeArmed(nOwner, Ov008_FindActiveEntryByTag(nOwner, TAG_UP), 0);
    Ov008_SetTagTrackerNodeArmed(nOwner, Ov008_FindActiveEntryByTag(nOwner, TAG_DOWN), 0);
    Ov008_SetTagTrackerNodeArmed(nOwner, Ov008_FindActiveEntryByTag(nOwner, TAG_SELECT), 0);
    nCount = Ov025_Res_GetCount(pPage->list);
    if (Ov008_GetCueRequest()->aWord[3] != 0) {
        if (nCount > 1) {
            Ov008_RewindTagTrackerNode(nOwner, Ov008_FindActiveEntryByTag(nOwner, TAG_UP));
            Ov008_RewindTagTrackerNode(nOwner, Ov008_FindActiveEntryByTag(nOwner, TAG_DOWN));
            Ov008_SetTagTrackerNodeArmed(nOwner, Ov008_FindActiveEntryByTag(nOwner, TAG_UP), 1);
            Ov008_SetTagTrackerNodeArmed(nOwner, Ov008_FindActiveEntryByTag(nOwner, TAG_DOWN), 1);
        }
        return;
    }
    if (pPage->nRow != 0) {
        Ov008_RewindTagTrackerNode(nOwner, Ov008_FindActiveEntryByTag(nOwner, TAG_UP));
        Ov008_SetTagTrackerNodeArmed(nOwner, Ov008_FindActiveEntryByTag(nOwner, TAG_UP), 1);
    }
    if (pPage->nRow + 1 == nCount) {
        Ov008_SetTagTrackerNodeArmed(nOwner, Ov008_FindActiveEntryByTag(nOwner, TAG_SELECT), 1);
    } else if (pPage->nRow + 1 < nCount) {
        Ov008_RewindTagTrackerNode(nOwner, Ov008_FindActiveEntryByTag(nOwner, TAG_DOWN));
        Ov008_SetTagTrackerNodeArmed(nOwner, Ov008_FindActiveEntryByTag(nOwner, TAG_DOWN), 1);
    }
}
