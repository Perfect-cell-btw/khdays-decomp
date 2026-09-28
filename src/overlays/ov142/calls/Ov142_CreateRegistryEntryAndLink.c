extern void CreateRegistryEntry();
extern void Ov142_stInitSlotsFlags6(void);

void Ov142_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x4c, Ov142_stInitSlotsFlags6, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
