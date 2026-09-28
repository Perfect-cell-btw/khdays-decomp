/* Ov025_LayoutScrollGauge -- Ov008_LayoutScrollGauge: place the scroll menu's
 * gauge widgets for knob position nPos.  The rail base comes from widget
 * 0x2d's block (+0 = x); the fourteen knob segments 0x30..0x3d sit at
 * y = nPos + 8 + 8 * i + 0x10 (fx32), the top cap 0x2d at nPos + 8 and the
 * bottom cap 0x2f at nPos + 8 + nGaugeScale - 0x10; every widget also gets the
 * menu's horizontal slide (-nSlideX, +0x38) applied as an offset sum.  The
 * knob offset (+0x48) records nPos.
 */
typedef unsigned char u8;

#define SEGMENT_FIRST 0x30
#define SEGMENT_LAST  0x3d
#define WIDGET_CAP_TOP    0x2d
#define WIDGET_CAP_BOTTOM 0x2f

typedef struct UiLayoutPos {
    int nX;
    int nY;
} UiLayoutPos;

typedef struct Ov008ScrollMenu {
    u8  pad_000[0x38];
    int nSlideX;              /* 0x038 */
    u8  pad_03c[0xc];
    int nKnobPos;             /* 0x048 */
    int nGaugeScale;          /* 0x04c */
} Ov008ScrollMenu;

extern int   Ov025_GetBlock4a80(void);                                  /* Ov008_GetCtxBlock4a80 */
extern void *Ov025_FindEntryById(int nCtx, int nId);                     /* FindEntryById */
extern int  *Ov025_GetEntryBlock2c(int nCtx, void *pEntry);                /* Ov008_GetEntryBlock2c */
extern void  Ov025_Widget_SetPoint(int nCtx, void *pEntry, UiLayoutPos *pPos); /* set the base position */
extern void  Ov025_ApplyOffsetSum(int nCtx, void *pEntry, UiLayoutPos *pPos); /* Ov008_ApplyOffsetSum */

void Ov025_LayoutScrollGauge(Ov008ScrollMenu *pMenu, int nPos)
{
    UiLayoutPos pos = { 0, 0 };
    int nCtx;
    int *pRail;
    void *pEntry;
    void *pCapTop;
    void *pCapBottom;
    int nId;
    int nTop;

    nCtx = Ov025_GetBlock4a80();
    pRail = Ov025_GetEntryBlock2c(nCtx, Ov025_FindEntryById(nCtx, WIDGET_CAP_TOP));
    nTop = nPos + 8;
    for (nId = SEGMENT_FIRST; nId <= SEGMENT_LAST; nId++) {
        pEntry = Ov025_FindEntryById(nCtx, nId);
        pos.nX = pRail[0];
        pos.nY = (nTop + (nId - SEGMENT_FIRST) * 8 + 0x10) << 12;
        Ov025_Widget_SetPoint(nCtx, pEntry, &pos);
        pos.nX = -pMenu->nSlideX << 12;
        pos.nY = 0;
        Ov025_ApplyOffsetSum(nCtx, pEntry, &pos);
    }
    pCapTop = Ov025_FindEntryById(nCtx, WIDGET_CAP_TOP);
    pCapBottom = Ov025_FindEntryById(nCtx, WIDGET_CAP_BOTTOM);
    pos.nX = pRail[0];
    pos.nY = nTop << 12;
    Ov025_Widget_SetPoint(nCtx, pCapTop, &pos);
    pos.nY = (nTop + pMenu->nGaugeScale - 0x10) << 12;
    Ov025_Widget_SetPoint(nCtx, pCapBottom, &pos);
    pos.nX = -pMenu->nSlideX << 12;
    pos.nY = 0;
    Ov025_ApplyOffsetSum(nCtx, pCapTop, &pos);
    Ov025_ApplyOffsetSum(nCtx, pCapBottom, &pos);
    pMenu->nKnobPos = nPos;
}
