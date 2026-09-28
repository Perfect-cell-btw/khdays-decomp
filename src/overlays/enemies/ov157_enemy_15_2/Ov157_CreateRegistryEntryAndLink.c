extern void CreateRegistryEntry();
extern void Ov157_stInitSlotsFlags6B(void);

void Ov157_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x3c, Ov157_stInitSlotsFlags6B, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
