/* Ov025_ReportDetail_Refresh -- Ov025_ReportDetail_Refresh: redraw the report detail view of page B
 * (Ov025_GetPageB 02084b14) when its record (+0x50) is dirty (+0xa).  In reports mode (+0x54
 * clear) the record's number is shown with the three digit entries (+0x60.., cells by
 * Ov025_SetEntryCell 02088928, leading zeros hidden) and the title entry; a read record lights
 * cell 1 of the tag tracker (+0x44).  The mark entry (+0x6c) follows bit 9 of the record; the
 * page count, slash, total and arrow entries (+0x70..+0x80) show when the record has a second
 * text page.  The text surface (+4) is cleared (02030158): string 0 heads it in colour 2, then
 * a read enemy profile gets its chapter lines (Ov025_ReportDetail_DrawLines 020b03dc), any other
 * record with nothing pending its current text page (Ov025_ReportDetail_DrawWrappedText
 * 020b02b8, colour 4 read / 6 unread), and the name (or "????????" while enemies are pending)
 * goes at x 0x5c (reports) / 0x18; the surface is uploaded (020300f8).  VRAM slot 0x19 is marked,
 * the record cleaned, and
 * slot 0x1a filled with tile 0xa0: on the first text page of a record with a picture (+8 >= 0)
 * its palette and characters are queued (GFXi_EnqueueCommand 0x1f / 0x16) and the 11 x 8 screen
 * block copied to rows 5..12 at column 0x13 (MIi_CpuCopy16). */

#include "nitro/types.h"

typedef struct Ov008CharacterBlock { u8 pad_0000[0x10]; u32 size; void *data; } Ov008CharacterBlock;
typedef struct Ov008PaletteBlock   { u8 pad_0000[0x08]; u32 size; void *data; } Ov008PaletteBlock;
typedef struct Ov008ScreenBlock    { u8 pad_0000[0x08]; u32 size; u16 data[1]; } Ov008ScreenBlock;

typedef struct Ov025ReportsEntry {
    u16  nId : 9;             /* 0x00 bits 0-8 */
    u16  nFlag9 : 1;          /* 0x00 bit 9: the mark entry */
    u16  nPending : 6;        /* 0x00 bits 10-15: enemies still to defeat */
    u8   pad_02[6];
    s16  nPicture;            /* 0x08: -1 = no picture */
    u8   bDirty;              /* 0x0a: the detail view redraws it */
    u8   bRead;               /* 0x0b */
    struct Ov025ReportsEntry *pRead; /* 0x0c: the read variant of the record, if any */
    const u16 *pName;         /* 0x10: the title */
    const u16 *apPage[2];     /* 0x14: the two text pages */
    Ov008ScreenBlock *pScreen; /* 0x1c: the picture */
    Ov008CharacterBlock *pChar; /* 0x20 */
    Ov008PaletteBlock *pPalette; /* 0x24 */
    const u16 *apLine[6];     /* 0x28: one line per chapter */
    u8   nPage;               /* 0x40: the text page shown (page A keeps it after its copy) */
} Ov025ReportsEntry;

typedef struct Ov025ReportDetailPage {
    int  nField00;            /* 0x00 */
    u8   surface[0x3c];       /* 0x04: the text surface (TileSurface) */
    int  nField40;            /* 0x40 */
    int  nTracker;            /* 0x44: the tag tracker */
    int  nCtx;                /* 0x48: the entry context */
    int  nField4c;            /* 0x4c */
    Ov025ReportsEntry *pEntry; /* 0x50: the report shown */
    int  bMissionMode;        /* 0x54: enemy profiles rather than reports */
    int  nChapter;            /* 0x58: GameState field 3, +1 under 6 */
    void *pTitleEntry;        /* 0x5c: entry 0 */
    void *apDigit[3];         /* 0x60: entries 1..3 */
    void *pMarkEntry;         /* 0x6c: entry 4 */
    void *pCountEntry;        /* 0x70: entry 5 */
    void *pSlashEntry;        /* 0x74: entry 7 */
    void *pTotalEntry;        /* 0x78: entry 6 */
    void *pEntry8;            /* 0x7c: entry 8 */
    void *pEntry9;            /* 0x80: entry 9 */
} Ov025ReportDetailPage;      /* 0x84 */

extern Ov025ReportDetailPage *Ov025_GetPageB(void);            /* Ov025_GetPageB */
extern void *Ov025_FindEntryByTag(int nTracker, int nTag);           /* Ov025_TagTracker_FindCell */
extern void  Ov025_TagTracker_InvokeCallback(int nTracker, void *pCell);        /* Ov025_TagTracker_InvokeCallback */
extern void  Ov025_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible); /* SetEntrySlotsVisible */
extern void  Ov025_ReleaseTwoSlotsEx_2(int nCtx, void *pEntry, int nCell); /* Ov025_SetEntryCell */
extern void  Obj_InvokeInnerVtable4(void *pSurface);                         /* TileSurface_Clear */
extern const u16 *Ov025_PageA_GetVarRecord(int nString);                 /* Ov025_Reports_GetString */
extern void  Ov025_DrawStringShadowed(int nX, int nY, int nColour, u32 nFlags, const u16 *pText); /* Ov025_DrawStringShadowed */
extern void  Ov025_ReportDetail_DrawLines(Ov025ReportsEntry *pEntry);        /* Ov025_ReportDetail_DrawLines */
extern void  Ov025_ReportDetail_DrawWrappedText(int nX, int nY, int nColour, int nUnused, const u16 *pText); /* Ov025_ReportDetail_DrawWrappedText */
extern void  EnqueueObjGfxCommand(void *pSurface);                         /* TileSurface_Upload */
extern void  Ov025_MarkSlotUsed(int nSlot);                        /* Ov025_MarkSlotUsed */
extern u8   *Ov025_LookupEntry(int nSlot);                        /* Ov025_SlotVram */
extern void  MIi_CpuClearFast(u32 nValue, void *pDst, u32 nSize);
extern void  MIi_CpuCopy16(const void *pSrc, void *pDst, u32 nSize);
extern void  GFXi_EnqueueCommand(int nCommand, int nArg, const void *pData, u32 nSize);
extern const u16 data_ov025_020b5724[];                             /* "????????" */
void Ov025_ReportDetail_Refresh(void)
{
    Ov025ReportDetailPage *pPage;
    int nId;
    Ov025ReportsEntry *pEntry;
    int bReports;
    int i;
    int bHasPage2;
    u8 *pVram;

    pPage = Ov025_GetPageB();
    pEntry = pPage->pEntry;
    if (pEntry->bDirty == 0) {
        return;
    }
    bReports = pPage->bMissionMode == 0;
    nId = pEntry->nId;
    Ov025_TagTracker_InvokeCallback(pPage->nTracker, Ov025_FindEntryByTag(pPage->nTracker, (u16)(bReports && pEntry->bRead != 0)));
    Ov025_SetEntrySlotsVisible(pPage->nCtx, pPage->pTitleEntry, bReports);
    for (i = 0; i < 3; i++) {
        Ov025_ReleaseTwoSlotsEx_2(pPage->nCtx, pPage->apDigit[i], (u16)(nId % 10));
        Ov025_SetEntrySlotsVisible(pPage->nCtx, pPage->apDigit[i], (bReports && (i == 0 || nId != 0)) ? 1 : 0);
        nId /= 10;
    }
    Ov025_SetEntrySlotsVisible(pPage->nCtx, pPage->pMarkEntry, pEntry->nFlag9);
    bHasPage2 = *pEntry->apPage[1] != 0;
    Ov025_SetEntrySlotsVisible(pPage->nCtx, pPage->pCountEntry, bHasPage2);
    Ov025_SetEntrySlotsVisible(pPage->nCtx, pPage->pSlashEntry, bHasPage2);
    Ov025_SetEntrySlotsVisible(pPage->nCtx, pPage->pTotalEntry, bHasPage2);
    Ov025_SetEntrySlotsVisible(pPage->nCtx, pPage->pEntry8, bHasPage2);
    Ov025_SetEntrySlotsVisible(pPage->nCtx, pPage->pEntry9, bHasPage2);
    if (bHasPage2) {
        Ov025_ReleaseTwoSlotsEx_2(pPage->nCtx, pPage->pCountEntry, (u16)(pPage->pEntry->nPage + 1));
        Ov025_ReleaseTwoSlotsEx_2(pPage->nCtx, pPage->pSlashEntry, 2);
    }
    Obj_InvokeInnerVtable4(pPage->surface);
    Ov025_DrawStringShadowed(0xf9, 2, 2, 0x821, Ov025_PageA_GetVarRecord(0));
    if (bReports == 0 && pEntry->bRead != 0) {
        Ov025_ReportDetail_DrawLines(pEntry);
    } else if (pEntry->nPending == 0) {
        Ov025_ReportDetail_DrawWrappedText(0x12, 0x2b, pEntry->bRead ? 4 : 6, 0x209, pEntry->apPage[pPage->pEntry->nPage]);
    }
    Ov025_DrawStringShadowed(bReports ? 0x5c : 0x18, 0x1b, 2, 0x209, pEntry->nPending != 0 ? data_ov025_020b5724 : pEntry->pName);
    EnqueueObjGfxCommand(pPage->surface);
    Ov025_MarkSlotUsed(0x19);
    pEntry->bDirty = 0;
    MIi_CpuClearFast(0x00a000a0, Ov025_LookupEntry(0x1a), 0x800);
    if (pEntry->nPicture >= 0 && pPage->pEntry->nPage == 0) {
        pVram = Ov025_LookupEntry(0x1a);
        GFXi_EnqueueCommand(0x1f, 0, pEntry->pPalette->data, 0x160);
        GFXi_EnqueueCommand(0x16, 0, pEntry->pChar->data, pEntry->pChar->size);
        for (i = 0; i < 8; i++) {
            MIi_CpuCopy16(&pEntry->pScreen->data[i * 0xb], pVram + 0x26 + (i + 5) * 0x40, 0x16);
        }
    }
    Ov025_MarkSlotUsed(0x1a);
}
