extern void CreateRegistryEntry(int, int, int, void *, int, int **);
extern void Ov131_AiStateInit(void);

void Ov131_SpawnActorRegistryEntry(int param_1, int param_2, int param_3, int param_4) {
    int *entry;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 100, 0x60, Ov131_AiStateInit, 0, &entry);
    *entry = param_1;
    entry[1] = *(int *)(*entry + 900);
    *(int **)(param_1 + 0x214) = entry;
}
