/* Ov008_UpdateGridDrag -- Ov008_UpdateGridDrag: one step of dragging a node with
 * the stylus.  While the pen is down the drag position (+0x60/+0x62) follows the
 * touch and widget 3 is moved there (fx32).  On release the position is mapped
 * to a grid cell: no cell -> the grid is reset (cue 0x37); a cell -> it becomes
 * the cursor cell (+0x64/+0x66) and the drop is attempted (cue 0x36, or 4 when
 * refused).  Either way mode 2 is entered, menu button 5 refreshed and the drag
 * flag (+0x28) cleared.
 */
typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct UiLayoutPos {
    int nX;
    int nY;
} UiLayoutPos;

typedef struct Ov008TouchRecord {
    u16 nX;                   /* 0x00 */
    u16 nY;                   /* 0x02 */
    u16 nTouching;            /* 0x04 */
} Ov008TouchRecord;

typedef struct Ov008MenuContext {
    u8  pad_0000[0x28];
    int bDrag;                /* 0x0028 */
    u8  pad_002c[0x60 - 0x2c];
    u16 nDragX;               /* 0x0060 */
    u16 nDragY;               /* 0x0062 */
    u16 nColumn;              /* 0x0064 */
    u16 nRowSel;              /* 0x0066 */
} Ov008MenuContext;

#define WIDGET_DRAG 3
#define SOUND_DROP_OK   0x36
#define SOUND_DROP_NONE 0x37
#define SOUND_REFUSED   4

extern void Ov008_CopySourceBlock(void *pOut);                              /* touch record */
extern int  Ov008_GetContext(void);                                    /* Ov008_GetContext */
extern void *Ov008_FindEntryById(int nCtx, int nId);                      /* FindEntryById */
extern void Ov008_SetEntryPos(int nCtx, void *pEntry, UiLayoutPos *pPos); /* Ov008_SetEntryPos */
extern int  Ov008_PixelToTileCell(u16 *pCol, u16 *pRow, u16 nX, u16 nY);    /* Ov008_PixelToTileCell */
extern int  Ov008_PlaceDraggedNode(Ov008MenuContext *pCtx, int nArg);        /* drop the dragged node */
extern void PlaySound(int nKind, int nSound);                         /* PlaySound */
extern void Ov008_ResetGridDrag(Ov008MenuContext *pCtx, int nArg);        /* grid reset */
extern void Ov008_EnterMenuState(Ov008MenuContext *pCtx, int nMode);
extern void Ov008_UpdateMenuButton5(int nArg);                                /* Ov008_UpdateMenuButton5 */

void Ov008_UpdateGridDrag(Ov008MenuContext *pCtx)
{
    u16 nCol;
    u16 nRow;
    Ov008TouchRecord touch;
    UiLayoutPos pos = { 0, 0 };
    int nCtx;

    Ov008_CopySourceBlock(&touch);
    nCtx = Ov008_GetContext();
    if (touch.nTouching != 0) {
        pos.nX = touch.nX << 12;
        pos.nY = touch.nY << 12;
        pCtx->nDragX = touch.nX;
        pCtx->nDragY = touch.nY;
        Ov008_SetEntryPos(nCtx, Ov008_FindEntryById(nCtx, WIDGET_DRAG), &pos);
        return;
    }
    if (Ov008_PixelToTileCell(&nCol, &nRow, pCtx->nDragX, pCtx->nDragY) != 0) {
        pCtx->nColumn = nCol;
        pCtx->nRowSel = nRow;
        if (Ov008_PlaceDraggedNode(pCtx, 0) != 0) {
            PlaySound(0, SOUND_DROP_OK);
        } else {
            PlaySound(0, SOUND_REFUSED);
        }
    } else {
        Ov008_ResetGridDrag(pCtx, 0);
        PlaySound(0, SOUND_DROP_NONE);
    }
    Ov008_EnterMenuState(pCtx, 2);
    Ov008_UpdateMenuButton5(1);
    pCtx->bDrag = 0;
}
