/* Runs the shared object tick, then copies the action resource's transform into the linked model
 * (+0x3b4). */

extern void Ov107_ProcessObjectTick(void *obj, int);
struct blk11 { int w[11]; };

void Ov253_CopyBlockToLinkedNode(char *obj, int delta) {
    Ov107_ProcessObjectTick(obj, delta);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x3b4)) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x3ac) + 4);
}
