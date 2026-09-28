extern void CreateRegistryEntry();
extern void Ov170_stateInitClearSlots(void);

void Ov170_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x4c, Ov170_stateInitClearSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
