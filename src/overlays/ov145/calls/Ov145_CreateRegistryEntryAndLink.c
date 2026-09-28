extern void CreateRegistryEntry();
extern void Ov145_InitAimStateSlots(void);

void Ov145_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x54, Ov145_InitAimStateSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
