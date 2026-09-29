/* Begin the move: acquire the target node, or bail out by requesting state 2.
 *
 * On success it notifies the owner, resets the sub-object, sets the countdown from the
 * template's +0x2c (kept as `* 0x1e / 10`, the multiply-and-magic-divide the ROM emits),
 * picks a random value in [+0x224, +0x228] with the range forced positive, and takes the
 * vector from the acquired node to the current position before handing off to the
 * per-frame step.
 *
 * PARKED behind `extern void Ov107_PostTagUpdate();` -- empty parentheses again, so the
 * zero-argument call under it compiled silently.  It takes (owner, mode, arg), and both
 * of the constants were already visible in the ROM, hoisted well above the call:
 *   - `mov r1, #2` at 0x30 sits ABOVE the branch and does double duty, as the state byte
 *     stored on the bail-out path and as this call's second argument on the other.  That
 *     is the "constant in the wrong register" tell from the pre-park checklist, showing
 *     up as a constant with no visible consumer instead.
 *   - `mov r2, #0` at 0x1c is the third argument, hoisted to the prologue -- and 0x1c is
 *     exactly where the parked version diverged.
 * The park also carried an uninitialised `int v` and a `+ (v - v)` term in the random
 * expression, scaffolding from some earlier hypothesis.  It is not needed: the function
 * matches without it, and reading uninitialised storage is not something to leave in
 * matched code.
 */

#include "game/enemy_common.h"

/* Head of a 5-member family.  Byte-exact.
 *
 * Why this looked impossible for so long: the ROM hoists two constants above the branch so
 * they serve both paths -- `mov r2,#0` (third argument of the tail SetIndexedSlot) and
 * `mov r1,#2` (the 0x1c7 state). With the callee arities wrong those constants have no
 * visible consumer, which reads exactly like a scheduler difference. Correct the arities
 * and mwcc hoists them too.
 *
 * SOLVED here -- do NOT rediscover:
 *  - Ov107_PostTagUpdate is called here with NO arguments at all (no r0-r3 setup before the
 *    bl). Passing (obj, 0, 0) is 8 B long. Same callee takes 3 elsewhere -- it is unprototyped,
 *    so read the arity per call site.
 *  - the tail SetIndexedSlot DOES take its third argument here (dropping it is 4 B short), so
 *    the two calls to the same function in this function have different arities.
 *  - `* 0x1e / 10` reproduces the magic multiply (0x66666667, asr #2).
 *
 * Ruled out: the `+ (v - v)` RNG artifact (identical either way here), a local for the RNG
 * result (+4 B), writing the body as the positive case (112 bytes -- much worse), and caching
 * *obj in a local (no change). Measured with tools/bytedist.py. */
extern int  Ov107_FindNearestObject(int obj, int flag);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov197_SeedDefaultPoseAndAdvance(int owner, int a);
extern int  RandNextScaled();
extern void VEC_Subtract();
extern void Ov197_ApplyTransformThenReseedIfFree(void);

void Ov197_BeginMoveOrRequestState2(int *self) {
    int *obj = (int *)self[1];
    int lo, range;

    *(int *)(*obj + 0x394) = Ov107_FindNearestObject(*obj, 0);
    if (*(int *)(*obj + 0x394) == 0) {
        *(signed char *)(*obj + 0x1c7) = 2;
        SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), 0);
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*obj), 2, 0);
    Ov197_SeedDefaultPoseAndAdvance(*obj, 0);
    obj[0xf] = *(int *)(self[0] + 0x2c) * 0x1e / 10;
    lo = *(int *)(*obj + 0x224);
    range = *(int *)(*obj + 0x228) - lo;
    if (range < 0) {
        range = -range;
    }
    obj[0x10] = lo + RandNextScaled(range + 1);
    VEC_Subtract(*(int *)(*obj + 0x394) + 400, obj[3], obj + 10);
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), &Ov197_ApplyTransformThenReseedIfFree);
}
