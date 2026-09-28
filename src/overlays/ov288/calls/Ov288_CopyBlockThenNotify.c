extern void Ov107_ProcessObjectTick(void *obj);
extern void Ov002_Element_CallHook30(int a, void *b);
struct blk11 { int w[11]; };
void Ov288_CopyBlockThenNotify(char *obj) {
    Ov107_ProcessObjectTick(obj);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x388)) + 0x10) = *(struct blk11 *)(obj + 0xa0);
    if (*(int *)(obj + 0x390) != 0) {
        Ov002_Element_CallHook30(*(int *)(obj + 0x390), obj + 0xb0);
    }
}
