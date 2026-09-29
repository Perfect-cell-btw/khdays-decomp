/* Returns the depth of the entity manager's VRAM state stack (+0xa4d0), pushed by
 * EntityMgr_PushVramState. */

extern int data_0204c208;

int EntityMgr_GetVramStateDepth(void) {
    return *(unsigned char *)(*(int *)&data_0204c208 + 0xa4d0);
}
