extern void FreeAllResourceTables(char *p);
extern void DestroyInstance(int h);
extern void FreeInstanceMemory(int h);
extern void Ov107_DestroyObject(char *self);

/* Releases everything the node owns: the two animation blocks, the eight sub-node sprites and
 * their table, the two texture blocks and the two own sprites. */
void Ov273_ReleaseNodeResources(char *self) {
    int i;
    FreeAllResourceTables(self + 0x38c);
    FreeAllResourceTables(self + 0x3b0);
    for (i = 0; i < 8; i++) {
        DestroyInstance(*(int *)(*(int *)(self + 0x430) + i * sizeof(long long)));
    }
    FreeInstanceMemory(*(int *)(self + 0x430));
    FreeInstanceMemory(*(int *)(self + 0x3e0));
    FreeInstanceMemory(*(int *)(self + 0x3e4));
    DestroyInstance(*(int *)(self + 0x384));
    DestroyInstance(*(int *)(self + 0x388));
    Ov107_DestroyObject(self);
}
