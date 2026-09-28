extern void CreateRegistryEntry();
extern void Ov299_InitStateSlots(void);

void Ov299_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0xc, Ov299_InitStateSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
