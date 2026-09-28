extern void Ov107_RefreshAndSelectChild(void *p);
extern void Ov107_ProcessObjectTick(void *obj, int arg2);
struct blk11 { int w[11]; };
void Ov130_PropagateBlockChain(char *obj, int arg2) {
    Ov107_RefreshAndSelectChild(*(void **)(obj + 0x390));
    Ov107_ProcessObjectTick(obj, arg2);
    *(struct blk11 *)(*(char **)(obj + 0x38c) + 0x10) = *(struct blk11 *)(obj + 0xa0);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x388)) + 0x10) =
        *(struct blk11 *)(*(char **)(obj + 0x38c) + 0x10);
}
