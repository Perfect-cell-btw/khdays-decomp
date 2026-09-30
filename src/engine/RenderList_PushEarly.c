/* Push `node` onto the head of the intrusive list at
 * *(gEntityMgr + index*4 + 0x64); links prev/next and tags node[0xa].
 * Sibling of RenderList_PushMain (offset 0x64 vs 0x84); this one re-reads the
 * base pointer for the store rather than caching it. */
extern int gEntityMgr;
void RenderList_PushEarly(int index, void *node) {
    void *old = *(void **)(gEntityMgr + index * 4 + 0x64);
    if (old != 0) {
        *(void **)node = old;
        *(void **)((char *)old + 4) = node;
    }
    *(void **)(gEntityMgr + index * 4 + 0x64) = node;
    *((char *)node + 0xa) = (char)index;
}
