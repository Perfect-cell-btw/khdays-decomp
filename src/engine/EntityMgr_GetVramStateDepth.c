/* Returns the depth of the entity manager's VRAM state stack (+0xa4d0), pushed by
 * EntityMgr_PushVramState. */

extern int gEntityMgr;

int EntityMgr_GetVramStateDepth(void) {
    return *(unsigned char *)(*(int *)&gEntityMgr + 0xa4d0);
}
