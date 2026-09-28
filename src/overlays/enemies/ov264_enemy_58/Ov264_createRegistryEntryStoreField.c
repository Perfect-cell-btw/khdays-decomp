extern void CreateRegistryEntry(int a, int b, int c, void *cb, int e5, int **out);
extern void Ov264_stEnterInstallTickHandler(void);

int *Ov264_createRegistryEntryStoreField(int param_1, int param_2, int param_3, int param_4) {
    int *e;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 8, Ov264_stEnterInstallTickHandler, 0, &e);
    *e = *(int *)(param_1 + 0x3c4);
    return e;
}
