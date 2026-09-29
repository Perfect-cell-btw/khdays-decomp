/* Tail-call ReleaseNodeResources on the sub-object at param_1+0x2c. */

#include "game/engine.h"

void Ov016_ReleaseEmbeddedNode(int param_1) {
    ReleaseNodeResources((void *)(param_1 + 0x2c));
}
