

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

extern u16 GetGlyphIndex (const NNSG2dFontCodeMap * pMap, u16 c);

/* NNS_G2dFontFindGlyphIndex -- NitroSystem g2d_Font.c: NNS_G2dFontFindGlyphIndex. */
u16 NNS_G2dFontFindGlyphIndex (const NNSG2dFont * pFont, u16 c)
{
    const NNSG2dFontCodeMap * pMap;

    pMap = pFont->pRes->pMap;

    while (pMap != NULL) {
        if ((pMap->ccodeBegin <= c) && (c <= pMap->ccodeEnd)) {
            return GetGlyphIndex(pMap, c);
        }

        pMap = pMap->pNext;
    }

    return NNS_G2D_GLYPH_INDEX_NOT_FOUND;
}
