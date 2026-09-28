extern void CreateRegistryEntry();
extern void Ov114_InitNodeAndRegisterHandlers(void);

void Ov114_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x6c, Ov114_InitNodeAndRegisterHandlers, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
