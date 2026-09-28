extern void CreateRegistryEntry();
extern void Ov177_stateInitTransformSlots(void);
void Ov177_registryCreateEntry(int param_1, int param_2, int param_3, int param_4) {
    int *local_10;
    int uStack_c = param_4;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 100, 0x8c, Ov177_stateInitTransformSlots, 0, &local_10);
    *local_10 = param_1;
    local_10[1] = *(int *)(*local_10 + 0x384);
    *(int **)(param_1 + 0x214) = local_10;
}
