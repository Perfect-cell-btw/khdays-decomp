/*
 * Ov002_DrawPageGauge - fill the eight-column gauge and send it.
 *
 * Columns up to the count given are drawn in the filled style, the rest in the
 * empty one, and the finished buffer is handed to the graphics queue once.
 *
 * ARM.
 */

#include "nitro/types.h"

typedef struct {
    char pad000[8];
    u8 *pGauge;
} Ov002PageContext;

extern Ov002PageContext *data_ov002_0207f634;

extern void GFXi_EnqueueCommand(int nCmd, int nDest, int nSrc, int nSize);
extern void Ov002_DrawGaugeColumn(u8 *pBuffer, int nColumn, int nStyle);

void Ov002_DrawPageGauge(int nFilled)
{
    Ov002PageContext *ctx;
    int i;

    ctx = data_ov002_0207f634;
    for (i = 0; i < nFilled; i++) {
        Ov002_DrawGaugeColumn(ctx->pGauge, i, 0);
    }
    for (; i < 8; i++) {
        Ov002_DrawGaugeColumn(ctx->pGauge, i, 1);
    }
    GFXi_EnqueueCommand(0x16, 0xde0, (int)ctx->pGauge, 0x20);
}
