/*
 * Ov002_ShowNoticeText - put a notice on the second caption surface.
 *
 * Only the first notice is taken: once a copy is held, later calls do nothing at
 * all. The line is copied onto the heap, drawn into the surface, and its extent
 * is kept for the layout that follows.
 *
 * During a replay the recap line is refreshed as well, and every accepted call
 * ends by kicking the step that puts the surface on screen.
 *
 * ARM.
 */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct {
    char pad000[0xb8];
    u16 *pLine;
    char pad0bc[0x40];
    char noticeCtx[0x3c];
    char gaugeCtx[0x3c];
    int nExtent;
    int nRecap;
} Ov002CaptionScene;

extern int data_ov002_0207f62c;
extern u8 data_0204c240;

extern void *NNSi_FndAllocFromDefaultExpHeap(unsigned int nSize);
extern int Wcslen(const u16 *pText);
extern void StrCopy16(u16 *pDst, const u16 *pSrc);

extern void Ov002_DrawMessageCaption(void);
extern void Ov002_TickOptionsPage(void);

void Ov002_ShowNoticeText(const u16 *pText)
{
    Ov002CaptionScene *s;

    s = *(Ov002CaptionScene **)((char *)&data_ov002_0207f62c + 4);
    if (s->pLine != 0) {
        return;
    }

    if (pText != 0) {
        s->pLine =
            (u16 *)NNSi_FndAllocFromDefaultExpHeap((Wcslen(pText) + 1) * 2);
        StrCopy16(s->pLine, pText);
        Text_DrawWithShadow(s->noticeCtx, 0, 0, 0xf, pText, 0);
        s->nExtent = Obj_GetWord18(s->noticeCtx);
        if ((data_0204c240 & 6) == 2 && s->nRecap != 0) {
            Ov002_DrawMessageCaption();
        }
    }
    Ov002_TickOptionsPage();
}
