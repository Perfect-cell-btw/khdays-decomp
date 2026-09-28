extern void CreateRegistryEntry();
extern void Ov298_InitStates(void);

void Ov298_CreateNodeRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x98, Ov298_InitStates, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
