extern void CreateRegistryEntry();
extern void Ov254_stateInitClearSlots(void);
void Ov254_Pillar_CreateAiTask(int param_1) {
    int *entry;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 100, 0x24, Ov254_stateInitClearSlots, 0, &entry);
    *entry = param_1;
    entry[1] = *(int *)(*entry + 0x384);
    *(int **)(param_1 + 0x214) = entry;
}
