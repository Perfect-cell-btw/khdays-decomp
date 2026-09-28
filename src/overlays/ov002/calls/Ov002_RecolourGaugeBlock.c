/*
 * Ov002_RecolourGaugeBlock - repaint the gauge's eight-by-eight block of screen
 * entries with the palettes a layout table gives.
 *
 * Only the palette survives from the table: each entry keeps the tile it already
 * names and takes the top four bits of the matching halfword instead. The block
 * starts nine rows down the 32-entry-wide screen and four entries in.
 *
 * When the page still has somewhere to go the sub-display is told about it, and
 * the item is selected once at the end either way.
 *
 * ARM.
 */

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct NNSG2dScreenData {
    u16 screenWidth;
    u16 screenHeight;
    u16 colorMode;
    u16 screenFormat;
    u32 szByte;
    u32 rawData[1];
} NNSG2dScreenData;

extern u16 *Ov002_GetItemResource(int nItemId);
extern void Ov002_SelectEntry(int nItemId);
extern int Ov002_Field_GetWordAC(void);
extern int Ov002_ForwardToSubDc(int nId);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int nHandle);

void Ov002_RecolourGaugeBlock(const NNSG2dScreenData *pMap)
{
    u16 *pScreen;
    int nRow;
    int nCol;
    int nBase;
    u16 nPal;
    u16 *pRow;

    pScreen = Ov002_GetItemResource(0x1a);
    for (nRow = 0, nBase = 0; nRow < 8; nRow++) {
        pRow = pScreen + (nRow + 9) * 0x20;
        for (nCol = 0; nCol < 8; nCol++) {
            nPal = (((const u16 *)pMap->rawData)[nBase + nCol] >> 12) & 0xf;
            pRow[4] = (u16)((nPal << 12) | (pRow[4] & 0xfff));
            pRow++;
        }
        nBase += 8;
    }

    if (Ov002_Field_GetWordAC() >= 0) {
        Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x419));
    }
    Ov002_SelectEntry(0x1a);
}
