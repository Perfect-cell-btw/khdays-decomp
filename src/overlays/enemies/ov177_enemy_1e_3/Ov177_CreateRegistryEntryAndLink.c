/* Spawn a child object via CreateRegistryEntry, link back to owner, store at +0x214. */

extern void CreateRegistryEntry();
extern void Ov177_stateInitClearSlots(void);

void Ov177_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x24, Ov177_stateInitClearSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
