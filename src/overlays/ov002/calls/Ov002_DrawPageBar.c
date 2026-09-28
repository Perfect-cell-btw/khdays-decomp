/*
 * Ov002_DrawPageBar - fill the eight-column bar, mark one column, and send it.
 *
 * Columns up to the count given are drawn in the filled style and the rest in
 * the empty one, exactly like the gauge above it; the marked column is then
 * overwritten in the third style, so it wins wherever it lands.
 *
 * ARM.
 */

typedef unsigned char u8;

typedef struct {
    char pad000[0xc];
    u8 *pBar;
} Ov002PageContext;

extern Ov002PageContext *data_ov002_0207f634;

extern void GFXi_EnqueueCommand(int nCmd, int nDest, int nSrc, int nSize);
extern void Ov002_DrawGaugeColumn(u8 *pBuffer, int nColumn, int nStyle);

void Ov002_DrawPageBar(int nFilled, int nMark)
{
    Ov002PageContext *ctx;
    int i;

    ctx = data_ov002_0207f634;
    for (i = 0; i < nFilled; i++) {
        Ov002_DrawGaugeColumn(ctx->pBar, i, 0);
    }
    for (; i < 8; i++) {
        Ov002_DrawGaugeColumn(ctx->pBar, i, 1);
    }
    Ov002_DrawGaugeColumn(ctx->pBar, nMark, 2);
    GFXi_EnqueueCommand(0x16, 0xda0, (int)ctx->pBar, 0x20);
}
