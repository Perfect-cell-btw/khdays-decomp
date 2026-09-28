/* Marks the owner's manager dirty (bit 1 of +0x5c) and clears the word the entry (+0x3e0) holds at
 * +4. */

void Ov274_ResetEntryMarkDirty(char *obj) {
    char *node = *(char **)(obj + 4);
    char *mgr = *(char **)(node + 4);
    *(int *)(mgr + 0x5c) |= 2;
    *(int *)(*(char **)(*(char **)node + 0x3e0) + 4) = 0;
}
