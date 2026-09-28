/* Ov025_TickGridMenu -- Ov008_TickGridMenu: one frame of the grid menu.  Unless
 * the scene is paused: run the mode handler for the current mode (+4) from the
 * four-entry table (mode 0 has none), then the optional drag (+0x24), tween
 * (+0x28), scroll (+0x2c), secondary list (+0x19b4) and hold (+0x30) updates
 * and the button-3 state.  Always redraws the menu, masks the latched key word
 * (+0x2098) with the keys still held and marks the frame drawn (+0x3c).
 */
typedef unsigned char  u8;
typedef unsigned short u16;

#define MODE_COUNT 4

typedef struct Ov008MenuContext Ov008MenuContext;
typedef void (*Ov008ModeHandler)(Ov008MenuContext *pCtx);

typedef struct Ov008ModeHandlerTable {
    Ov008ModeHandler apfn[MODE_COUNT];
} Ov008ModeHandlerTable;

struct Ov008MenuContext {
    u8   pad_0000[4];
    int  nMode;               /* 0x0004 */
    u8   pad_0008[0x24 - 0x8];
    int  bDrag;               /* 0x0024 */
    int  bTween;              /* 0x0028 */
    int  bScroll;             /* 0x002c */
    int  bHold;               /* 0x0030 */
    u8   pad_0034[8];
    int  bFrameDrawn;         /* 0x003c */
    u8   pad_0040[0x19b4 - 0x40];
    int  bListUp;             /* 0x19b4 */
    u8   pad_19b8[0x2098 - 0x19b8];
    u16  nKeyLatch;           /* 0x2098 */
};

extern const Ov008ModeHandlerTable data_ov025_020b3cac;
extern u16 data_0204c18c;                                   /* held keys */

extern int  Ov025_IsContextMode4(void);                      /* scene paused */
extern void Ov025_UpdateKnobDrag(Ov008MenuContext *pCtx);    /* drag update */
extern void Ov025_UpdateGridDrag(Ov008MenuContext *pCtx);    /* tween update */
extern void Ov025_UpdateNodeDrag(Ov008MenuContext *pCtx);    /* scroll update */
extern void Ov025_LayoutSecondaryList(Ov008MenuContext *pCtx);    /* secondary list update */
extern void Ov025_GridMenuCancel(Ov008MenuContext *pCtx);    /* hold update */
extern void Ov025_UpdateButton3State(Ov008MenuContext *pCtx);    /* Ov008_UpdateButton3State */
extern void Ov025_DrawGridMenu(Ov008MenuContext *pCtx);    /* Ov008_DrawGridMenu */

void Ov025_TickGridMenu(Ov008MenuContext *pCtx)
{
    Ov008ModeHandlerTable handlers = data_ov025_020b3cac;

    if (Ov025_IsContextMode4() == 0) {
        if (handlers.apfn[pCtx->nMode] != 0) {
            handlers.apfn[pCtx->nMode](pCtx);
        }
        if (pCtx->bDrag != 0) {
            Ov025_UpdateKnobDrag(pCtx);
        }
        if (pCtx->bTween != 0) {
            Ov025_UpdateGridDrag(pCtx);
        }
        if (pCtx->bScroll != 0) {
            Ov025_UpdateNodeDrag(pCtx);
        }
        if (pCtx->bListUp != 0) {
            Ov025_LayoutSecondaryList(pCtx);
        }
        if (pCtx->bHold != 0) {
            Ov025_GridMenuCancel(pCtx);
        }
        Ov025_UpdateButton3State(pCtx);
    }
    Ov025_DrawGridMenu(pCtx);
    pCtx->nKeyLatch &= data_0204c18c;
    pCtx->bFrameDrawn = 1;
}
