extern void CreateRegistryEntry();
extern void Ov144_InitAimStateSlots(void);

void Ov144_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x54, Ov144_InitAimStateSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
