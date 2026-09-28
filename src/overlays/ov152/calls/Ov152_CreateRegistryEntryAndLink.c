extern void CreateRegistryEntry();
extern void Ov152_stateInitClearSlots(void);

void Ov152_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x3c, Ov152_stateInitClearSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
