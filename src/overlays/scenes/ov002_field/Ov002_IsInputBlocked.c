/* Report whether input is currently blocked: yes while the session is not ready,
 * and yes while either of bits 1 and 7 of the context's flag word is set.
 * Otherwise Ov002_AdvancePhase decides. The flag word is read ONCE and both
 * bits tested against the same register. */

#include "game/engine.h"

extern int Ov002_AdvancePhase(void);

extern int *data_ov002_0207fa08;

int Ov002_IsInputBlocked(void) {
    int *ctx = data_ov002_0207fa08;
    int flags;

    if (Session_IsReady() == 0) {
        return 1;
    }

    flags = *ctx;
    if (flags & 2) {
        return 1;
    }
    if (flags & 0x80) {
        return 1;
    }
    return Ov002_AdvancePhase();
}
