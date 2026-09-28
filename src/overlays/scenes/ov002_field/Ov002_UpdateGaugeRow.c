/* Selects the gauge-row style from row parity and fill state, creates or reuses the row-pair
 * tracker handle, applies its metrics and invokes the tracker callback; the final/odd row flushes
 * pending state. */

typedef unsigned short u16;

typedef enum {
    FALSE = 0,
    TRUE = 1
} BOOL;

typedef struct {
    short nOrigin;
    short nRowLimit;
    short nColour;
} Ov002RowStyle;

typedef struct {
    unsigned char pad0000[0x3c];
    int nVisibleRows;
    unsigned char pad0040[0x124];
    Ov002RowStyle *aRowStyles[5];
} Ov002GaugeLayoutContext;

extern Ov002GaugeLayoutContext *data_ov002_0207f618;
extern BOOL data_ov002_0207e988;

extern int Ov002_PositionSubDcHandle(Ov002RowStyle *pStyle, u16 nRow, int nKind);
extern int Ov002_Ctx_SetTagTrackerNodeArmed(int nHandle, Ov002RowStyle *pStyle);
extern int Ov002_ForwardToSubDc(u16 nRow);
extern int Ov002_PositionSubDcHandle_2(int nHandle, short nOffset, short nColour);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int nHandle);

void Ov002_UpdateGaugeRow(int nRow, BOOL bFilled, BOOL bLast)
{
    int nParity = nRow % 2;
    Ov002GaugeLayoutContext *pContext = data_ov002_0207f618;
    int nHandle;
    int nHalfRow;
    u16 nEncodedRow;

    if (nParity == 1) {
        if (data_ov002_0207e988 != 3) {
            if (data_ov002_0207e988 == 4) {
                data_ov002_0207e988 = 2;
            }
        } else {
            data_ov002_0207e988 = bFilled ? FALSE : TRUE;
        }
    } else {
        data_ov002_0207e988 = bFilled != 0 ? 3 : 4;
    }

    if (bLast == 0 && nParity != 1) {
        return;
    }

    nHalfRow = nRow / 2;
    nEncodedRow = (u16)(nHalfRow + 50000);
    if (pContext->nVisibleRows > 0 &&
        nHalfRow <= pContext->nVisibleRows / 2) {
        nHandle = Ov002_ForwardToSubDc(nEncodedRow);
        Ov002_Ctx_SetTagTrackerNodeArmed(nHandle,
                            pContext->aRowStyles[data_ov002_0207e988]);
    } else {
        short nLimit = pContext->aRowStyles[0]->nRowLimit;
        nHandle = Ov002_PositionSubDcHandle(
            pContext->aRowStyles[data_ov002_0207e988], nEncodedRow, 0xb);
        Ov002_PositionSubDcHandle_2(nHandle, (short)(nLimit - nHalfRow),
                            pContext->aRowStyles[0]->nColour);
    }
    Ov002_Ctx_InvokeTagTrackerCallback(nHandle);
    data_ov002_0207e988 = -1;
}
