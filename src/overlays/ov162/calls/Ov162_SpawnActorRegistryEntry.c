extern void CreateRegistryEntry();
extern void Ov162_AiStateInit(void);

void Ov162_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x60, Ov162_AiStateInit, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
