/* Marks the manager dirty and clears the actor's field at +0x5b8. */

void Ov258_ResetEntryMarkDirty(char *obj) {
    char *node = *(char **)(obj + 4);
    char *mgr = *(char **)(node + 4);
    *(int *)(mgr + 0x5c) |= 2;
    *(int *)(*(char **)node + 0x5b8) = 0;
}
