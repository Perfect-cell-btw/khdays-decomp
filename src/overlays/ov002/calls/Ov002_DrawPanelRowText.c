/*
 * Ov002_DrawPanelRowText - write the text of all eight panel rows into the
 * five 0x3c-byte surfaces the caller hands over.
 *
 * Each row is classified first, and the class decides what is written. Class 0
 * is the fixed six-line block: the first line follows the mission-clear check,
 * the next two read the word at +0x24 of the session walked four bytes at a
 * time, and the last three are numbered from the line index. Class 1 walks six
 * cells of the row and writes the ones that are not 0xff, in the left or right
 * column depending on whether the row is the first. Classes 2 and 3 share a
 * body - class 3 just looks two rows further on - and write six named entries,
 * falling back to the spare string when the lookup finds nothing.
 *
 * The font goes into the block at +0x110 afterwards, and the last surface gets
 * its three fixed lines.
 *
 * THUMB.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0000[0x24];
    int nField0024;                     /* +0x024 */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;
extern char data_ov002_0207eadc[];
extern char data_ov002_0207eaf4[];
extern int data_ov002_0207eb08[];
extern int data_ov002_0207eb0c[];

extern void Resource_BindByName(void *pField, const void *pTable);
extern void FreeFieldAt8(void *pField);
extern void Text_DrawWithShadow(void *pSurface, int a, int b, int c, void *pText,
                          int d);
extern int Ov002_Hud_GetBlock24(void);
extern int Ov002_GetPanelField0058(void);
extern void Ov002_InitResourceRecord(void *pSet, const void *pTable);
extern void Ov002_FreeResourceRecordBuffer(void *pSet);
extern int *Ov002_GetVarRecordByIndex(void *pSet, int nIndex);
extern int Ov002_ClassifyCode(int *pOut, int nIndex);
extern void Ov002_PickTextFitting64(void *pSurface, int nFont, void *pBind,
                                int *pText);
extern int *Ov002_FindNamedEntry(int nName);

void Ov002_DrawPanelRowText(char *pDst)
{
    Ov002PanelSession *s;
    Ov002PanelSession *pWalk;
    int *pText;
    int nIndex;
    int nFont;
    int nRow;
    int nCode;
    int nClass;
    int nSelect;
    int nColumn;
    int i;
    int nY;
    int nX;
    u16 nName;
    int aRecords[3];
    int aBind[3];

    s = data_ov002_0207f620;
    Resource_BindByName(aBind, data_ov002_0207eadc);
    nFont = Ov002_Hud_GetBlock24();
    Ov002_InitResourceRecord(aRecords, data_ov002_0207eaf4);

    /* The y cursor is claimed here rather than in the class-2 body: with its
       live range starting before the switch, mwcc gives it the same register
       the ROM does and the whole block's allocation falls into place. */
    nY = 0;
    nIndex = 0;
    nRow = 0;
    do {
        nClass = Ov002_ClassifyCode(&nCode, nIndex);
        switch (nClass) {
        case 0:
            pWalk = s;
            i = 0;
            do {
                switch (i) {
                case 0:
                    if (Ov002_GetPanelField0058() != 0) {
                        nSelect = 7;
                    } else {
                        nSelect = 0;
                    }
                    break;
                case 1:
                case 2:
                    nSelect = pWalk->nField0024 + 5;
                    break;
                case 3:
                case 4:
                case 5:
                    nSelect = i - 2;
                    break;
                }
                pText = Ov002_GetVarRecordByIndex(aRecords, nSelect);
                Ov002_PickTextFitting64(pDst, nFont, aBind, pText);
                Text_DrawWithShadow(pDst, 0, (nRow + i * 2) * 8 + 3, 2, pText, 1);
                pWalk = (Ov002PanelSession *)((char *)pWalk + 4);
                i++;
            } while (i < 6);
            break;

        case 1:
            if (nCode < 1) {
                nColumn = 0;
                nY = 0x60;
            } else {
                nColumn = 1;
                nY = (nCode - 1) * 0x60;
            }
            nX = nColumn * 0x3c;
            i = 0;
            do {
                if (i + nCode * 6 < 0xf
                    && *((u8 *)s + (i + nCode * 6) * 2 + 0x32) != 0xff) {
                    pText = Ov002_GetVarRecordByIndex((char *)s + 0x5e8,
                                                *((u8 *)s + (i + nCode * 6) * 2 + 0x32));
                    Ov002_PickTextFitting64(pDst + nX, nFont, aBind, pText);
                    Text_DrawWithShadow(pDst + nX, 0, nY + 3, 2, pText, 1);
                }
                i++;
                nY += 0x10;
            } while (i < 6);
            break;

        case 2:
        case 3:
            if (nClass == 3) {
                nCode += 2;
            }
            if (nCode < 2) {
                nColumn = 2;
            } else {
                nColumn = 3;
            }
            nY = nCode % 2 * 0x60;
            nX = nColumn * 0x3c;
            i = 0;
            do {
                nName = *(u16 *)((char *)s + (i + nCode * 6) * 0xc + 0x4b8);
                if (nName != 0) {
                    pText = Ov002_FindNamedEntry((short)nName);
                    Ov002_PickTextFitting64(pDst + nX, nFont, aBind, pText);
                    if (pText == 0) {
                        pText = data_ov002_0207eb08;
                    }
                    Text_DrawWithShadow(pDst + nX, 0, nY + 3, 2, pText, 1);
                }
                i++;
                nY += 0x10;
            } while (i < 6);
            break;
        }
        nRow += 0xc;
        nIndex++;
    } while (nIndex <= 7);

    *(int *)(pDst + 0x110) = nFont;
    Text_DrawWithShadow(pDst + 0xf0, 0, 3, 2, data_ov002_0207eb0c, 1);
    Text_DrawWithShadow(pDst + 0xf0, 0, 0x13, 2, Ov002_GetVarRecordByIndex(aRecords, 4), 1);
    Text_DrawWithShadow(pDst + 0xf0, 0, 0x23, 2, Ov002_GetVarRecordByIndex(aRecords, 5), 1);
    Ov002_FreeResourceRecordBuffer(aRecords);
    FreeFieldAt8(aBind);
}
