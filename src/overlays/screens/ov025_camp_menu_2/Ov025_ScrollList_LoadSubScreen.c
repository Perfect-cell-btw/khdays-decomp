/* Ov025_ScrollList_LoadSubScreen -- Ov025_ScrollList_LoadSubScreen: load the scrolling list's sub-screen
 * graphics.  Its background comes from archive member 0x14 (Ov008_PackSlotTag 02084d18) when
 * the language word (02024e5c) is 1, else from localised sub-file 6 (02084d50); the file
 * (0201ef9c, heap 0xe) gives the palette / character / screen cell (Res_LoadSpriteSet 02024c94):
 * the palette goes to the sub BG palette RAM (GXS_LoadBGPltt) and the characters to sub BG3
 * (GXS_LoadBG3Char), then the file is freed.  Members 0x10 and 0x11 load their CHAR blocks into
 * sub BG0 and BG2 (020ae340), cells 0xa and 0xb of the shared tag tracker (02084a64) are invoked
 * (Ov008_TagTracker_InvokeCallback 02089544) and VRAM slots 0x19..0x1b marked used (02084964). */

#include "nitro/types.h"

typedef struct Ov008CharacterBlock { u8 pad_0000[0x10]; u32 size; void *data; } Ov008CharacterBlock;

typedef struct Ov008PaletteBlock   { u8 pad_0000[0x08]; u32 size; void *data; } Ov008PaletteBlock;

typedef struct Ov008ScreenBlock    { u8 pad_0000[0x08]; u32 size; u8 data[1]; } Ov008ScreenBlock;

typedef struct Ov008ResourceCell {
    Ov008ScreenBlock    *screen;
    Ov008CharacterBlock *character;
    Ov008PaletteBlock   *palette;
} Ov008ResourceCell;

typedef void (*Ov025CharLoader)(const void *pSrc, u32 nOffset, u32 nSize);

extern int   func_02024e5c(void);                                   /* LoadGlobalShort_0204c1ec: the language */
extern u32   Ov025_PackSlotTag(int nMember);                      /* Ov008_PackSlotTag */
extern u32   Ov025_PackHandleTag(int nSubFile);                     /* Ov008_PackLocalisedTag */
extern void *Archive_LoadFile(u32 nTag, int nHeap);                    /* Res_Open */
extern void  Res_LoadSpriteSet(Ov008ResourceCell *pCell, void *pFile, int nScreen, int nChar, int nPalette); /* Res_LoadSpriteSet */
extern void  GXS_LoadBGPltt(const void *pSrc, u32 nOffset, u32 nSize);
extern void  GXS_LoadBG3Char(const void *pSrc, u32 nOffset, u32 nSize);
extern void  GXS_LoadBG0Char(const void *pSrc, u32 nOffset, u32 nSize);
extern void  GXS_LoadBG2Char(const void *pSrc, u32 nOffset, u32 nSize);
extern void  NNSi_FndFreeFromDefaultHeap(void *pBlock);
extern int   Ov025_GetCtxBlock954c(void);                             /* Ov008_GetCtxBlock954c */
extern void  Ov025_WithCharBlock_3(u32 nTag, Ov025CharLoader pfnLoad); /* Ov025_LoadCharBlock */
extern void *Ov025_FindEntryByTag(int nTracker, int nTag);           /* Ov008_TagTracker_FindCell */
extern void  Ov025_TagTracker_InvokeCallback(int nTracker, void *pCell);        /* Ov008_TagTracker_InvokeCallback */
extern void  Ov025_MarkSlotUsed(int nSlot);                        /* Ov008_MarkSlotUsed */

void Ov025_ScrollList_LoadSubScreen(void)
{
    void *pFile;
    int nTracker;
    Ov008ResourceCell cell;
    int bDefaultLanguage;

    bDefaultLanguage = func_02024e5c() == 1;
    if (bDefaultLanguage) {
        pFile = Archive_LoadFile(Ov025_PackSlotTag(0x14), 0xe);
    } else {
        pFile = Archive_LoadFile(Ov025_PackHandleTag(6), 0xe);
    }
    Res_LoadSpriteSet(&cell, pFile, 0, 0, 0);
    GXS_LoadBGPltt(cell.palette->data, 0, cell.palette->size);
    GXS_LoadBG3Char(cell.character->data, 0, cell.character->size);
    if (pFile != 0) {
        NNSi_FndFreeFromDefaultHeap(pFile);
    }
    nTracker = Ov025_GetCtxBlock954c();
    Ov025_WithCharBlock_3(Ov025_PackSlotTag(0x10), GXS_LoadBG0Char);
    Ov025_WithCharBlock_3(Ov025_PackSlotTag(0x11), GXS_LoadBG2Char);
    Ov025_TagTracker_InvokeCallback(nTracker, Ov025_FindEntryByTag(nTracker, 0xa));
    Ov025_TagTracker_InvokeCallback(nTracker, Ov025_FindEntryByTag(nTracker, 0xb));
    Ov025_MarkSlotUsed(0x19);
    Ov025_MarkSlotUsed(0x1a);
    Ov025_MarkSlotUsed(0x1b);
}
