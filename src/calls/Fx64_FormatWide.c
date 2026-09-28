#pragma thumb on
/* Fx64_FormatWide -- format a 64-bit fixed-point value as two wide strings: the decimal integer part
 * into pIntOut and the fraction digits (to `precision` places) into pFracOut, both zero-terminated,
 * through the byte formatter Fx64_FormatText. */
typedef unsigned short u16;
typedef long long s64;

extern void Fx64_FormatText(s64 value, int precision, char *pIntText, char *pFracText);

static inline void WidenText(u16 *pDst, const char *pSrc)
{
    while (*pSrc != 0) {
        *pDst++ = *pSrc++;
    }
    *pDst = 0;
}

void Fx64_FormatWide(s64 value, int precision, u16 *pIntOut, u16 *pFracOut)
{
    char aIntText[26];
    char aFracText[14];

    Fx64_FormatText(value, precision, aIntText, aFracText);
    WidenText(pIntOut, aIntText);
    WidenText(pFracOut, aFracText);
}
