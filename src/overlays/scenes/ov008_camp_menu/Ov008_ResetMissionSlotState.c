/* Ov008_ResetMissionSlotState -- reset the ov008 mission-slot state and set its mode word (obj+2):
 * mode 2 only when the shared flag, Session_IsActive and NOT Session_IsReady all agree; otherwise 1. */

#include "game/engine.h"

extern int  Ov008_GetMenuContext(void);
extern void MI_CpuFill8(void *dst, int val, unsigned int size);

void Ov008_ResetMissionSlotState(void) {
    int *obj = (int *)Ov008_GetMenuContext();
    int alt;
    MI_CpuFill8(obj, 0, 0xbc);
    alt = 0;
    obj[0x2d] = alt;
    obj[0x2e] = alt;
    if (Session_Exists() == 0) {
        alt = 1;
    }
    if (Session_IsActive() == 0) {
        alt = 1;
    }
    if (Session_IsReady() != 0) {
        alt = 1;
    }
    *(unsigned short *)((int)obj + 2) = (alt != 0) ? 1 : 2;
}
