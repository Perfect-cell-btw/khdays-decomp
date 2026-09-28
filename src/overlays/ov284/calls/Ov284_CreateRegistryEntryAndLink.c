extern void CreateRegistryEntry();
extern void Ov284_SetupActorNodeAndStateSlots(void);

void Ov284_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x28, Ov284_SetupActorNodeAndStateSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
