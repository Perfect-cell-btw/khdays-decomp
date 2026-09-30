/* After Ov107_ProcessObjectTick, copies the 11-word block obj+0xa0 into two linked nodes. */

extern void Ov107_ProcessObjectTick(void *obj, int);
struct blk11 { int w[11]; };
void Ov286_CopyBlockToTwoNodes(char *obj, int delta) {
    Ov107_ProcessObjectTick(obj, delta);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x38c)) + 0x10) = *(struct blk11 *)(obj + 0xa0);
    *(struct blk11 *)(*(char **)(obj + 0x388) + 0x10) = *(struct blk11 *)(obj + 0xa0);
}
