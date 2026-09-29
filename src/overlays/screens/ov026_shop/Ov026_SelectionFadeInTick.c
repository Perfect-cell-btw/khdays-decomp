#include "game/engine.h"

extern char *data_ov026_02091368;
extern void Ov026_UpdateTouchState(void);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_ShopTabSelectTick(void);

/* Fade-in tick for the selection screen: 12 frames of brightness ramp (4x faster when the fast
 * flag is set), then hands over to the idle state. */
void *Ov026_SelectionFadeInTick(void) {
    void *next = 0;
    char *st = *(char **)&data_ov026_02091368;
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
        next = (void *)&Ov026_ShopTabSelectTick;
    }
    Ov026_UpdateTouchState();
    Ov026_RefreshPanelDisplay();
    return next;
}
