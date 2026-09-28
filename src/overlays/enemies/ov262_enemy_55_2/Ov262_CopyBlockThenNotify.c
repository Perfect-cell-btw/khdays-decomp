/* After Ov107_ProcessObjectTick, copies the 11-word block obj+0xa0 into the child node, then (if
 * the notify target is non-null) calls Ov002_Element_CallHook30. */

extern void Ov107_ProcessObjectTick(void *obj);
extern void Ov002_Element_CallHook30(int a, void *b);
struct blk11 { int w[11]; };
void Ov262_CopyBlockThenNotify(char *obj) {
    Ov107_ProcessObjectTick(obj);
    *(struct blk11 *)(*(char **)(obj + 0x398) + 0x10) = *(struct blk11 *)(obj + 0xa0);
    if (*(int *)(*(char **)(obj + 0x3a0)) != 0) {
        Ov002_Element_CallHook30(*(int *)(*(char **)(obj + 0x3a0)), *(char **)(obj + 0x398) + 0x20);
    }
}
