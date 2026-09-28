extern void CreateRegistryEntry();
extern void Ov123_InitNode(void);

void Ov123_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x38, Ov123_InitNode, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
