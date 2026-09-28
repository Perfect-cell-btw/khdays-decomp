#include "game/ov008_camp_menu.h"
/* Ov008_CardXferBeginGate -- card-transfer "begin" gate.
 *
 * While the owner is busy (+0x49c) there is no follow-up handler.  Otherwise ask the
 * ov105 stage to start the transfer: on success hand back the follow-up handler, on
 * failure latch +0x4f0 and stay on null.
 *
 * CODEGEN NOTE -- see the twin Ov006_MissionStartGate.  The ROM materialises the null
 * result up front (`mov r0,#0` filling the pool load's load-use slot) and runs the busy
 * chain through r1.  Writing the guard as an early `if (busy) return 0;` makes mwcc run
 * the chain through r0 and predicate the result with `movne r0,#0`.  The positive guard
 * plus the redundant `next = 0;` on the failure path is what reproduces the ROM: without
 * that re-assignment the tail shares the leading zero and the function is 4 bytes short.
 */
typedef void (*Ov008Handler)(void);

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
extern int Ov105_WH_Initialize(void);
extern void Ov008_HandleSubScenePoll(void);

Ov008Handler Ov008_CardXferBeginGate(void) {
    Ov008Handler next = 0;

    if (MISSION_CONTEXT->busy == 0) {
        if (Ov105_WH_Initialize() != 0) {
            return &Ov008_HandleSubScenePoll;
        }
        MISSION_CONTEXT->startFailed = 1;
        next = 0;
    }
    return next;
}
