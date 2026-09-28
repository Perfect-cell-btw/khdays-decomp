/* Ov025_RebindListCallbacksAndClose -- Ov008_RebindListAndFadeAfterTransfer: once the pending
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

extern Ov008MenuContext *Ov025_GetPageA(void);            /* Ov008_GetMenuContext */
extern void Ov025_BeginMenuModeSwitch(Ov008MenuContext *pCtx, int nMode);
extern void Ov025_EnterMenuState(Ov008MenuContext *pCtx, int nMode);
extern void PlaySound(int nKind, int nArg);                 /* PlaySound */
extern void Ov025_GridMenuConfirm(void);
extern void Ov025_MenuKeyUp(void);
extern void Ov025_MenuKeyDown(void);
extern Ov008ListHooks data_ov025_020b4d4c;

void Ov025_RebindListCallbacksAndClose(void)
{
    Ov008MenuContext *pCtx = Ov025_GetPageA();

    if (pCtx->nTransferPending != 0) {
        return;
    }
    Ov025_BeginMenuModeSwitch(pCtx, 0);
    if (pCtx->nSecondaryOpen == 0) {
        Ov025_EnterMenuState(pCtx, 0);
    }
    data_ov025_020b4d4c.pfnDone = Ov025_GridMenuConfirm;
    data_ov025_020b4d4c.pfnSelect = Ov025_MenuKeyUp;
    data_ov025_020b4d4c.pfnCancel = Ov025_MenuKeyDown;
    PlaySound(0, 1);
}
