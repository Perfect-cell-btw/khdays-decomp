extern void FreeAllResourceTables(char *p);
extern void DestroyInstance(int h);
extern void Ov107_ActionResource_Destroy(int h);
extern void NNSi_FndDestroyDoubleList(char *list);
extern void Ov107_DestroyObject(char *self);

/* Releases everything the node owns: the two animation blocks, its two sprites, the actor pool,
 * the eight row sprites and the row list. */
void Ov254_ReleaseNodeResources(char *self) {
    int i;
    FreeAllResourceTables(self + 0x38c);
    FreeAllResourceTables(self + 0x3b0);
    DestroyInstance(*(int *)(self + 0x384));
    DestroyInstance(*(int *)(self + 0x388));
    Ov107_ActionResource_Destroy(*(int *)(self + 0x430));
    for (i = 0; i < 8; i++) {
        DestroyInstance(*(int *)(self + i * sizeof(long long) + 0x4e8));
    }
    NNSi_FndDestroyDoubleList(self + 0x34 + 0x400);
    Ov107_DestroyObject(self);
}
