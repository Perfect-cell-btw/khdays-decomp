/* Ov026_ShowTierPage -- Ov008_ShowTierPage: store the tier's two message ids in
 * the panel context, show the cell tagged nCellTag in the secondary tag tracker
 * (+0x5c) and the cell tagged nFrameTag in the primary one (+0x10), then show
 * the eight cells tagged nFirstTag..nFirstTag+7 in the primary tracker with their
 * tile palette set to nPalette.  Called for tiers 1..3 by 020850c0.
 */
typedef unsigned char  u8;
typedef unsigned short u16;

#define REWARD_CELL_COUNT 8

typedef struct Ov008PanelContext {
    u8 pad_0000[0x10];
    u8 primaryTracker[0x5c - 0x10];   /* 0x0010 */
    u8 secondaryTracker[1];           /* 0x005c */
    u8 pad_005d[0xc3b8 - 0x5d];
    int aTierMessage[2];            /* 0xc3b8 */
} Ov008PanelContext;

extern Ov008PanelContext *data_ov026_02091368;
extern int Ov026_FindEntryByTag(void *pTracker, u16 nTag);            /* ov008_FindEntryByTag */
extern void Ov026_TagTracker_InvokeCallback(void *pTracker, int nCell);           /* Ov008_TagTracker_InvokeCallback */
extern void Ov026_FillTilemapRegionPalette(void *pTracker, int nCell, u8 nMode);  /* Ov008_StampTileMode */

void Ov026_ShowTierPage(int nTitleMsg, int nBodyMsg, int nCellTag, int nFrameTag, int nFirstTag, int nPalette)
{
    Ov008PanelContext *pCtx;
    int nCell;
    int i;

    pCtx = data_ov026_02091368;
    {
        /* through a pointer: the ROM forms ctx+0x3b8+0xc000 once and stores [1] at +4 */
        int *pMessage = pCtx->aTierMessage;
        pMessage[0] = nTitleMsg;
        pMessage[1] = nBodyMsg;
    }
    nCell = Ov026_FindEntryByTag(pCtx->secondaryTracker, nCellTag);
    Ov026_TagTracker_InvokeCallback(pCtx->secondaryTracker, nCell);
    nCell = Ov026_FindEntryByTag(pCtx->primaryTracker, nFrameTag);
    Ov026_TagTracker_InvokeCallback(pCtx->primaryTracker, nCell);
    for (i = 0; i < REWARD_CELL_COUNT; i++) {
        nCell = Ov026_FindEntryByTag(pCtx->primaryTracker, nFirstTag + i);
        Ov026_FillTilemapRegionPalette(pCtx->primaryTracker, nCell, nPalette);
        Ov026_TagTracker_InvokeCallback(pCtx->primaryTracker, nCell);
    }
}
