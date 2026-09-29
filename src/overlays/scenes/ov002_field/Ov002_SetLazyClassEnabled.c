/*
 * Ov002_SetLazyClassEnabled - enable or disable the ov002 lazy-init subsystem and record
 * its state in bit0 of the root context flag byte (ctx+0x8d0a). Called from the ov002
 * gameplay scene tick (Ov002_ConstructGameplayScene).
 *
 * No-op while the global mode byte (LoadGlobalS8_027e0084) is 0x10. Otherwise, when enabling
 * (param_1 != 0) it runs Ov002_LazyInitClass and sets bit0; when disabling it runs the
 * teardown counterpart (Ov002_ReleaseObjectService) and clears bit0. `&= ~1` (not `& 0xfe`) so mwcc
 * emits `bic #1`. The root context pointer is held at data_ov002_0207fa00.
 */

#include "nitro/types.h"
#include "game/engine.h"

extern void Ov002_LazyInitClass(void);
extern void Ov002_ReleaseObjectService(void);
extern int  data_ov002_0207fa00;

void Ov002_SetLazyClassEnabled(int param_1)
{
    int ctx = data_ov002_0207fa00;

    if (GetMasterBrightnessMain() == 0x10) {
        return;
    }
    if (param_1 != 0) {
        Ov002_LazyInitClass();
        *(u8 *)(ctx + 0x8d0a) |= 1;
        return;
    }
    Ov002_ReleaseObjectService();
    *(u8 *)(ctx + 0x8d0a) &= ~1;
}
