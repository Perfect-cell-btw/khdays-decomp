extern void CreateRegistryEntry();
extern void Ov243_InitNode(void);

void Ov243_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x44, Ov243_InitNode, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
