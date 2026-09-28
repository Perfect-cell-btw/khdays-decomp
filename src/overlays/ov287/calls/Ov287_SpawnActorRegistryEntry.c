extern void CreateRegistryEntry();
extern void Ov287_InitActorStateSlots(void);

void Ov287_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x5c, Ov287_InitActorStateSlots, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
