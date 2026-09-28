extern void Ov107_ProcessObjectTick(void *obj);
struct blk11 { int w[11]; };

void Ov253_CopyBlockToLinkedNode(char *obj) {
    Ov107_ProcessObjectTick(obj);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x3b4)) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x3ac) + 4);
}
