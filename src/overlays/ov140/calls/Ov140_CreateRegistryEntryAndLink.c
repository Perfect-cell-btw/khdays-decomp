extern void CreateRegistryEntry();
extern void Ov140_EnterAimStateInstallCallbacks(void);

void Ov140_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x58, Ov140_EnterAimStateInstallCallbacks, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
