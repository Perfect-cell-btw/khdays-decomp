extern void CreateRegistryEntry();
extern void Ov137_InitChase(void);
void Ov137_CreateAiTask(int param_1) {
    int *entry;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 100, 0x58, Ov137_InitChase, 0, &entry);
    *entry = param_1;
    entry[1] = *(int *)(*entry + 0x388);
    *(int **)(param_1 + 0x214) = entry;
}
