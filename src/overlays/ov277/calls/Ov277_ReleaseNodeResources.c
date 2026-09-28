extern void FreeInstanceMemory(int h);
extern void FreeAllResourceTables(int h);
extern void DestroyInstance(int h);
extern void Ov107_DestroyObject(char *self);

/* Releases everything the node owns: the three texture blocks, the three animation pairs, the
 * three own sprites and the eight sub-node sprites with their table. */
void Ov277_ReleaseNodeResources(char *self) {
    int i;
    FreeInstanceMemory(*(int *)(self + 0x400));
    FreeInstanceMemory(*(int *)(self + 0x404));
    FreeInstanceMemory(*(int *)(self + 0x408));
    FreeAllResourceTables(*(int *)(self + 0x390));
    FreeInstanceMemory(*(int *)(self + 0x390));
    FreeAllResourceTables(*(int *)(self + 0x394));
    FreeInstanceMemory(*(int *)(self + 0x394));
    FreeAllResourceTables(*(int *)(self + 0x398));
    FreeInstanceMemory(*(int *)(self + 0x398));
    DestroyInstance(*(int *)(self + 0x384));
    DestroyInstance(*(int *)(self + 0x388));
    DestroyInstance(*(int *)(self + 0x38c));
    for (i = 0; i < 8; i++) {
        DestroyInstance(*(int *)(*(int *)(self + 0x40c) + i * sizeof(long long)));
    }
    FreeInstanceMemory(*(int *)(self + 0x40c));
    Ov107_DestroyObject(self);
}
