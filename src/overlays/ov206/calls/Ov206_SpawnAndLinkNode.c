/* Spawn a size-8 registry entry (CreateRegistryEntry, cbs ccc0/cc3c) into *entry, then link it:
 * entry[0]=self, entry[1]=self's active node (**(self->f3e0)), stamp that node's +0x6c with
 * the ccb78 handler and back-link it to the entry at +0x84. */
extern int CreateRegistryEntry(int list, int a, int b, void *cb2, void *cb1, int **out);
extern void Ov206_ResetEntryMarkDirty(void);
extern void Ov206_ResetRigTracks(void);
extern void Ov206_RenderAtOwnerNode(void);
int Ov206_SpawnAndLinkNode(int param_1) {
    int *entry;
    int spawn = CreateRegistryEntry(*(int *)(param_1 + 0x3c), 100, 8,
                              &Ov206_ResetRigTracks, &Ov206_ResetEntryMarkDirty, &entry);
    entry[0] = param_1;
    entry[1] = **(int **)(*entry + 0x3e0);
    *(int *)(entry[1] + 0x6c) = (int)&Ov206_RenderAtOwnerNode;
    *(int **)(entry[1] + 0x84) = entry;
    return spawn;
}
