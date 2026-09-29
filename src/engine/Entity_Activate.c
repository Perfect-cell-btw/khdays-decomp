/* When inactive sets the active/pending bits and inserts the entity at the head of the entity
 * manager's list `nList` (EntityMgr_PushToList, which also records the index in the node). */

extern void EntityMgr_PushToList(int nList, void *pNode);

void Entity_Activate(unsigned char *ptr, int nList) {
    unsigned char flags = ptr[8];

    if ((flags & 2) == 0) {
        ptr[8] = flags | 0xa;
        EntityMgr_PushToList(nList, ptr);
    }
}
