extern void CreateRegistryEntry();
extern void Ov182_InitNodeAndRegisterHandlers(void);

void Ov182_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x88, Ov182_InitNodeAndRegisterHandlers, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
