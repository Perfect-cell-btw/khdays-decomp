/* Advances a timer; returns whether it is done (after 3.0 when the session is ready, at once
 * otherwise) and resets its state then. */

#include "game/engine.h"

int func_ov022_0208b1c8(int arg0, int *arg1, int arg2) {
    int r = 0;
    *arg1 += arg2;
    if (Session_IsReady()) {
        if (*arg1 >= 0x3000) r = 1;
    } else {
        r = 1;
    }
    if (r) *(char *)(arg1 + 0x53) = 0;
    return r;
}
