/* Ov025_RebindListHooksAfterTransfer -- Ov008_RebindListHooksAfterTransfer: the target slot is cleared
 * (Ov008_SetTargetSlot 02084798 0 / -1) and, once no transfer is pending (+0x30 of the menu
 * context), the three list callbacks of data_ov025_020b4d4c are rebound (done 020988c0, select
 * 020984ac, cancel 020985b8) and the confirm sound plays (02033b78 0 / 1).  Sibling of 02099558
 * without the list closing. */

#include "nitro/types.h"

typedef struct Ov008MenuContext {
    u8   pad_0000[0x30];
    int  nTransferPending;    /* 0x30 */
} Ov008MenuContext;

typedef struct Ov008ListHooks {
    u8   pad_00[0x14];
    void (*pfnSelect)(void);  /* 0x14 */
    void (*pfnCancel)(void);  /* 0x18 */
    u8   pad_1c[8];
    void (*pfnDone)(void);    /* 0x24 */
} Ov008ListHooks;

extern Ov008MenuContext *Ov025_GetPageA(void);                 /* Ov008_GetMenuContext */
extern void  Ov025_SetTargetSlot(int nEntry, int nTarget);          /* Ov008_SetTargetSlot */
extern void  Ov025_GridMenuConfirm(void);
extern void  Ov025_MenuKeyUp(void);
extern void  Ov025_MenuKeyDown(void);
extern void  PlaySound(int nKind, int nSound);                  /* PlaySound */
extern Ov008ListHooks data_ov025_020b4d4c;

void Ov025_RebindListHooksAfterTransfer(void)
{
    Ov008MenuContext *pCtx;

    pCtx = Ov025_GetPageA();
    Ov025_SetTargetSlot(0, -1);
    if (pCtx->nTransferPending != 0) {
        return;
    }
    data_ov025_020b4d4c.pfnDone = Ov025_GridMenuConfirm;
    data_ov025_020b4d4c.pfnSelect = Ov025_MenuKeyUp;
    data_ov025_020b4d4c.pfnCancel = Ov025_MenuKeyDown;
    PlaySound(0, 1);
}
