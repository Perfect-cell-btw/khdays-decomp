extern void CreateRegistryEntry();
extern void Ov150_stInitSlotsFlags6(void);

void Ov150_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x4c, Ov150_stInitSlotsFlags6, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
