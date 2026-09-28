extern void Ov107_ProcessObjectTick(void *obj);
struct blk11 { int w[11]; };
void Ov295_CopyPoseBlockToTwoNodes(char *obj) {
    Ov107_ProcessObjectTick(obj);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x388)) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x384) + 0x30);
    *(struct blk11 *)(*(char **)(obj + 0x390) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x384) + 0x30);
}
