extern void CreateRegistryEntry();
extern void Ov262_HoverSetup(void);

void Ov262_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x90, Ov262_HoverSetup, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
