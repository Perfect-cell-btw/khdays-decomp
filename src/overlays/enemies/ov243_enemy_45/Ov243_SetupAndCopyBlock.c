/* After Ov107_RefreshAndSelectChild + Ov107_ProcessObjectTick, copies the 11-word block obj+0xa0
 * into the child node (single copy). */

extern void Ov107_RefreshAndSelectChild(void *p, int arg1);
extern void Ov107_ProcessObjectTick(void *obj, int arg2);
struct blk11 { int w[11]; };
void Ov243_SetupAndCopyBlock(char *obj, int arg2) {
    Ov107_RefreshAndSelectChild(*(void **)(obj + 0x390), arg2);
    Ov107_ProcessObjectTick(obj, arg2);
    *(struct blk11 *)(*(char **)(obj + 0x38c) + 0x10) = *(struct blk11 *)(obj + 0xa0);
}
