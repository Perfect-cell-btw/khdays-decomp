/* Refreshes the child selector, runs the shared object tick and copies the actor's transform to its
 * linked model (+0x390). */

#include "game/enemy_common.h"

extern void Ov107_ProcessObjectTick(void *obj, int arg2);
struct blk11 { int w[11]; };

void Ov144_SetupAndPropagateBlock(char *obj, int arg2) {
    Ov107_RefreshAndSelectChild((int)(*(void **)(obj + 0x394)), arg2);
    Ov107_ProcessObjectTick(obj, arg2);
    *(struct blk11 *)(*(char **)(obj + 0x390) + 0x10) =
        *(struct blk11 *)(obj + 0xa0);
}
