/* ov thin tail-call veneer: forwards to ReleaseNodeResources with a computed/first arg. */

#include "game/engine.h"

void Ov017_tailDispatch(char *p) {
    ReleaseNodeResources(p + 0x2c);
}
