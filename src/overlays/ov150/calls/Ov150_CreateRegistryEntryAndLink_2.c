/* Spawn a child object via CreateRegistryEntry (callback Ov150_stateInitClearSlots), link it back
 * to this object and store it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov150_stateInitClearSlots(void);

void Ov150_CreateRegistryEntryAndLink_2(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x28, Ov150_stateInitClearSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
