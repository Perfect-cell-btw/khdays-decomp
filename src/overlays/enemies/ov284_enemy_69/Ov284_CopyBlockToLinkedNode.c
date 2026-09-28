/* Runs the shared object tick, then copies the action resource's transform into the linked model
 * (+0x3b4). */

extern void Ov107_ProcessObjectTick(void *obj);
struct blk11 { int w[11]; };

void Ov284_CopyBlockToLinkedNode(char *obj) {
    Ov107_ProcessObjectTick(obj);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x3a8)) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x3a4) + 4);
}
