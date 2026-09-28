extern void CreateRegistryEntry();
extern void Ov151_stateInitClearSlots(void);

void Ov151_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x3c, Ov151_stateInitClearSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
