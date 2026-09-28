extern void CreateRegistryEntry();
extern void Ov189_InitReactionSlots(void);

void Ov189_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x40, Ov189_InitReactionSlots, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
