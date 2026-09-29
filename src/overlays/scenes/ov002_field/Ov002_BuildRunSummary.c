/*
 * Ov002_BuildRunSummary - build the mission summary line and put it on screen.
 *
 * Every part of the run that has something to report adds its own message to a
 * 512-byte buffer, in a fixed order: the time taken, split into minutes and
 * seconds; the combo count; the three bonus flags; the three tallies; and the
 * two closing counts. From the second entry onwards each message is asked to
 * open with the separator, which is what the running flag carries.
 *
 * The finished line is drawn into the summary surface and its width is handed
 * back to the row that owns it.
 *
 * ARM.
 */

#include "nitro/types.h"

typedef struct {
    char pad000[0x10];
    char textCtx[0x44];
    int nStyle;
} Ov002TextScene;

typedef struct {
    u16 nSeconds;
    u16 nCombo;
    u16 wBonus;
    u8 nTallyA;
    u8 nTallyB;
    u8 nTallyC;
    char pad009[1];
    u16 nExtraA;
    u16 nExtraB;
} Ov002RunStats;

extern int data_ov002_0207f62c;
extern Ov002RunStats data_0204c254;

extern void TileSurface_SetCurrentItem(void *pCtx, int nStyle, int nFlags);
extern void Text_DrawWithShadow(void *pCtx, int a, int b, int c, void *pText, int d);
extern int TextWindow_GetTextWidth(void *pCtx, void *pText);

extern void Ov002_EmitMessageLine(void *pSink, unsigned int nId, int bOpen,
                                int nArg, ...);
extern void Ov002_AppendOptionEntries(void *pSink, unsigned int nId, int bOpen,
                                int nArg);
extern void Ov002_SetRowValue(int nRow, int nWidth);

void Ov002_BuildRunSummary(void)
{
    Ov002TextScene *s = *(Ov002TextScene **)((char *)&data_ov002_0207f62c + 4);
    short aText[0x100] = { 0 };
    int nSeconds = data_0204c254.nSeconds;
    int nMinutes = nSeconds / 60;
    int nRemain = nSeconds % 60;
    int bMore = 0;

    if (nMinutes > 0) {
        Ov002_EmitMessageLine(aText, 2, 0, 0x100, nMinutes);
        bMore = 1;
    }
    if (nRemain > 0) {
        Ov002_EmitMessageLine(aText, 3, 0, 0x100, nRemain);
        bMore = 1;
    }
    if (bMore != 0) {
        Ov002_AppendOptionEntries(aText, 4, 0, 0x100);
    }

    if (data_0204c254.nCombo != 0) {
        Ov002_EmitMessageLine(aText, 5, bMore, 0x100, data_0204c254.nCombo);
        bMore = 1;
    }
    if ((data_0204c254.wBonus & 1) != 0) {
        Ov002_AppendOptionEntries(aText, 6, bMore, 0x100);
        bMore = 1;
    }
    if ((data_0204c254.wBonus & 2) != 0) {
        Ov002_AppendOptionEntries(aText, 7, bMore, 0x100);
        bMore = 1;
    }
    if ((data_0204c254.wBonus & 4) != 0) {
        Ov002_AppendOptionEntries(aText, 8, bMore, 0x100);
        bMore = 1;
    }
    if (data_0204c254.nTallyA != 0) {
        Ov002_EmitMessageLine(aText, 9, bMore, 0x100, data_0204c254.nTallyA);
        bMore = 1;
    }
    if (data_0204c254.nTallyB != 0) {
        Ov002_EmitMessageLine(aText, 0xa, bMore, 0x100, data_0204c254.nTallyB);
        bMore = 1;
    }
    if (data_0204c254.nTallyC != 0) {
        Ov002_EmitMessageLine(aText, 0xb, bMore, 0x100, data_0204c254.nTallyC);
        bMore = 1;
    }
    if (data_0204c254.nExtraA != 0) {
        Ov002_AppendOptionEntries(aText, 0xc, bMore, 0x100);
        bMore = 1;
    }
    if (data_0204c254.nExtraB != 0) {
        Ov002_EmitMessageLine(aText, 0xd, bMore, 0x100);
    }

    TileSurface_SetCurrentItem(s->textCtx, s->nStyle, 0);
    Text_DrawWithShadow(s->textCtx, 8, 3, 0xc, aText, 0);
    Ov002_SetRowValue(1, TextWindow_GetTextWidth(s->textCtx, aText));
    TileSurface_SetCurrentItem(s->textCtx, 0, 0);
}
