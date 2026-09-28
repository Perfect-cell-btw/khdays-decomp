extern void CreateRegistryEntry();
extern void Ov245_stateInitClearSlots_4(void);
void Ov245_CreateNodeRegistryEntry(int param_1) {
    int *entry;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 100, 0x50, Ov245_stateInitClearSlots_4, 0, &entry);
    *entry = param_1;
    entry[1] = *(int *)(*entry + 0x9c);
    *(int **)(param_1 + 0x214) = entry;
}
