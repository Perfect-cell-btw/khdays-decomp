extern void FreeAllResourceTables(void *p);
extern void DestroyInstance(int handle);
extern void Ov107_ActionResource_Destroy(int handle);
extern void FreeInstanceMemory(void *p);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: both animation binders (clearing their back-pointers), the three models, the
 * effect handle, then the 19 entries of the attachment table before freeing it. */
void Ov237_Actor_Destroy(char *self) {
    int i;
    FreeAllResourceTables(self + 0x388);
    *(int *)(self + 0x394) = 0;
    FreeAllResourceTables(self + 0x3b0);
    *(int *)(self + 0x3bc) = 0;
    DestroyInstance(*(int *)(self + 0x384));
    DestroyInstance(*(int *)(self + 0x3ac));
    DestroyInstance(*(int *)(self + 0x3e4));
    Ov107_ActionResource_Destroy(*(int *)(self + 0x3d8));
    for (i = 0; i < 0x13; i++) {
        DestroyInstance(*(int *)(*(char **)(self + 0x490) + i * sizeof(long long)));
    }
    FreeInstanceMemory(*(void **)(self + 0x490));
    Ov107_DestroyObject(self);
}
