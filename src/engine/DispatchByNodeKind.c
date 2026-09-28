/* Read the kind halfword at obj[0]+2 and dispatch: kind 0x16 goes to Record_ReleaseSlot, any other
 * kind below 0x21 to FreeNodeAndChildLists, and 0x21 or above returns 0. */

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
