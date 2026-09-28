/* Ov008_DrawTextRow -- Ov008_DrawTextRow: draw the text entries of row nRow
 * of a text-row screen (the caller keeps its variable records at +0x28c).  A 5 x 4 table of variable-record indices
 * (data_ov008_0208f378, -1 = end of row) is copied to the stack; the row's
 * first entry is drawn on the row's text surface (+0x160 + 0x3c * nRow) through
 * its base cell (Obj_GetWord18, stored in aCell[nRow][0] at +0x298), and each
 * further entry up to the first -1 gets its own cell (TileSurface_AddCanvas) in
 * aCell[nRow][i].  Every entry is drawn twice with Text_DrawDirectional: the
 * shadow (0x39, 7, 0xf2) and the face (0x38, 6, 0xf3), style 0x412.
 * NOTE: the surface address is spelled &pCtx->aSurface[nRow] at every use; a
 * local for it swaps the base / product registers.
 */
#include "nitro/types.h"

#define ROW_ENTRIES   4
#define TEXT_STYLE    0x412
#define ENTRY_END     -1

typedef struct TextSurface {
    u8 pad[0x3c];
} TextSurface;

typedef struct Ov008TextRows {
    u8          pad_000[0x160];
    TextSurface aSurface[5];              /* 0x160 */
    u8          pad_28c[0x298 - 0x28c];
    void       *aCell[5][ROW_ENTRIES];    /* 0x298 */
} Ov008TextRows;

typedef struct Ov008TextRowTable {
    int aIndex[5][ROW_ENTRIES];
} Ov008TextRowTable;

extern const Ov008TextRowTable data_ov008_0208f378;
extern void *Ov008_GetVarRecordByIndex(void *pRecords, int nIndex);           /* GetVarRecordByIndex */
extern void *Obj_GetWord18(TextSurface *pSurface);                      /* base cell */
extern void *TileSurface_AddCanvas(TextSurface *pSurface, int nKind);           /* new cell */
extern void  Text_DrawDirectional_2(TextSurface *pSurface, int nX, int nY, int nColour, unsigned int nStyle, void *pText); /* Text_DrawDirectional */

void Ov008_DrawTextRow(Ov008TextRows *pCtx, void *pRecords, int nRow)
{
    Ov008TextRowTable table;
    void *pText;
    int i;

    table = data_ov008_0208f378;
    pText = Ov008_GetVarRecordByIndex(pRecords, table.aIndex[nRow][0]);
    pCtx->aCell[nRow][0] = Obj_GetWord18(&pCtx->aSurface[nRow]);
    Text_DrawDirectional_2(&pCtx->aSurface[nRow], 0x39, 7, 0xf2, TEXT_STYLE, pText);
    Text_DrawDirectional_2(&pCtx->aSurface[nRow], 0x38, 6, 0xf3, TEXT_STYLE, pText);
    for (i = 1; i < ROW_ENTRIES; i++) {
        if (table.aIndex[nRow][i] == ENTRY_END) {
            return;
        }
        pText = Ov008_GetVarRecordByIndex(pRecords, table.aIndex[nRow][i]);
        pCtx->aCell[nRow][i] = TileSurface_AddCanvas(&pCtx->aSurface[nRow], 1);
        Text_DrawDirectional_2(&pCtx->aSurface[nRow], 0x39, 7, 0xf2, TEXT_STYLE, pText);
        Text_DrawDirectional_2(&pCtx->aSurface[nRow], 0x38, 6, 0xf3, TEXT_STYLE, pText);
    }
}
