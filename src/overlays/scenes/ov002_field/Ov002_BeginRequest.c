/* Begin the request at +0x1b6, once. Refuses while the busy byte is already set,
 * while Ov002_GetRootField8b68Alt reports the subsystem occupied, and -- when the mode
 * byte at +0x1bb is non-zero -- unless Ov002_SetLeaveRequest(1) grants it. On
 * success it latches the busy byte, dispatches the request kind, and if the
 * follow-up state is 1 hands the ov022 handle on to Ov002_SetOrClearFlag200.
 * Every path reports 0. */

#include "game/engine.h"

extern int Ov002_GetRootField8b68Alt(void);
extern int Ov002_SetLeaveRequest(int a);
extern void Ov002_SetRosterHighlight(void *self, int kind, int a);
extern int Ov002_GetPhaseWord(void);
extern int func_ov022_02083f0c(void);
extern int func_ov022_02083f5c(void);
extern void func_ov022_02086818(int a, int b);
extern void Ov002_SetOrClearFlag200(int a, int b);

int Ov002_BeginRequest(unsigned char *self, unsigned char *req) {
    if (Ov002_GetRootField8b68Alt() != 0) {
        return 0;
    }
    if (self[0x1b6] == 0) {
        if (*(signed char *)(self + 0x1bb) != 0) {
            if (Ov002_SetLeaveRequest(1) == 0) {
                return 0;
            }
        }

        self[0x1b6] = 1;
        Ov002_SetRosterHighlight(self, req[0], 1);
        PauseMenu_SetAllowed(0);

        if (Ov002_GetPhaseWord() == 1) {
            int handle = func_ov022_02083f0c();

            func_ov022_02086818(func_ov022_02083f5c(), 0);
            Ov002_SetOrClearFlag200(handle, 1);
        }
    }

    return 0;
}
