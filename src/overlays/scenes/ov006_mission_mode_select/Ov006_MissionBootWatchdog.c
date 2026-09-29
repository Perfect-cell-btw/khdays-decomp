/* Ov006_MissionBootWatchdog -- Mission Mode: per-frame watchdog on the boot/scene object.
 * Ticks the object held at data_ov006_02056668, and once it reports state 2 (finished) reads
 * the result (Overlay105_Release) and requests shutdown/reset with code -2. The global is re-read
 * after the tick because the tick may replace the object. */

#include "game/engine.h"

extern void func_02023ad0(int *p);
extern void OS_ResetSystem(int code);
extern int  data_ov006_02056668;

#define OBJ (*(int **)&data_ov006_02056668)

void Ov006_MissionBootWatchdog(void) {
    func_02023ad0(*(int **)OBJ);
    if (OBJ[1] != 2) {
        return;
    }
    Overlay105_Release();
    OS_ResetSystem(-2);
}
