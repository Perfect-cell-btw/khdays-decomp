#include "game/engine.h"

extern void Ov107_ProcessObjectTick(void *obj, int arg2);
struct blk11 { int w[11]; };
void Ov199_ResetSetupAndPropagate(char *obj, int arg2) {
    RefreshObjectCallbacks(*(void **)(obj + 0x388), arg2);
    DispatchObjectCallbacks(*(void **)(obj + 0x388), 1);
    Ov107_ProcessObjectTick(obj, arg2);
    *(struct blk11 *)(*(char **)(obj + 0x390) + 0x10) = *(struct blk11 *)(obj + 0xa0);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x38c)) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x390) + 0x10);
}
