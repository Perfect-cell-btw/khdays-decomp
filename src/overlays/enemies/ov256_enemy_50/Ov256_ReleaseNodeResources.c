extern void FreeAllResourceTables(char *p);
extern void DestroyInstance(int h);
extern void Ov107_ActionResource_Destroy(int h);
extern void Ov107_DestroyObject(char *self);

/* Releases everything the node owns: the two animation blocks (clearing their handles), the
 * seven fixed sprites, the actor pool and up to sixteen row sprites. */
void Ov256_ReleaseNodeResources(char *self) {
    int i;
    FreeAllResourceTables(self + 0x388);
    *(int *)(self + 0x394) = 0;
    FreeAllResourceTables(self + 0x3b0);
    *(int *)(self + 0x3bc) = 0;
    DestroyInstance(*(int *)(self + 0x384));
    DestroyInstance(*(int *)(self + 0x3ac));
    DestroyInstance(*(int *)(self + 0x3d4));
    DestroyInstance(*(int *)(self + 0x3e0));
    DestroyInstance(*(int *)(self + 0x3ec));
    DestroyInstance(*(int *)(self + 0x3f8));
    DestroyInstance(*(int *)(self + 0x404));
    Ov107_ActionResource_Destroy(*(int *)(self + 0x450));
    for (i = 0; i < 0x10; i++) {
        int h = *(int *)(self + i * sizeof(long long) + 0x46c);
        if (h != 0) {
            DestroyInstance(h);
        }
    }
    Ov107_DestroyObject(self);
}
