/* Removes and frees every entry of the menu's list. */

extern int NNS_FndGetNextListObject();
extern void Ov025_ListRemoveAndFree();
extern int data_ov025_020b5744;

void Ov025_DestroyAllRegistryEntries(void) {
    int e = NNS_FndGetNextListObject((void *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x9660), 0);
    if (e != 0) {
        do {
            int next = NNS_FndGetNextListObject((void *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x9660), e);
            Ov025_ListRemoveAndFree(e);
            e = next;
        } while (e != 0);
    }
}
