/* Unlinks a node from a doubly linked list (moving the list head when it is the head) and clears
 * its links. */

void DList_UnlinkAndClear(int *head, int *node) {
    if (node == (int *)*head) *head = node[1];
    if ((int *)node[1] != (int *)0) *(int *)node[1] = *node;
    if (*node != 0) *(int *)(*node + 4) = node[1];
    *node = 0;
    node[1] = 0;
}
