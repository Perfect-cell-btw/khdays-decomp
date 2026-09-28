/* Recompute the scrollbar thumb position at +0x182.
 *
 * A positive total latches into +0x184 and the position is clamped to it. With
 * the prompt mode word at +0x17c clear the thumb tracks the whole list, and the
 * last row is nudged back one so a full list does not divide by itself. With it
 * set the thumb tracks the window instead, measuring from the top while the
 * position is inside it and from the bottom once past it.
 *
 * Both halfwords are read twice rather than cached, the same way
 * Ov002_OpenConfirmPrompt reads the row height.
 */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0000[0x3a];
    u16 wRowHeight;             /* +0x3a */
    u8 pad003c[0x140];
    int nMode17c;               /* +0x17c */
    u16 wScrollTop;             /* +0x180 */
    u16 wScrollThumb;           /* +0x182 */
    int nTotal;                 /* +0x184 */
} Ov002SceneContext;

extern Ov002SceneContext *data_ov002_0207f618;

extern int FX_Div(int nNumerator, int nDenominator);

void Ov002_UpdateScrollThumb(int nPos, int nTotal, int nWindow) {
    Ov002SceneContext *ctx = data_ov002_0207f618;
    int nMax;
    int nFx;
    int nRest;

    if (nTotal > 0) {
        ctx->nTotal = nTotal;
    }

    nMax = ctx->nTotal;
    if (nPos > nMax) {
        nPos = nMax;
    }

    if (ctx->nMode17c != 0) {
        if (nPos >= nWindow) {
            nRest = nMax - nPos;
            nFx = FX_Div(nRest * (0x4d - ctx->wRowHeight), nMax - nWindow);
            nFx = nFx + ctx->wRowHeight * 0x1000;
        } else {
            nFx = FX_Div(nPos * (0x4d - ctx->wScrollTop), nWindow);
            nFx = nFx + ctx->wScrollTop * 0x1000;
        }
    } else {
        if (nPos == nMax) {
            nPos = nPos - 1;
        }
        nFx = FX_Div(nPos * (0x4d - ctx->wScrollTop), nMax);
        nFx = nFx + ctx->wScrollTop * 0x1000;
    }

    ctx->wScrollThumb = (short)(nFx >> 12);
}
