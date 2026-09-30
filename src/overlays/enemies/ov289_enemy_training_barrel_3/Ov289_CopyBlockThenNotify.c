/* After Ov107_ProcessObjectTick, copies the 11-word block obj+0xa0 into the child node, then (if
 * the notify target is non-null) calls Ov002_Element_CallHook30. */

extern void Ov107_ProcessObjectTick(void *obj, int);
extern void Ov002_Element_CallHook30(int a, void *b);
struct blk11 { int w[11]; };
void Ov289_CopyBlockThenNotify(char *obj, int delta) {
    Ov107_ProcessObjectTick(obj, delta);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x388)) + 0x10) = *(struct blk11 *)(obj + 0xa0);
    if (*(int *)(obj + 0x390) != 0) {
        Ov002_Element_CallHook30(*(int *)(obj + 0x390), obj + 0xb0);
    }
}
