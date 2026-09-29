/* The single-case switch is deliberate: two plain `if (...) return;` guards let mwcc
 * if-convert the second into the first (ldreq/cmpeq, 8 B short). The ROM emits two
 * separate `popne {r3,pc}` early returns, and the switch is what reproduces that. */

#include "game/engine.h"

extern void Ov009_PlaceElementByVariant(int obj, int old_value, int new_value);

void Ov009_StepSelectionBackward(int param_1) {
    int old = *(int *)param_1;
    int nv;
    switch (*(int *)(param_1 + 0x240)) {
    case 0:
        if (*(int *)(param_1 + 8) != 0) return;
        nv = old - 1;
        *(int *)param_1 = nv;
        if (nv < 0) {
            *(int *)param_1 = 2;
        }
        Ov009_PlaceElementByVariant(param_1, old, *(int *)param_1);
        PlaySound(0, 0);
        break;
    }
}
