extern void CreateRegistryEntry();
extern void Ov154_InitNode(void);

void Ov154_CreateRegistryEntryAndLink_2(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x28, Ov154_InitNode, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
