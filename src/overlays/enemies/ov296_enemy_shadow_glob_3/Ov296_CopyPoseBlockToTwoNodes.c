/* After Ov107_ProcessObjectTick, copies the 11-word pose block (src +0x30) into two linked nodes.
 */

extern void Ov107_ProcessObjectTick(void *obj, int);
struct blk11 { int w[11]; };
void Ov296_CopyPoseBlockToTwoNodes(char *obj, int delta) {
    Ov107_ProcessObjectTick(obj, delta);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x388)) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x384) + 0x30);
    *(struct blk11 *)(*(char **)(obj + 0x390) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x384) + 0x30);
}
