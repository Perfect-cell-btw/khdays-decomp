/* After refreshing (Ov107_RefreshAndSelectChild/6980), copies obj+0xa0 into the child node then
 * propagates the child into the linked node. Two chained 11-word block copies. */

extern void Ov107_ProcessObjectTick(void *obj);
struct blk11 { int w[11]; };
void Ov297_PropagateBlockChain(char *obj) {
    Ov107_ProcessObjectTick(obj);
    *(struct blk11 *)(*(char **)(obj + 0x390) + 0x10) = *(struct blk11 *)(obj + 0xa0);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x38c)) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x390) + 0x10);
}
