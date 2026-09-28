extern void Ov107_ProcessObjectTick(void *obj);
struct blk11 { int w[11]; };
void Ov152_CopyBlockToTwoNodes(char *obj) {
    Ov107_ProcessObjectTick(obj);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x388)) + 0x10) = *(struct blk11 *)(obj + 0xa0);
    *(struct blk11 *)(*(char **)(obj + 0x3a4) + 0x10) = *(struct blk11 *)(obj + 0xa0);
}
