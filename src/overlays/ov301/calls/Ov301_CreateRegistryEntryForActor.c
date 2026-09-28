extern void CreateRegistryEntry();
extern void Ov301_InitStateSlots();

void Ov301_CreateRegistryEntryForActor(int this_) {
    int out;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 0x64, 0x4c, (int)&Ov301_InitStateSlots, 0, &out);
    *(int *)out = this_;
    *(int *)(this_ + 0x214) = out;
}
