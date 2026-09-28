/*
 * Text_DrawGlyph - resolve one character to a glyph and blit it, returning its advance.
 *
 * Looks up the glyph index for `ch` (NNS_G2dFontFindGlyphIndex); a miss (0xffff) falls back to the
 * font's default glyph (*(u16 *)(font[0] + 2)). Resolves the glyph metrics pointer
 * (NNS_G2dFontGetCharWidthsFromIndex) and the bitmap address (glyphIndex * cellStride + glyphTable + 8).
 * Applies a per-format pen adjustment selected by the glyph-table mode byte
 * glyphTable[7]: modes 0/7 shift x by the left bearing; 1/2 also lift y; 3/4 and 5/6
 * apply the table's fixed offsets. Finally it dispatches to the owner's blit callback
 * (*(fn **)(owner + 0x14))[0] with the {metrics, bitmap} pair, and returns the glyph
 * advance width (signed byte at metrics[2]).
 *
 * The leaf of the text-render chain: called per glyph by Text_DrawLine (Text_DrawLine).
 */

typedef struct { char *metrics; int bitmap; } GlyphDraw;

extern unsigned NNS_G2dFontFindGlyphIndex(int *font, unsigned ch);
extern char *NNS_G2dFontGetCharWidthsFromIndex(int *font, unsigned glyph);

int Text_DrawGlyph(int owner, int *font, int x, int y, int p5, unsigned short ch)
{
    GlyphDraw gd;
    unsigned glyph;
    unsigned char *G;

    glyph = NNS_G2dFontFindGlyphIndex(font, ch);
    if (glyph == 0xffff)
        glyph = *(unsigned short *)(*font + 2);
    gd.metrics = NNS_G2dFontGetCharWidthsFromIndex(font, glyph);
    gd.bitmap = glyph * *(unsigned short *)(*(int *)(*font + 8) + 2) + (*(int *)(*font + 8) + 8);
    G = *(unsigned char **)(*font + 8);
    switch (G[7]) {
    case 0:
    case 7:
        x += *(signed char *)gd.metrics;
        break;
    case 1:
    case 2:
        x -= G[0];
        y += *(signed char *)gd.metrics;
        break;
    case 3:
    case 4:
        x -= *(signed char *)gd.metrics + *(unsigned char *)(gd.metrics + 1);
        y -= G[1];
        break;
    case 5:
    case 6:
        y -= *(signed char *)gd.metrics + G[1];
        break;
    }
    (*(int (**)(int, int *, int, int, int, GlyphDraw *))(*(int *)(owner + 0x14)))
        (owner, font, x, y, p5, &gd);
    return *(signed char *)(gd.metrics + 2);
}
