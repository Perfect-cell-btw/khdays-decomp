/* Release the resource held at param_1+0x2c (if any) via ReleaseNodeResources. */

#include "game/engine.h"

void Ov015_Pickup_ReleaseNode(int param_1) {
    if (*(void **)(param_1 + 0x2c) != 0) {
        ReleaseNodeResources(*(void **)(param_1 + 0x2c));
    }
}
