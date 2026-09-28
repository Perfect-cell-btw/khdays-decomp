/* When inactive sets the active/pending bits and inserts the entity at the head of the entity
 * manager's list `nList` (func_0202b5f8, which also records the index in the node). */

extern void func_0202b5f8(int nList, void *pNode);

void Entity_Activate(unsigned char *ptr, int nList) {
    unsigned char flags = ptr[8];

    if ((flags & 2) == 0) {
        ptr[8] = flags | 0xa;
        func_0202b5f8(nList, ptr);
    }
}
