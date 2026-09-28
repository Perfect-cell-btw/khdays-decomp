/* Creates the object's state-machine registry entry (starting in its dwell state, with an empty
 * release callback), links it back to the object and stores it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov202_EntryReleaseNoOp();
extern void Ov202_EnterRandomDwellState();

void Ov202_CreateRegistryEntryTwoCallbacks(int this_) {
    int out;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 0x64, 0x5c,
                  (int)&Ov202_EnterRandomDwellState, (int)&Ov202_EntryReleaseNoOp, &out);
    *(int *)out = this_;
    *(int *)(this_ + 0x214) = out;
}
