/*
 * Ov002_SetCaptionText - put a line of text on the caption surface.
 *
 * The first line asked for brings the surface up: its two resources are handed
 * to the shared text globals, the surface is built, the top rows of the BG1
 * screen are refreshed, and during a replay the run summary is built once.
 *
 * Every line is then drawn with the surface temporarily switched to item 0, and
 * its width is kept both for the row that owns it and for the next caller.
 *
 * A null line only clears what is there, and either way the surface is flushed
 * before the caption entry is selected again.
 *
 * ARM.
 */

#include "nitro/types.h"

typedef struct {
    char pad000[0x10];
    char textCtx[0x3c];
    int bLoaded;
    int nBaseItem;
    int nStyle;
    char pad058[0x58];
    int nWidth;
} Ov002CaptionScene;

extern int data_ov002_0207f62c;
extern int data_ov002_0207ebf4[];
extern const int data_ov002_0207ec28;
extern u8 data_0204c240;

extern void *G2S_GetBG1ScrPtr(void);
extern void MIi_CpuCopy16(const void *src, void *dst, unsigned int size);

extern void TileSurface_InitAndUpload4bpp(void *pCtx, const void *pCfg);
extern int TileSurface_AddCanvas(void *pCtx, int nIndex);
extern void TileSurface_SetCurrentItem(void *pCtx, int nStyle, int nFlags);
extern void EnqueueObjGfxCommand(void *pCtx);
extern void Obj_InvokeInnerVtable4(void *pCtx);
extern void Text_DrawWithShadow(void *pCtx, int a, int b, int c, const void *pText,
                          int d);
extern int Obj_GetWord18(void *pCtx);
extern int TextWindow_GetTextWidth(void *pCtx, const void *pText);

extern int Ov002_GetItemResource(int nId);
extern void Ov002_SelectEntry(int nId);
extern int Ov002_Hud_GetBlock30(void);
extern void Ov002_SetRowValue(int nRow, int nWidth);
extern void Ov002_BuildRunSummary(void);

void Ov002_SetCaptionText(const u16 *pText)
{
    Ov002CaptionScene *s;
    int nItem;
    char *pScreen;

    s = *(Ov002CaptionScene **)((char *)&data_ov002_0207f62c + 4);
    if (pText != 0) {
        if (s->bLoaded == 0) {
            data_ov002_0207ebf4[0x13] = Ov002_GetItemResource(0x18);
            data_ov002_0207ebf4[0x15] = Ov002_Hud_GetBlock30();
            TileSurface_InitAndUpload4bpp(s->textCtx, &data_ov002_0207ec28);
            pScreen = (char *)G2S_GetBG1ScrPtr();
            MIi_CpuCopy16(pScreen + 0x700,
                          (char *)Ov002_GetItemResource(0x19) + 0x700, 0x80);
            Ov002_SelectEntry(0x19);
            s->nBaseItem = Obj_GetWord18(s->textCtx);
            if ((data_0204c240 & 6) == 2) {
                s->nStyle = TileSurface_AddCanvas(s->textCtx, 0);
                Ov002_BuildRunSummary();
            }
            s->bLoaded = 1;
        }
        nItem = Obj_GetWord18(s->textCtx);
        TileSurface_SetCurrentItem(s->textCtx, 0, 0);
        Obj_InvokeInnerVtable4(s->textCtx);
        Text_DrawWithShadow(s->textCtx, 8, 3, 2, pText, 0);
        s->nWidth = TextWindow_GetTextWidth(s->textCtx, pText);
        Ov002_SetRowValue(0, s->nWidth);
        TileSurface_SetCurrentItem(s->textCtx, nItem, 0);
    } else {
        if (s->bLoaded != 0) {
            nItem = Obj_GetWord18(s->textCtx);
            TileSurface_SetCurrentItem(s->textCtx, 0, 0);
            Obj_InvokeInnerVtable4(s->textCtx);
            TileSurface_SetCurrentItem(s->textCtx, nItem, 0);
        }
        s->nWidth = 0;
    }
    EnqueueObjGfxCommand(s->textCtx);
    Ov002_SelectEntry(0x18);
}
