extern void CreateRegistryEntry();
extern void Ov256_StartBrain(void);
void Ov256_CreateAiTask(int param_1) {
    int *entry;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 100, 0xb4, Ov256_StartBrain, 0, &entry);
    *entry = param_1;
    entry[1] = *(int *)(*entry + 0x384);
    entry[2] = *(int *)(*entry + 0x3ac);
    *(int **)(param_1 + 0x214) = entry;
}
