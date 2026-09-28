

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

int NNSi_G2dFontGetStringWidth(const NNSG2dFont * pFont, int hSpace, const void * str, const void ** pPos);
extern int NNSi_G2dFontGetStringWidth (const NNSG2dFont * pFont, int hSpace, const void * str, const void ** pPos);

/* NNSi_G2dFontGetTextWidth -- NitroSystem g2d_Font.c: NNSi_G2dFontGetTextWidth. */
int NNSi_G2dFontGetTextWidth (const NNSG2dFont * pFont, int hSpace, const void * txt)
{
    int width = 0;

    while (txt != NULL) {
        const int line_width = NNSi_G2dFontGetStringWidth(pFont, hSpace, txt, &txt);
        if (line_width > width) {
            width = line_width;
        }
    }

    return width;
}
