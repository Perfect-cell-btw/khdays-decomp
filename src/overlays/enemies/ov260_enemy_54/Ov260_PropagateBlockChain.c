/* Refreshes the child model, runs the object tick and copies the transform down the model chain. */

#include "game/enemy_common.h"

extern void Ov107_ProcessObjectTick(void *obj, int arg2);
struct blk11 { int w[11]; };
void Ov260_PropagateBlockChain(char *obj, int arg2) {
    Ov107_RefreshAndSelectChild((int)(*(void **)(obj + 0x428)), arg2);
    Ov107_ProcessObjectTick(obj, arg2);
    *(struct blk11 *)(*(char **)(obj + 0x41c) + 0x10) = *(struct blk11 *)(obj + 0xa0);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x418)) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x41c) + 0x10);
}
