/* Ov025_MissionMenu_DrawMissionText -- Ov025_MissionMenu_DrawMissionText: draw a mission's text (+0x40 of its
 * name node) on the menu's text surface (+0xc): the surface takes target +0x138 (02030094), mode
 * 6 (+0x34) and is cleared (02030158); the text goes at (3, 3) in colour 0xf5 with shade 0xfb
 * (020302ec) and its measured height (020aa168) is kept at +0x144.  During a page transition
 * (02084e38) an empty text falls back to the alternate node's, when there is one. */

#include "nitro/types.h"

typedef struct Ov008MissionNameNode {
    u8   pad_00[0x40];
    const u16 *pText;         /* 0x40: the mission text */
    const u16 *pDesc;         /* 0x44: description text */
} Ov008MissionNameNode;

typedef struct Ov008MissionMenu {
    u8   pad_000[0xc];
    u8   surface[0x34 - 0xc]; /* 0x00c */
    int  nMode;               /* 0x034 */
    u8   pad_038[0x138 - 0x38];
    int  nTextTarget;         /* 0x138 */
    int  nLinesTarget;        /* 0x13c */
    u8   pad_140[4];
    int  nMissionTextHeight;  /* 0x144 */
    int  nTextHeight;         /* 0x148 */
} Ov008MissionMenu;

extern void  TileSurface_SetCurrentItem(void *pSurface, int nTarget, int nUpdate); /* TileSurface_SetCurrentItem */
extern void  Obj_InvokeInnerVtable4(void *pSurface);                         /* TileSurface_Clear */
extern int   Ov025_GetCtxObject9634(void);                             /* Ov025_GetCtxObject9634: page transition */
extern void  Obj_ForwardToSub1c(void *pSurface, int nX, int nY, int nColour, int nShade, const u16 *pText); /* Text_DrawShaded */
extern int   Ov025_MeasureWideStringHeight(const u16 *pText);                 /* Ov025_MeasureTextHeight */

void Ov025_MissionMenu_DrawMissionText(Ov008MissionMenu *pMenu, Ov008MissionNameNode *pNode, Ov008MissionNameNode *pAltNode)
{
    int nHeight;
    const u16 *pText;

    pText = pNode->pText;
    nHeight = 0;
    TileSurface_SetCurrentItem(pMenu->surface, pMenu->nTextTarget, 0);
    pMenu->nMode = 6;
    Obj_InvokeInnerVtable4(pMenu->surface);
    if (Ov025_GetCtxObject9634() == 0) {
        Obj_ForwardToSub1c(pMenu->surface, 3, 3, 0xf5, 0xfb, pText);
        nHeight += Ov025_MeasureWideStringHeight(pText);
    } else if (*pText != 0) {
        Obj_ForwardToSub1c(pMenu->surface, 3, 3, 0xf5, 0xfb, pText);
        nHeight += Ov025_MeasureWideStringHeight(pText);
    } else if (pAltNode != 0) {
        Obj_ForwardToSub1c(pMenu->surface, 3, 3, 0xf5, 0xfb, pAltNode->pText);
        nHeight += Ov025_MeasureWideStringHeight(pAltNode->pText);
    }
    pMenu->nMissionTextHeight = nHeight;
}
