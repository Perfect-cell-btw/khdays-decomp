/*
 * Ov002_SceneLayoutPanelWindow - work out where the panel window and its two
 * inner boxes sit, and report how many entries it laid out for.
 *
 * The two text handles are recreated first, then the entries are measured and
 * the caption is measured through the first handle. The caption's height decides
 * the height of the upper box, capped at twenty rows; the entries push the box
 * up from the bottom until it would leave less than six rows, at which point it
 * is parked at row 0x11 instead. Everything else is derived from those two: the
 * lower box starts three rows below the top, the strip below it starts where the
 * upper box ends, and the outer frame is at least eight rows tall.
 *
 * ARM.
 */

#include "nnsys/g2d.h"

extern int data_ov002_0207f624;

extern NNSG2dTextRect NNSi_G2dFontGetTextRect(const NNSG2dFont *pFont, int hSpace, int vSpace,
                                              const void *txt);

extern int Ov002_Hud_GetBlock30(void);
extern int Ov002_MeasureActiveEntries(int *pnMax);

int Ov002_SceneLayoutPanelWindow(int *pLayout)
{
    NNSG2dTextRect used;
    int *ctx;
    int nCount;
    int nMax;
    NNSG2dTextRect size;
    int n;

    ctx = *(int **)&data_ov002_0207f624;
    ctx[0x6c8 / 4] = Ov002_Hud_GetBlock30();
    ctx[0x6f0 / 4] = Ov002_Hud_GetBlock30();
    nCount = Ov002_MeasureActiveEntries(&nMax);
    size = NNSi_G2dFontGetTextRect((const NNSG2dFont *)ctx[0x6c8 / 4], 0, 3,
                                   (const void *)ctx[0x7c0 / 4]);

    used = size;
    if (ctx[0x68c / 4] == 0) {
        pLayout[6] = 0x1e;
    } else {
        pLayout[6] = 0x18;
    }

    n = (used.height + 7) / 8;
    if (n >= 0x14) {
        n = 0x14;
    }
    pLayout[7] = n;
    pLayout[4] = 1;

    n = pLayout[7] + nCount * 2;
    if (n > 5) {
        n = 0x16 - n;
    } else {
        n = 0x11;
    }
    pLayout[5] = n;

    pLayout[8] = pLayout[4] + 3;
    pLayout[9] = pLayout[5] + pLayout[7];
    pLayout[10] = 0x18;
    pLayout[11] = nCount * 2 + 1;

    pLayout[0] = 0;
    pLayout[1] = pLayout[5] - 2;
    pLayout[2] = 0x20;
    n = pLayout[7] + pLayout[11] + 2;
    if (n <= 8) {
        n = 8;
    }
    pLayout[3] = n;
    return nCount;
}
