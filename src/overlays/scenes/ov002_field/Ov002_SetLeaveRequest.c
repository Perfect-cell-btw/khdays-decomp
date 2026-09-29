/*
 * Arms or clears the session's leave request and reports whether the request
 * stands.
 *
 * Clearing always succeeds. Arming is unconditional for a peer, but the
 * machine that owns the session has to earn it: the bit must not already be
 * set, the alternate root field must be clear, and the slot-request gate has
 * to agree. Any of those refuses and the bit is left alone.
 *
 * One thing here is load-bearing rather than style. The already-set test is
 * its own statement while the last two checks are one condition joined by an
 * or, which is what gives the first its predicated exit and the other two a
 * shared one, exactly as the original splits them.
 *
 * ARM.
 */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov002RootContext {
    char pad0000[0x8b64];
    int nFlags;
} Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;

extern int Ov002_GetRootField8b68Alt(void);
extern int Ov002_CanAcceptSlotRequest(void);

int Ov002_SetLeaveRequest(int bArm)
{
    Ov002RootContext *pCtx;

    pCtx = data_ov002_0207fa00;
    if (bArm == 0) {
        pCtx->nFlags &= ~0x200;
    } else {
        if (Session_GetLocalPlayerIndex() == 0) {
            if ((pCtx->nFlags & 0x200) != 0) {
                return 0;
            }
            if (Ov002_GetRootField8b68Alt() != 0 || Ov002_CanAcceptSlotRequest() == 0) {
                return 0;
            }
        }
        pCtx->nFlags |= 0x200;
    }
    return 1;
}
