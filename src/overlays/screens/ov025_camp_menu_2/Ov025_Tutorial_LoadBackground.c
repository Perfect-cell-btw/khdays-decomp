/* Ov025_Tutorial_LoadBackground -- Ov025_Tutorial_LoadBackground: load the tutorial page's background.
 * Archive member 0x43 (Ov008_PackSlotTag 02084d18; 0201ef9c, heap 0xe) gives the palette /
 * character / screen cell (Res_LoadSpriteSet 02024c94): the palette goes to the BG palette RAM
 * (GX_LoadBGPltt); the characters come from the localised sub-file 1 when there is one
 * (02084d50: its CHAR block 020119d4 is flushed from the cache and sent to BG3), else from the
 * member's own character block (GX_LoadBG3Char); the files are freed again. */

#include "nitro/types.h"

typedef struct Ov008CharacterBlock { u8 pad_0000[0x10]; u32 size; void *data; } Ov008CharacterBlock;

typedef struct Ov008PaletteBlock   { u8 pad_0000[0x08]; u32 size; void *data; } Ov008PaletteBlock;

typedef struct Ov008ScreenBlock    { u8 pad_0000[0x08]; u32 size; u8 data[1]; } Ov008ScreenBlock;

typedef struct Ov008ResourceCell {
    Ov008ScreenBlock    *screen;
    Ov008CharacterBlock *character;
    Ov008PaletteBlock   *palette;
} Ov008ResourceCell;

extern void *Ov025_GetPageA(void);                             /* Ov008_GetPageA */
extern u32   Ov025_PackSlotTag(int nMember);                      /* Ov008_PackSlotTag */
extern u32   Ov025_PackHandleTag(int nSubFile);                     /* Ov008_PackLocalisedTag */
extern void *Archive_LoadFile(u32 nTag, int nHeap);                    /* Res_Open */
extern void  Res_LoadSpriteSet(Ov008ResourceCell *pCell, void *pFile, int nScreen, int nChar, int nPalette); /* Res_LoadSpriteSet */
extern void  GetResourceSubBlock_CHAR2(void *pFile, Ov008CharacterBlock **ppBlock); /* GetResourceSubBlock_CHAR2 */
extern void  DC_FlushRange(const void *pAddress, u32 nSize);
extern void  GX_LoadBGPltt(const void *pSource, u32 nOffset, u32 nSize);
extern void  GX_LoadBG3Char(const void *pSource, u32 nOffset, u32 nSize);
extern void  NNSi_FndFreeFromDefaultHeap(void *pBlock);

void Ov025_Tutorial_LoadBackground(void)
{
    void *pFile;
    void *pCharFile;
    u32  nTag;
    Ov008CharacterBlock *pChar;
    Ov008ResourceCell cell;

    Ov025_GetPageA();
    pFile = Archive_LoadFile(Ov025_PackSlotTag(0x43), 0xe);
    Res_LoadSpriteSet(&cell, pFile, 0, 0, 0);
    GX_LoadBGPltt(cell.palette->data, 0, cell.palette->size);
    nTag = Ov025_PackHandleTag(1);
    if (nTag != 0) {
        pCharFile = Archive_LoadFile(nTag, 0xe);
        GetResourceSubBlock_CHAR2(pCharFile, &pChar);
        DC_FlushRange(pChar->data, pChar->size);
        GX_LoadBG3Char(pChar->data, 0, pChar->size);
        if (pCharFile != 0) {
            NNSi_FndFreeFromDefaultHeap(pCharFile);
        }
    } else {
        GX_LoadBG3Char(cell.character->data, 0, cell.character->size);
    }
    if (pFile != 0) {
        NNSi_FndFreeFromDefaultHeap(pFile);
    }
}
