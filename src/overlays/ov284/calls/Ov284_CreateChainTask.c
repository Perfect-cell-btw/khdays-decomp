extern int CreateRegistryEntry(int owner, int a, int b, void *step, void *done, int **out);
extern void Ov284_LayoutChain(void);
extern void Ov284_ResetEntryList(char *obj);

int Ov284_CreateChainTask(int obj) {
    int *out;
    int r = CreateRegistryEntry(*(int *)(obj + 0x3c), 0x64, 8, (void *)Ov284_LayoutChain,
                          (void *)Ov284_ResetEntryList, &out);
    out[0] = obj;
    out[1] = *(int *)(obj + 0x3ac);
    *(int *)(out[1] + 0x5c) &= ~2;
    return r;
}
