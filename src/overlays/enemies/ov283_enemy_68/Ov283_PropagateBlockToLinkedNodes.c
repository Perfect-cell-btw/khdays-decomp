/* Runs the shared object tick, then copies the actor's 44-byte transform to its linked node
 * (+0x38c) and on to that node's model (+0x388). */

extern void Ov107_ProcessObjectTick(void *);
struct blk11 { int w[11]; };

void Ov283_PropagateBlockToLinkedNodes(char *obj) {
    Ov107_ProcessObjectTick(obj);
    *(struct blk11 *)(*(char **)(obj + 0x38c) + 0x10) =
        *(struct blk11 *)(obj + 0xa0);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x388)) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x38c) + 0x10);
}
