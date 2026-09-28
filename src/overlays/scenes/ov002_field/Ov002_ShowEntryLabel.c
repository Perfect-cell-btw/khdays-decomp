/*
 * Ov002_ShowEntryLabel - put the label cell that belongs to an entry id on the
 * panel's text surface.
 *
 * The mode the cell is shown in says whether the panel is between its first
 * and eighth state, which is the stretch where the labels are live; anything
 * outside that range shows it in mode 1 instead.
 *
 * The entry id table is walked in order and stops at the first negative id, so
 * an id that is not listed - or a table that ends before it - falls through to
 * the spare cell the teardown selects.
 *
 * ARM.
 */

typedef struct {
    char pad0000[0x6c];
    int aTextSurface[1];                /* +0x06c sTextSurface */
    char pad0070[0x38];
    void *apLabelCells[5];              /* +0x0a8 */
    char pad00bc[0xc4];
    short *pEntryIds;                   /* +0x180 */
    char pad0184[8];
    int nPanelState;                    /* +0x18c */
} Ov002PanelContext;

extern Ov002PanelContext *data_ov002_0207f614;

extern void TileSurface_SetCurrentItem(int *pSurface, void *pCell, int nMode);
extern void Ov002_RestartRequestQueue(int a, int b);

void Ov002_ShowEntryLabel(int a, int b, int nId, int bRestart)
{
    Ov002PanelContext *ctx;
    int nMode;
    int i;
    short *pIds;

    ctx = data_ov002_0207f614;
    nMode = (ctx->nPanelState < 1 || ctx->nPanelState > 8) ? 1 : 0;
    if (bRestart != 0) {
        Ov002_RestartRequestQueue(a, b);
    }

    pIds = ctx->pEntryIds;
    i = 0;
    do {
        if (pIds[i] < 0) {
            break;
        }
        if (nId == pIds[i]) {
            TileSurface_SetCurrentItem(ctx->aTextSurface, ctx->apLabelCells[i], nMode);
            return;
        }
        i++;
    } while (i < 4);

    TileSurface_SetCurrentItem(ctx->aTextSurface, ctx->apLabelCells[4], nMode);
}
