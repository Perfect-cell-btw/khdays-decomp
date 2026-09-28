/*
 * Ov002_ShowPageSpread - put the whole page spread on screen.
 *
 * With nothing loaded the object is just released. Otherwise the three parts of
 * the object are opened - the palette, the character data and the tile map -
 * the map is uploaded, and the other two are handed to the graphics queue.
 *
 * The row of seven marks that goes underneath is built last: a mark is lit
 * where the flag word has its bit and blank where it does not.
 *
 * THUMB.
 */

typedef unsigned short u16;

typedef struct {
    char pad000[0xc];
    int nPalette;
} Ov002PagePart;

typedef struct {
    char pad000[0x10];
    int nCharBase;
    int nCharSize;
} Ov002PageChars;

extern int data_ov002_0207f638;

extern void *NNS_FndAllocFromDefaultExpHeapEx(int nSize, int nAlign);
extern void GFXi_EnqueueCommand(int nCmd, int nDest, int nSrc, int nSize);
extern void GetResourceSubBlock_CHAR(int hPart, void *pOut);
extern void NNS_G2dGetUnpackedPaletteData(int hPart, void *pOut);
extern void NNS_G2dGetUnpackedScreenData(int hPart, void *pOut);
extern void Obj_RelocateSections(int hObj, int nMode);
extern int Archive_GetMember(int hObj, int nPart, int nFlags);

extern int Ov002_GetWord8(int pObj);
extern void Ov002_DestroyOwnedEntry(int pObj, int nMode);
extern void Ov002_EnqueueAndRecordCommand(int a, int b, int c, int d, int e);
extern int Ov002_Field_GetHalf88(void);
extern void Ov002_RecolourGaugeBlock(u16 *pMap);

void Ov002_ShowPageSpread(int pObj)
{
    Ov002PagePart *pPal;
    Ov002PageChars *pChars;
    u16 *pMap;
    int hObj;
    int nMask;
    u16 *pBuf;
    int i;
    int nEntry;

    if (data_ov002_0207f638 == 0) {
        Ov002_DestroyOwnedEntry(pObj, 1);
        return;
    }

    hObj = Ov002_GetWord8(pObj);
    Obj_RelocateSections(hObj, 1);
    NNS_G2dGetUnpackedPaletteData(Archive_GetMember(hObj, 0, 0), &pPal);
    GetResourceSubBlock_CHAR(Archive_GetMember(hObj, 1, 0), &pChars);
    NNS_G2dGetUnpackedScreenData(Archive_GetMember(hObj, 6, 0), &pMap);

    Ov002_RecolourGaugeBlock(pMap);
    GFXi_EnqueueCommand(0x1f, 0, pPal->nPalette, 0x140);
    Ov002_EnqueueAndRecordCommand(0x16, 0x1f20, pChars->nCharSize, pChars->nCharBase,
                        hObj);
    Ov002_DestroyOwnedEntry(pObj, 0);

    nMask = Ov002_Field_GetHalf88();
    pBuf = (u16 *)NNS_FndAllocFromDefaultExpHeapEx(0x10, 4);
    pBuf[0] = 0;
    for (i = 0; i < 7; i++) {
        if ((nMask & (1 << i)) != 0) {
            nEntry = 0x1d;
        } else {
            nEntry = 0x14a5;
        }
        pBuf[i + 1] = (u16)nEntry;
    }
    Ov002_EnqueueAndRecordCommand(0x1f, 0x160, (int)pBuf, 0x10, 0);
}
