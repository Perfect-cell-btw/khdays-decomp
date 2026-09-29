/* Updates touch and display; returns the list step once the dialog finished. */

#include "game/engine.h"

extern int Ov026_FadeInStep(void);
extern void Ov026_UpdateTouchState(void);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_ShopConfirmPurchase(void);
extern char *data_ov026_02091368[];

void *Ov026_Shop_WaitDialogClose(void)
{
    void *result;

    if (Ov026_FadeInStep() != 0) {
        result = Ov026_ShopConfirmPurchase;
    } else {
        result = 0;
    }

    KeyRepeat_Step(data_ov026_02091368[0] + 0xc0fc);
    Ov026_UpdateTouchState();
    Ov026_RefreshPanelDisplay();

    return result;
}
