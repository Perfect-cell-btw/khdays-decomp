#include "game/ov006_mission_mode_select.h"
/* Ov006_MissionStartGate -- Mission Mode "start" gate.
 *
 * Reports "no handler yet" (null) while the scene is still blocked (+0x49c) and while
 * the ov105 sound/transfer stage has not fired.  Once it fires, hand back the next
 * scene handler; if it reports failure, latch +0x4f0 and stay on null.
 *
 * CODEGEN NOTE -- the ROM materialises the null result ONCE up front (`mov r0,#0`
 * scheduled into the pool load's load-use slot) and runs the guard chain through r1;
 * writing the guard as an early `if (blocked) return null;` makes mwcc compute the
 * chain in r0 and predicate the result with `movne r0,#0` instead.  Two source shapes
 * are load-bearing here:
 *   1. the guard is the POSITIVE form -- `if (!blocked) { ... }` wrapping the body,
 *      with a single `return next;` at the end;
 *   2. the failure path RE-ASSIGNS `next = 0;`.  It is redundant as C, but it is what
 *      forces mwcc to emit the second `mov r0,#0` in the tail; drop it and the tail
 *      shares the leading zero and the function is 4 bytes short.
 * Same shape matches its ov008 twin Ov008_CardXferBeginGate.
 */
typedef struct Ov006MissionCtx {
    char _pad0000[0x49c];
    int nStartBlocked;             /* +0x49c: non-zero while the start is held off */
    char _pad04a0[0x4f0 - 0x49c - 4];
    unsigned char bStartFailed;    /* +0x4f0: latched when the ov105 stage refuses */
} Ov006MissionCtx;

typedef void (*Ov006Handler)(void);

#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
extern int Ov105_WH_Initialize(void);
extern void Ov006_HandleSubScenePoll(void);

Ov006Handler Ov006_MissionStartGate(void) {
    Ov006Handler next = 0;

    if (MISSION_CONTEXT->busy == 0) {
        if (Ov105_WH_Initialize() != 0) {
            return &Ov006_HandleSubScenePoll;
        }
        MISSION_CONTEXT->startFailed = 1;
        next = 0;
    }
    return next;
}
