extern void CreateRegistryEntry();
extern void Ov139_EnterAimStateInstallCallbacks(void);

void Ov139_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x58, Ov139_EnterAimStateInstallCallbacks, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
