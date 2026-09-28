/* Flattens a build-list of 4-byte entries (obtained from List_First/List_Next,
 * iterating node's list at +0xb0) into a packed array allocated at node->entries,
 * records the entry count, allocates two more count-sized buffers, then destroys and
 * frees the list and clears the pointer. */
typedef struct {
    unsigned char b0, b1, b2, b3;
} Entry4;

typedef struct {
    char pad_00[0x94];
    Entry4 *entries;    /* +0x94 */
    int entryCount;     /* +0x98 */
    void *field_9c;      /* +0x9c: count-sized buffer */
    void *field_a0;      /* +0xa0: count-sized buffer */
    char pad_a4[0xb0 - 0xa4];
    int list;            /* +0xb0 */
} Node;

extern void *CallocInstance(unsigned int size);
extern int List_First(int list);
extern int List_Next(int list);
extern void NNSi_FndDestroyDoubleList(void *list);
extern void FreeInstanceMemory(void *object);

void Ov107_ContainerNode_Finalize(int nodeAddr) {
    Node *node = (Node *)nodeAddr;
    int count = *(int *)(node->list + 0x20);
    int i;
    unsigned char *p;

    node->entryCount = count;
    node->entries = (Entry4 *)CallocInstance(count << 2);
    i = 0;
    p = (unsigned char *)List_First(node->list);
    while (p != 0) {
        node->entries[i] = *(Entry4 *)p;
        i++;
        p = (unsigned char *)List_Next(node->list);
    }
    node->field_9c = CallocInstance(node->entryCount);
    node->field_a0 = CallocInstance(node->entryCount);
    NNSi_FndDestroyDoubleList((void *)node->list);
    FreeInstanceMemory((void *)node->list);
    node->list = 0;
}
