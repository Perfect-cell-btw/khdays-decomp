/* Calls the object's hook at +0x7c when it has one, with the handler pair uninstalled around the
 * call. */

#include "game/engine.h"

void invokeObjCallbackGuarded(int param_1) {
    if (*(void **)(param_1 + 0x7c) == 0) return;
    InstallHandlerPairByFlag(0);
    (*(void (**)(int))(param_1 + 0x7c))(param_1);
    InstallHandlerPairByFlag(1);
}
