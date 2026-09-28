extern void CreateRegistryEntry();
extern void Ov203_EntryReleaseNoOp();
extern void Ov203_EnterRandomDwellState();

void Ov203_CreateRegistryEntryTwoCallbacks(int this_) {
    int out;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 0x64, 0x5c,
                  (int)&Ov203_EnterRandomDwellState, (int)&Ov203_EntryReleaseNoOp, &out);
    *(int *)out = this_;
    *(int *)(this_ + 0x214) = out;
}
