#include "game/engine.h"

extern char *data_ov008_02090fac;
extern void Ov008_UpdateTouchState(void);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_ShopTabSelectTick(void);

/* Fade-in tick for the selection screen: 12 frames of brightness ramp (4x faster when the fast
 * flag is set), then hands over to the idle state. */
void *Ov008_SelectionFadeInTick(void) {
    void *next = 0;
    char *st = *(char **)&data_ov008_02090fac;
    int v = *(int *)st;
    if (v < 0xc) {
        if (*(int *)(st + 0xc3d8) != 0) {
            *(int *)st = v + 4;
        } else {
            *(int *)st = v + 1;
            SetMasterBrightnessMain((v + 1) * 16 / 12 - 0x10);
        }
        SetMasterBrightnessSub(*(int *)st * 16 / 12 - 0x10);
    } else {
        next = (void *)&Ov008_ShopTabSelectTick;
    }
    Ov008_UpdateTouchState();
    Ov008_RefreshPanelDisplay();
    return next;
}
