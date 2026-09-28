extern void CreateRegistryEntry();
extern void Ov261_HoverSetup(void);

void Ov261_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x90, Ov261_HoverSetup, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
