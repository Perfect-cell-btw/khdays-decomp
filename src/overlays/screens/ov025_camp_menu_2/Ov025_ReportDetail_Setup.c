/* Ov025_ReportDetail_Setup -- Ov025_ReportDetail_Setup: open the report detail view of page B
 * (Ov025_GetPageB 02084b14).  After the common reset (020afdb0) the mode (+0x54) comes from the
 * context field 9768 (enemy profiles rather than reports; 02085078) and the chapter (+0x58) from
 * game-state field 3 (020235d0; +1 while below 6); the background is loaded
 * (Ov025_ReportDetail_LoadBackground 020afdd4), the tag tracker (+0x44; 02084a64) and the entry
 * context (+0x48; 02084a8c) taken, the sprites bound (Ov025_ReportDetail_SetupEntries 020afef4),
 * the text surface built (Ov025_ReportDetail_SetupSurface 020b0090) and the view drawn
 * (Ov025_ReportDetail_Refresh 020b0484).  Always returns 1. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov025ReportDetailPage {
    int  nField00;            /* 0x00 */
    u8   surface[0x3c];       /* 0x04: the text surface (TileSurface) */
    int  nField40;            /* 0x40 */
    int  nTracker;            /* 0x44: the tag tracker */
    int  nCtx;                /* 0x48: the entry context */
    int  nField4c;            /* 0x4c */
    void *pEntry;             /* 0x50: the report shown */
    int  bMissionMode;        /* 0x54: enemy profiles rather than reports */
    int  nChapter;            /* 0x58: GameState field 3, +1 under 6 */
} Ov025ReportDetailPage;

extern Ov025ReportDetailPage *Ov025_GetPageB(void);            /* Ov025_GetPageB */
extern void  Ov025_PageB_Reset(void);                             /* Ov025_ReportDetail_Reset */
extern int   Ov025_GetCtxField9768(void);                             /* Ov025_GetCtxField9768 */
extern void  Ov025_ReportDetail_LoadBackground(void);                             /* Ov025_ReportDetail_LoadBackground */
extern int   Ov025_GetCtxBlock954c(void);                             /* Ov025_GetCtxBlock954c */
extern int   Ov025_GetBlock4a80(void);                             /* Ov025_GetBlock4a80 */
extern void  Ov025_ReportDetail_SetupEntries(void);                             /* Ov025_ReportDetail_SetupEntries */
extern void  Ov025_ReportDetail_SetupSurface(void);                             /* Ov025_ReportDetail_SetupSurface */
extern void  Ov025_ReportDetail_Refresh(void *pArg);                       /* Ov025_ReportDetail_Refresh: no argument used */

int Ov025_ReportDetail_Setup(void *pArg)
{
    Ov025ReportDetailPage *pPage;

    pPage = Ov025_GetPageB();
    Ov025_PageB_Reset();
    pPage->bMissionMode = Ov025_GetCtxField9768();
    pPage->nChapter = GameState_GetField(0x44e, 3);
    if (pPage->nChapter < 6) {
        pPage->nChapter++;
    }
    Ov025_ReportDetail_LoadBackground();
    pPage->nTracker = Ov025_GetCtxBlock954c();
    pPage->nCtx = Ov025_GetBlock4a80();
    Ov025_ReportDetail_SetupEntries();
    Ov025_ReportDetail_SetupSurface();
    Ov025_ReportDetail_Refresh(pArg);
    return 1;
}
