extern int Record_ReleaseSlot(void *ptr);
extern int FreeNodeAndChildLists(void *ptr);

int DispatchByNodeKind(int **ptr) {
    unsigned short kind = *(unsigned short *)((char *)ptr[0] + 2);

    if (kind < 0x21) {
        if (kind == 0x16) {
            return Record_ReleaseSlot(ptr);
        }

        return FreeNodeAndChildLists(ptr);
    }

    return 0;
}
