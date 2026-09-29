/* Record `a`'s entry-count cap: 6 plus twice a per-record lookup value (param 0x5a
 * into Slot_EvalPackedParam), clamped to 18 -- the stride-4 array at +0xba only has room
 * for 18 entries. */

#include "game/engine.h"

int Slot_CalcRangeCap18(int a) {
    unsigned char n = 6;
    n += Slot_EvalPackedParam(a, 0x5a) * 2;
    if (n > 18)
        n = 18;
    return n;
}
