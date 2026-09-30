/* Ov282_AiPickMove -- ov282's move CHOOSER, the plain (non-steering) shape.
 *
 * Byte-identical to Ov210_AiPickMove modulo this overlay's own symbols; that is the rep
 * and carries the analysis.
 *
 * A dispatcher reads the queued move at ctx[0]+0x1c7 and runs it; a chooser decides what to queue.
 * Ov107_FindNearestObject returns the target and writes the SQUARED distance through its out-param,
 * hence the FX_Sqrt; `d` is that one slot reused, squared distance then real gap.
 *
 * Unlike the other choosers, no target means it simply RETURNS -- it queues nothing at all.
 *
 * ctx[0x1b] < 1 selects a passive ruleset:
 *   d > 0x1000   -> move 5 (close the distance)
 *   otherwise    -> a d100: <= 70 move 15, else move 5
 *
 * Otherwise, by range:
 *   d >= 0x8000  -> move 10
 *   d < 0x3000   -> a d100 == 0 -> move 9; else a second d100 >= 20 -> nothing;
 *                   else a third d100 < 50 -> move 13, else move 12
 *   in between   -> one d100 fans out: <40 move 10, <60 move 13, <80 move 12, <99 move 11,
 *                   else move 9
 *
 * `+ (v - v)` on every RNG result is NOT a typo and must not be "simplified": RandNextScaled returns
 * long long, and that unfoldable zero is what makes mwcc emit the ROM's `add/adds r0, r0, #0`.
 * See deferred-ties.md.
 *
 * The comparison constants are the ROM's own: `<= 0x46` rather than the equivalent `< 0x47`, and
 * `>= 0x14` rather than `> 0x13` -- the other spelling flips the branch.
 */

extern int Ov107_FindNearestObject(int obj, int *outDistSq);
extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern int FX_Sqrt(int x);
extern int RandNextScaled();

void Ov282_AiPickMove(int self) {
    int *ctx;
    int *owner;
    int target;
    int d;
    int roll;

    ctx = *(int **)(self + 4);
    ctx[4] = Ov107_FindNearestObject(ctx[0], &d);
    target = ctx[4];
    if (target == 0) {
        return;
    }

    owner = (int *)ctx[0];
    d = FX_Sqrt(d) - (owner[0x20] + *(int *)(target + 0x80));

    if (ctx[0x1b] <= 0) {
        if (d <= 0x1000) {
            if (RandNextScaled(0x65) + (d - d) <= 0x46) {
                *(signed char *)(ctx[0] + 0x1c7) = 15;
                SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
                return;
            }
            *(signed char *)(ctx[0] + 0x1c7) = 5;
            SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
            return;
        }
        *(signed char *)(ctx[0] + 0x1c7) = 5;
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }

    if (d >= 0x8000) {
        *(signed char *)(ctx[0] + 0x1c7) = 10;
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }

    if (d >= 0x3000) {
        roll = RandNextScaled(0x65) + (d - d);
        if (roll < 0x28) {
            *(signed char *)(ctx[0] + 0x1c7) = 10;
            SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
            return;
        }
        if (roll < 0x3c) {
            *(signed char *)(ctx[0] + 0x1c7) = 13;
            SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
            return;
        }
        if (roll < 0x50) {
            *(signed char *)(ctx[0] + 0x1c7) = 12;
            SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
            return;
        }
        if (roll < 99) {
            *(signed char *)(ctx[0] + 0x1c7) = 11;
            SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
            return;
        }
        *(signed char *)(ctx[0] + 0x1c7) = 9;
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }

    if (RandNextScaled(0x65) + (d - d) == 0) {
        *(signed char *)(ctx[0] + 0x1c7) = 9;
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }
    if (RandNextScaled(0x65) + (d - d) >= 0x14) {
        return;
    }
    if (RandNextScaled(0x65) + (d - d) < 0x32) {
        *(signed char *)(ctx[0] + 0x1c7) = 13;
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }
    *(signed char *)(ctx[0] + 0x1c7) = 12;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
    return;
}
