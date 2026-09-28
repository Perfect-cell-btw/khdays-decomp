#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

typedef struct NNSG2dCharWidths {
    s8 left;
    u8 glyphWidth;
    s8 charWidth;
} NNSG2dCharWidths;
typedef struct NNSG2dFontGlyph {
    u8 cellWidth;
    u8 cellHeight;
    u16 cellSize;
    s8 baselinePos;
    u8 maxCharWidth;
    u8 bpp;
    u8 flags;
    u8 glyphTable[];
} NNSG2dFontGlyph;
typedef struct NNSG2dFontWidth {
    u16 indexBegin;
    u16 indexEnd;
    struct NNSG2dFontWidth * pNext;
    NNSG2dCharWidths widthTable[];
} NNSG2dFontWidth;
typedef struct NNSG2dFontCodeMap {
    u16 ccodeBegin;
    u16 ccodeEnd;
    u16 mappingMethod;
    u16 reserved;
    struct NNSG2dFontCodeMap * pNext;
    u16 mapInfo[];
} NNSG2dFontCodeMap;
typedef struct NNSG2dFontInformation {
    u8 fontType;
    s8 linefeed;
    u16 alterCharIndex;
    NNSG2dCharWidths defaultWidth;
    u8 encoding;
    NNSG2dFontGlyph * pGlyph;
    NNSG2dFontWidth * pWidth;
    NNSG2dFontCodeMap * pMap;
} NNSG2dFontInformation;
typedef u16 (*NNSiG2dSplitCharCallback)(const void ** ppChar);
typedef struct NNSG2dFont {
    NNSG2dFontInformation * pRes;
    NNSiG2dSplitCharCallback cbCharSpliter;
} NNSG2dFont;
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
