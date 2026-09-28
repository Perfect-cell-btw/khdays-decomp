/* Ov008_DrawDescriptionText -- Ov008_DrawDescriptionText: draw a description string on
 * the panel's text surface (+0xc160, region (0, 0xa0, 0x100 x 0x20) cleared
 * first) from (8, 0xa4).  Code unit 1 selects colour 4, 2 colour 2; any other
 * glyph is drawn once with a (+1, +1) colour-1 shadow and once in the current
 * colour, advancing the pen by the returned width.  A newline (10) is skipped
 * and returns the pen to x 8 on the next 15-px line.  Widget 0x3f of the
 * widget group is shown with frame nIcon when nIcon is below 0x3f, hidden
 * otherwise.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define TEXT_X0   8
#define TEXT_Y0   0xa4
#define LINE_STEP 15
#define WIDGET_ICON 0x3f
#define ICON_NONE   0x3f

extern char *data_ov008_02090fac;
extern void Obj_InvokeInnerVtable8(void *pSurface, int nX, int nY, int nW, int nH); /* Obj_InvokeInnerVtable8 */
extern int  Obj_ForwardInnerPayload(void *pSurface, int nX, int nY, int nColour, int nGlyph); /* Obj_ForwardInnerPayload */
extern void *Ov008_FindEntryById(void *pGroup, int nId);              /* FindEntryById */
extern void Ov008_SetEntrySlotsVisible(void *pGroup, void *pWidget, int bVisible); /* SetEntrySlotsVisible */
extern void Ov008_ReleaseTwoSlotsEx(void *pGroup, void *pWidget, int nFrame);   /* Ov008_ReleaseTwoSlotsEx */

void Ov008_DrawDescriptionText(u16 *pText, u32 nIcon)
{
    char *ctx = data_ov008_02090fac;
    u8 (*pSurface)[0xc000];
    u8 (*pGroup)[0x2000];
    int nY;
    int nX;
    int nColour;
    void *pWidget;

    pSurface = (u8 (*)[0xc000])(ctx + 0x160);
    pGroup = (u8 (*)[0x2000])(ctx + 0xab0);
    nColour = 4;
    Obj_InvokeInnerVtable8(pSurface + 1, 0, 0xa0, 0x100, 0x20);
    nY = TEXT_Y0;
    nX = TEXT_X0;
    while (*pText != 0) {
        u16 c = *(volatile u16 *)pText;   /* the ROM re-reads the code unit (precedent 020681b0) */
        switch (c) {
        case 1:
            nColour = 4;
            break;
        case 2:
            nColour = 2;
            break;
        default:
            Obj_ForwardInnerPayload(pSurface + 1, nX + 1, nY + 1, 1, c);
            nX += Obj_ForwardInnerPayload(pSurface + 1, nX, nY, nColour, *pText);
            break;
        }
        pText++;
        if (*pText == 10) {
            pText++;
            nX = TEXT_X0;
            nY += LINE_STEP;
        }
    }
    pWidget = Ov008_FindEntryById(pGroup + 1, WIDGET_ICON);
    Ov008_SetEntrySlotsVisible(pGroup + 1, pWidget, nIcon < ICON_NONE);
    if (nIcon < ICON_NONE) {
        Ov008_ReleaseTwoSlotsEx(pGroup + 1, pWidget, (u16)nIcon);
    }
}
