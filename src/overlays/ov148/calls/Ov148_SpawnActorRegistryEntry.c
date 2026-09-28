extern void CreateRegistryEntry();
extern void Ov148_InitReactionSlots(void);

void Ov148_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x48, Ov148_InitReactionSlots, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
