/* Detaches a node from the entity's node list (+0xc). */

extern int DList_Unlink();

int Entity_DetachNode(int entity, int *node) {
    return DList_Unlink(entity + 0xc, node);
}
