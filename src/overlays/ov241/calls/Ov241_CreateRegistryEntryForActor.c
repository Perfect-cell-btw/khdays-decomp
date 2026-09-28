extern void CreateRegistryEntry();
extern void Ov241_InitNode();

void Ov241_CreateRegistryEntryForActor(int this_) {
    int out;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 0x64, 0x44, (int)&Ov241_InitNode, 0, &out);
    *(int *)out = this_;
    *(int *)(this_ + 0x214) = out;
}
