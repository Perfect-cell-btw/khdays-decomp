/* Attaches a node at the front of the entity's node list (+0xc). */

extern int ListPushFront();

int Entity_AttachNode(int entity, int *node) {
    return ListPushFront(entity + 0xc, node);
}
