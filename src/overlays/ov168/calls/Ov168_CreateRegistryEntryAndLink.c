extern void CreateRegistryEntry();
extern void Ov168_stateInitClearSlots(void);

void Ov168_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x2c, Ov168_stateInitClearSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
