/* Ov008_RebindListCallbacksAndClose -- Ov008_RebindListAndFadeAfterTransfer: once the pending
 * transfer is done, close the list (and the secondary list if it is not open),
 * rebind the three list callbacks and start the fade.  Twin of 02067640, which
 * skips the secondary list.
 */
typedef unsigned char u8;

typedef struct Ov008MenuContext {
    u8   pad_0000[0x30];
    int  nTransferPending;   /* 0x30 */
    u8   pad_0034[0x18];
    int  nSecondaryOpen;     /* 0x4c */
} Ov008MenuContext;

typedef struct Ov008ListHooks {
    u8   pad_00[0x14];
    void (*pfnSelect)(void); /* 0x14 */
    void (*pfnCancel)(void); /* 0x18 */
    u8   pad_1c[8];
    void (*pfnDone)(void);   /* 0x24 */
} Ov008ListHooks;

extern Ov008MenuContext *Ov008_GetMenuContext(void);            /* Ov008_GetMenuContext */
extern void Ov008_BeginMenuModeSwitch(Ov008MenuContext *pCtx, int nMode);
extern void Ov008_EnterMenuState(Ov008MenuContext *pCtx, int nMode);
extern void PlaySound(int nKind, int nArg);                 /* PlaySound */
extern void Ov008_GridMenuConfirm(void);
extern void Ov008_MenuKeyUp(void);
extern void Ov008_MenuKeyDown(void);
extern Ov008ListHooks data_ov008_02090380;

void Ov008_RebindListCallbacksAndClose(void)
{
    Ov008MenuContext *pCtx = Ov008_GetMenuContext();

    if (pCtx->nTransferPending != 0) {
        return;
    }
    Ov008_BeginMenuModeSwitch(pCtx, 0);
    if (pCtx->nSecondaryOpen == 0) {
        Ov008_EnterMenuState(pCtx, 0);
    }
    data_ov008_02090380.pfnDone = Ov008_GridMenuConfirm;
    data_ov008_02090380.pfnSelect = Ov008_MenuKeyUp;
    data_ov008_02090380.pfnCancel = Ov008_MenuKeyDown;
    PlaySound(0, 1);
}
