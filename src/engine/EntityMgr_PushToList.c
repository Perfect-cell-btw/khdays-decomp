/* Pushes a node on the front of the entity manager's indexed list (+0xa4) and records the list
 * index in the node. */

extern int data_0204c208;

void EntityMgr_PushToList(int list, int *node) {
    int base = data_0204c208;
    int head = *(int *)(base + list * 4 + 0xa4);
    if (head != 0) {
        *node = head;
        *(int **)(head + 4) = node;
    }
    *(int **)(base + list * 4 + 0xa4) = node;
    *(char *)((int)node + 10) = (char)list;
}
