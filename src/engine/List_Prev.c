/* Continues a backward iteration: returns the previous element, or NULL at the start. */

struct Node {
    char pad[0xc];
    void *data;
};

struct List {
    char pad[0x24];
    struct Node *cur;
};

void *List_Prev(struct List *list)
{
    struct Node *n = list->cur;
    n = *(struct Node **)n;
    list->cur = n;
    if (n == (struct Node *)list)
        return 0;
    return n->data;
}
