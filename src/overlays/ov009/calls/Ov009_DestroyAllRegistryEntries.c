/* Ov009_DestroyAllRegistryEntries -- tear down every entry in the menu's active-widget list, ov008.
 * Walks the intrusive list at base+0x9660 and releases each node via Ov009_ListRemoveAndFree,
 * fetching the next link before freeing the current one. */
extern void *NNS_FndGetNextListObject(void *list, void *prev);
extern void  Ov009_ListRemoveAndFree(int node);
extern int   data_ov009_020563e4[];

void Ov009_DestroyAllRegistryEntries(void) {
    int node = (int)NNS_FndGetNextListObject((void *)(data_ov009_020563e4[1] + 0x9660), 0);
    if (node != 0) {
        int next;
        do {
            next = (int)NNS_FndGetNextListObject((void *)(data_ov009_020563e4[1] + 0x9660), (void *)node);
            Ov009_ListRemoveAndFree(node);
            node = next;
        } while (next != 0);
    }
}
