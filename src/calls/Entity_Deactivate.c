/* When active clears the active/pending bits and releases the entity. */

extern void EntityMgr_UnlinkFromListC(void *ptr);

void Entity_Deactivate(unsigned char *ptr) {
    unsigned char flags = ptr[8];

    if (flags & 2) {
        ptr[8] = flags & ~0xa;
        EntityMgr_UnlinkFromListC(ptr);
    }
}
