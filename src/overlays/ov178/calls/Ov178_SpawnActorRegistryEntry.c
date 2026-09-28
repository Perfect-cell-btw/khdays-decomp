extern void CreateRegistryEntry();
extern void Ov178_stateInitClearSlots(void);

void Ov178_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x14, Ov178_stateInitClearSlots, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
