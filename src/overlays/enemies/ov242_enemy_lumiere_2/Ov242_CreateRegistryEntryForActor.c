/* Creates the object's state-machine registry entry (starting in its init state), links it back to
 * the object and stores it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov242_InitNode();

void Ov242_CreateRegistryEntryForActor(int this_) {
    int out;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 0x64, 0x44, (int)&Ov242_InitNode, 0, &out);
    *(int *)out = this_;
    *(int *)(this_ + 0x214) = out;
}
