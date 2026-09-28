/* Refreshes the child selector, runs the shared object tick and copies the actor's transform to its
 * linked model (+0x390). */

extern void Ov107_RefreshAndSelectChild(void *p);
extern void Ov107_ProcessObjectTick(void *obj, int arg2);
struct blk11 { int w[11]; };

void Ov145_SetupAndPropagateBlock(char *obj, int arg2) {
    Ov107_RefreshAndSelectChild(*(void **)(obj + 0x394));
    Ov107_ProcessObjectTick(obj, arg2);
    *(struct blk11 *)(*(char **)(obj + 0x390) + 0x10) =
        *(struct blk11 *)(obj + 0xa0);
}
