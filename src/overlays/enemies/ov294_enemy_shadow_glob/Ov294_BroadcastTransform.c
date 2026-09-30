/* Runs the object tick and copies its transform to its two models. */

extern void Ov107_ProcessObjectTick(void *obj, int);
struct blk11 { int w[11]; };
void Ov294_BroadcastTransform(char *obj, int delta) {
    Ov107_ProcessObjectTick(obj, delta);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x388)) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x384) + 0x30);
    *(struct blk11 *)(*(char **)(obj + 0x390) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x384) + 0x30);
}
