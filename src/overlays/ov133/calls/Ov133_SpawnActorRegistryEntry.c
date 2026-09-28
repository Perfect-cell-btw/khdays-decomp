extern void CreateRegistryEntry();
extern void Ov133_AiStateInit(void);

void Ov133_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x60, Ov133_AiStateInit, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
