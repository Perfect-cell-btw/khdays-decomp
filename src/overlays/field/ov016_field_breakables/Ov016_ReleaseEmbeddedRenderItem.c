/* Tail-call Render_ReleaseNodeItem on the sub-object at param_1+0x2c. */

#include "game/engine.h"

void Ov016_ReleaseEmbeddedRenderItem(int param_1) {
    Render_ReleaseNodeItem((void *)(param_1 + 0x2c));
}
