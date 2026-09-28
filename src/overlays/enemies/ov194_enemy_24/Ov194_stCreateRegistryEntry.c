extern void CreateRegistryEntry();
extern void Ov194_stInitSlotsFlags6C(void);

void Ov194_stCreateRegistryEntry(int param_1) {
    int *local_10;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x58, Ov194_stInitSlotsFlags6C, 0, &local_10);
    *local_10 = param_1;
    local_10[1] = *(int *)(*local_10 + 0x384);
    *(int **)(param_1 + 0x214) = local_10;
}
