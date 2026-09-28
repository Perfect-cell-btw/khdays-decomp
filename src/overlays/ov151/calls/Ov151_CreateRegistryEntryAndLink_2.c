extern void CreateRegistryEntry();
extern void Ov151_EnterAimStateInstallCallbacks(void);

void Ov151_CreateRegistryEntryAndLink_2(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x50, Ov151_EnterAimStateInstallCallbacks, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
