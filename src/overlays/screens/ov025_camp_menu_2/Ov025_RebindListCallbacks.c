#include "game/engine.h"

extern char *Ov025_GetPageA(void);
extern void Ov025_BeginMenuModeSwitch(char *self, int mode);
extern void Ov025_GridMenuConfirm(void);
extern void Ov025_MenuKeyUp(void);
extern void Ov025_MenuKeyDown(void);
extern char *data_ov025_020b4d4c;

/* Once the pending transfer is done, rebinds the three list callbacks and starts the fade. */
void Ov025_RebindListCallbacks(void) {
    char *self = Ov025_GetPageA();
    if (*(int *)(self + 0x30) != 0) {
        return;
    }
    Ov025_BeginMenuModeSwitch(self, 0);
    *(void **)((char *)&data_ov025_020b4d4c + 0x24) = (void *)&Ov025_GridMenuConfirm;
    *(void **)((char *)&data_ov025_020b4d4c + 0x14) = (void *)&Ov025_MenuKeyUp;
    *(void **)((char *)&data_ov025_020b4d4c + 0x18) = (void *)&Ov025_MenuKeyDown;
    PlaySound(0, 1);
}
