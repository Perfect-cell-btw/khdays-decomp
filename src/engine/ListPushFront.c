/* Pushes a node at the front of a doubly linked list. */

void ListPushFront(int *head, int *node)
{
    node[1] = 0;
    node[0] = *head;
    if (*head != 0)
        *(int *)(*head + 4) = (int)node;
    *head = (int)node;
}
