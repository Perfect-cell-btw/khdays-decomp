/* Loads the default projection (fovy sin/cos, aspect, near 1.0, far 1000.0) and clears the camera
 * offsets. */

#include "game/engine.h"

void CamAnim_ResetProjection(int *ptr) {
    Projection_LoadDefaults(ptr + 4);
    ptr[0x10 / 4] = 0x5fe;
    ptr[0x14 / 4] = 0xed6;
    ptr[0x24 / 4] = 0;
    ptr[0x28 / 4] = 0;
    ptr[0x2c / 4] = 0;
    ptr[0x30 / 4] = 0;
    ptr[0x34 / 4] = 0;
    ptr[0x38 / 4] = 0x1000;
    ptr[0x1c / 4] = 0x1000;
    ptr[0x20 / 4] = 0x3e8000;
    ptr[0x40 / 4] = 0;
    ptr[0x3c / 4] = 0;
    ptr[0x44 / 4] = -0x1000;
}
