

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

static inline const NNSG2dCharWidths * GetCharWidthsFromIndex (const NNSG2dFontWidth * const pWidth, int idx)
{
    ((void) 0); ;
    return (NNSG2dCharWidths *)(pWidth->widthTable) + (idx - pWidth->indexBegin);
}

/* NNS_G2dFontGetCharWidthsFromIndex -- NitroSystem g2d_Font.c: NNS_G2dFontGetCharWidthsFromIndex. */
const NNSG2dCharWidths * NNS_G2dFontGetCharWidthsFromIndex (const NNSG2dFont * pFont, u16 idx)
{
    const NNSG2dFontWidth * pWidth;

    pWidth = pFont->pRes->pWidth;

    while (pWidth != NULL) {
        if ((pWidth->indexBegin <= idx) && (idx <= pWidth->indexEnd)) {
            return GetCharWidthsFromIndex(pWidth, idx);
        }

        pWidth = pWidth->pNext;
    }

    return &(pFont->pRes->defaultWidth);
}
