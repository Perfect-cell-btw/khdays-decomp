extern void FreeAllResourceTables(int h);
extern void FreeInstanceMemory(int h);
extern void DestroyInstance(int h);
extern void Ov107_DestroyObject(char *self);

/* Releases everything the node owns: the two animation pairs, the three sprite handles, the two
 * texture blocks, the two entries of the sub-node table and the table itself. */
void Ov253_ReleaseNodeResources(char *self) {
    int i;
    FreeAllResourceTables(*(int *)(self + 0x388));
    FreeInstanceMemory(*(int *)(self + 0x388));
    FreeAllResourceTables(*(int *)(self + 0x390));
    FreeInstanceMemory(*(int *)(self + 0x390));
    DestroyInstance(*(int *)(self + 0x384));
    DestroyInstance(*(int *)(self + 0x38c));
    DestroyInstance(*(int *)(self + 0x3a8));
    FreeInstanceMemory(*(int *)(self + 0x458));
    FreeInstanceMemory(*(int *)(self + 0x45c));
    for (i = 0; i < 2; i++) {
        DestroyInstance(*(int *)(*(int *)(self + 0x468) + i * sizeof(long long)));
    }
    FreeInstanceMemory(*(int *)(self + 0x468));
    Ov107_DestroyObject(self);
}
