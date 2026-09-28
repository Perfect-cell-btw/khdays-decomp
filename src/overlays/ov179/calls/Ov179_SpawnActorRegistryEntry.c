extern void CreateRegistryEntry();
extern void Ov179_stateInitClearSlots(void);

void Ov179_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x14, Ov179_stateInitClearSlots, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
