extern unsigned int *CallocInstance(int size);

unsigned int List_InsertSorted(int list, int extra, unsigned int key) {
    unsigned int *slot;
    unsigned int prev;
    unsigned int *node = *(unsigned int **)(list + 4);
    while (node[2] <= key)
        node = (unsigned int *)node[1];
    prev = node[0];
    slot = CallocInstance(extra + 0x10);
    slot[0] = prev;
    slot[1] = (unsigned int)node;
    *(unsigned int **)(prev + 4) = slot;
    node[0] = (unsigned int)slot;
    slot[2] = key;
    slot[3] = (unsigned int)(slot + 4);
    *(int *)(list + 0x20) = *(int *)(list + 0x20) + 1;
    return slot[3];
}
