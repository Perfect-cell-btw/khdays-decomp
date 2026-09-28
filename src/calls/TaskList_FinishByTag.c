extern unsigned char *List_First(void *ptr);
extern unsigned char *List_Next(void *ptr);

int TaskList_FinishByTag(void *ptr, int value) {
    unsigned char *node;

    if (value == 0) {
        return 0;
    }

    node = List_First(ptr);
    while (node != 0) {
        if (*(int *)(node + 0x1c) == value) {
            *(int *)(node + 0x24) = 1;
            return 1;
        }

        node = List_Next(ptr);
    }

    return 0;
}
