#include "game/engine.h"

#pragma thumb on
/* Ov023_ReleaseSubPanelResource -- release the sub-panel resource in slot @+0x1a24 and clear it,
 * ov023 (ZeroHalfThenFree). */
void Ov023_ReleaseSubPanelResource(char *obj) {
    ZeroHalfThenFree(*(void **)(obj + 0x1a24));
    *(int *)(obj + 0x1a24) = 0;
}
