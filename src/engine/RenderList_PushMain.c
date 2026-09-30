/* Push `node` onto the head of the intrusive list at
 * *(gEntityMgr + index*4 + 0x84); links prev/next and tags node[0xa]. */
extern int gEntityMgr;
void RenderList_PushMain(int index, void *node) {
    int base = gEntityMgr;
    void *old = *(void **)(base + index * 4 + 0x84);
    if (old != 0) {
        *(void **)node = old;
        *(void **)((char *)old + 4) = node;
    }
    *(void **)(base + index * 4 + 0x84) = node;
    *((char *)node + 0xa) = (char)index;
}
