/* c634 handler: arm the second phase of the move.
 *
 * Set the countdown from the template's +0x2c (as `* 30 / 5`, the multiply-and-magic-
 * divide the ROM emits), and bail out if the progress counter has already reached 0x100.
 * Otherwise copy the two shorts at the table's +0xc/+0xe into a stack pair, hand them to
 * the owner's callback at +0x24 when it has one, then re-arm the countdown at `* 30 / 10`,
 * notify the owner, clear the two per-phase fields and dispatch the next step.
 *
 * PARKED as an "arg-materialization scheduling tie ... not steerable from C".  It is
 * steerable, and the knob is SCOPE.  The ROM computes &buf immediately after the guard;
 * mwcc puts it just before the blx with the buffer used directly, and hoists it ABOVE the
 * guard when given a pointer at function scope.  Declaring the pointer inside the block
 * that follows the guard lands it exactly where the ROM has it:
 *
 *     if (progress >= 0x100) return;
 *     {
 *         unsigned short *p = buf;      <- `add r1, sp, #0` right here
 *         p[1] = ...; p[0] = ...;
 *         if (cb != 0) cb(owner, p, 4);
 *     }
 *
 * Declaring the ARRAY itself in that block is not the same thing and does not work; it is
 * the pointer's live range that pins the materialization.
 *
 * The same fix does NOT rescue Ov141_ProjectileAction_Enter, which has the same early-&buf symptom
 * but is parked on a genuine halfword-order difference underneath it.  Two functions can
 * show the same surface symptom and need different things.
 */

#include "game/enemy_common.h"

extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov160_AttackWaitTick(void);
extern unsigned short data_ov160_020cf794[];
void Ov160_ArmMovePhase2(int self) {
    int obj = *(int *)(self + 4);
    unsigned short buf[2];
    void (*cb)(int owner, void *b, int c);
    *(int *)(obj + 0x14) = *(int *)(*(int *)self + 0x2c) * 30 / 5;
    if (*(int *)(obj + 0x40) >= 0x100) {
        return;
    }
    {
        unsigned short *p = buf;
        p[1] = data_ov160_020cf794[7];
        p[0] = data_ov160_020cf794[6];
        cb = *(void (**)(int, void *, int))(*(int *)obj + 0x24);
        if (cb != 0) {
            cb(*(int *)obj, p, 4);
        }
    }
    *(int *)(obj + 0x14) = *(int *)(*(int *)self + 0x2c) * 30 / 10;
    Ov107_PostTagUpdate((Actor *)(*(int *)obj), 6, 0);
    *(int *)(obj + 0x3c) = 0;
    *(unsigned char *)(obj + 0x54) = 0;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov160_AttackWaitTick);
}
