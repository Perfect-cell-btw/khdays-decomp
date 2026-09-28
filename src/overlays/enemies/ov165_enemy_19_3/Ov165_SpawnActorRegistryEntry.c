extern void CreateRegistryEntry();
extern void Ov165_EnterRandomDwellState(void);

void Ov165_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x70, Ov165_EnterRandomDwellState, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
