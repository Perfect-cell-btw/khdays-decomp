/* Ov025_MenuKeyCancel -- Ov008_MenuKeyCancel: the grid menu's cancel handler.
 * Nothing while busy (+0x30), while a drag/tween/scroll is live (+0x24/+0x28/
 * +0x2c) or with a touch down.  Resets the grid, hides widget 3, then: from
 * the sub-menu (+8 == 1) clears the parameter overrides, closes the list
 * (mode 0; the secondary list too when no secondary panel) and rebinds the
 * three list hooks; otherwise closes the list with mode 1, refreshes menu
 * button 5 and rebuilds the grid hits.  Cue 0x38 either way.
 */
typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct Ov008MenuContext {
    u8   pad_0000[0x8];
    int  nPending;            /* 0x0008: 1 = sub-menu open */
    u8   pad_000c[0x24 - 0xc];
    int  bDrag;               /* 0x0024 */
    int  bTween;              /* 0x0028 */
    int  bScroll;             /* 0x002c */
    int  nBusy;               /* 0x0030 */
    u8   pad_0034[0x4c - 0x34];
    int  bSecondaryPanel;     /* 0x004c */
} Ov008MenuContext;

typedef struct Ov008ListHooks {
    u8   pad_00[0x14];
    void (*pfnSelect)(void); /* 0x14 */
    void (*pfnCancel)(void); /* 0x18 */
    u8   pad_1c[8];
    void (*pfnDone)(void);   /* 0x24 */
} Ov008ListHooks;

#define WIDGET_DRAG 3
#define SOUND_CANCEL 0x38

extern int  Ov025_GetContext(void);                                    /* Ov008_GetContext */
extern void Ov025_CopySourceBlock(void *pOut);                              /* touch record */
extern void Ov025_ResetGridDrag(Ov008MenuContext *pCtx, int nArg);        /* grid reset */
extern void *Ov025_FindEntryById(int nCtx, int nId);                      /* FindEntryById */
extern void Ov025_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);    /* SetEntrySlotsVisible */
extern void Ov025_SwapParamOverrides(int nCtx, void *pEntry);                  /* Ov008_SwapParamOverrides */
extern void Ov025_BeginMenuModeSwitch(Ov008MenuContext *pCtx, int nMode);
extern void Ov025_EnterMenuState(Ov008MenuContext *pCtx, int nMode);
extern void Ov025_UpdateMenuButton5(int nArg);                                /* Ov008_UpdateMenuButton5 */
extern void Ov025_RebuildGridHits(Ov008MenuContext *pCtx);                  /* Ov008_RebuildGridHits */
extern void PlaySound(int nKind, int nSound);                         /* PlaySound */
extern void Ov025_GridMenuConfirm(void);
extern void Ov025_MenuKeyUp(void);
extern void Ov025_MenuKeyDown(void);
extern Ov008ListHooks data_ov025_020b4d4c;

void Ov025_MenuKeyCancel(Ov008MenuContext *pCtx)
{
    int nCtx = Ov025_GetContext();
    u16 touch[3];

    if (pCtx->nBusy != 0) {
        return;
    }
    if (pCtx->bDrag != 0 || pCtx->bTween != 0 || pCtx->bScroll != 0) {
        return;
    }
    Ov025_CopySourceBlock(touch);
    if (touch[2] != 0) {
        return;
    }
    Ov025_ResetGridDrag(pCtx, 0);
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, WIDGET_DRAG), 0);
    if (pCtx->nPending == 1) {
        Ov025_SwapParamOverrides(nCtx, 0);
        Ov025_BeginMenuModeSwitch(pCtx, 0);
        if (pCtx->bSecondaryPanel == 0) {
            Ov025_EnterMenuState(pCtx, 0);
        }
        data_ov025_020b4d4c.pfnDone = Ov025_GridMenuConfirm;
        data_ov025_020b4d4c.pfnSelect = Ov025_MenuKeyUp;
        data_ov025_020b4d4c.pfnCancel = Ov025_MenuKeyDown;
    } else {
        Ov025_BeginMenuModeSwitch(pCtx, 1);
        Ov025_UpdateMenuButton5(1);
        Ov025_RebuildGridHits(pCtx);
    }
    PlaySound(0, SOUND_CANCEL);
}
