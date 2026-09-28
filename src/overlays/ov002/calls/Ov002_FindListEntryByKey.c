/* Find the first entry in the context's list at +0x10 whose leading byte matches
 * the key. Returns it, or 0. Sibling of Ov002_FindFreeListEntry, which searches the
 * same list for the 0xff empty marker. */
extern void *NNS_FndGetNextListObject(void *list, void *from);

extern char *data_ov002_0207f61c;

void *Ov002_FindListEntryByKey(int key) {
    char *ctx = data_ov002_0207f61c;
    unsigned char *node = NNS_FndGetNextListObject(ctx + 0x10, 0);

    while (node != 0) {
        if (*node == key) {
            break;
        }
        node = NNS_FndGetNextListObject(ctx + 0x10, node);
    }

    return node;
}
