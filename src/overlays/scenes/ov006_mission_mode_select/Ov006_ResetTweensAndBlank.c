/* Ov006_ResetTweensAndBlank -- if a heap is active, reset the two tween channels (-0x10) and
 * blank both screens' BG mode bits. */

#include "game/engine.h"

#define REG_DISPCNT     (*(volatile unsigned int *)0x04000000)
#define REG_DISPCNT_SUB (*(volatile unsigned int *)0x04001000)
extern int  NNSi_FndGetCurrentRootHeap(void);

void Ov006_ResetTweensAndBlank(void) {
    if (NNSi_FndGetCurrentRootHeap() == 0) {
        return;
    }
    SetMasterBrightnessMain(-0x10);
    SetMasterBrightnessSub(-0x10);
    REG_DISPCNT &= 0xffffe0ff;
    REG_DISPCNT_SUB &= 0xffffe0ff;
}
