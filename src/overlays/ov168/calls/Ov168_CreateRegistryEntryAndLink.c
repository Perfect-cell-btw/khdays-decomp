/* Create a sub-object via CreateRegistryEntry (kind 0x64/0x2c, handler Ov168_stateInitClearSlots),
 * back-link it to the owner, and store it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov168_stateInitClearSlots(void);

void Ov168_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x2c, Ov168_stateInitClearSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
