/* ⚠ The `+ (v - v)` terms are deliberate and `v` is deliberately uninitialised: they are
 * the documented crack for RandNextScaled's copy artifact (`adds r0,r0,#0` when the result
 * is tested, `add r0,r0,#0` when it is stored). Both forms appear here, one of each.
 * The ternary is `!= 0 ? -1 : 1`, not `== 0 ? 1 : -1` -- the arm order decides which of
 * mvnne/moveq comes first. */

#include "game/enemy_common.h"
#include "game/engine.h"

extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov133_StrafeThenReact(void);

void Ov133_PickRandomSpinDirection(int *self) {
    int v;
    int *obj = (int *)self[1];

    obj[5] = *(int *)(self[0] + 0x2c) * 0x1e / 10;
    *(signed char *)((int)obj + 0x5c) = RandNextScaled(2) + (v - v) != 0 ? -1 : 1;
    obj[0xf] = RandNextScaled(0x81) + (v - v);
    Ov107_PostTagUpdate((Actor *)(*obj), 1, 1);
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), &Ov133_StrafeThenReact);
}
