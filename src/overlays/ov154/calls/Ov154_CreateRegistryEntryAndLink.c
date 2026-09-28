/* Spawn a child object via CreateRegistryEntry (callback Ov154_stateInitClearSlots), link it back
 * to this object and store it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov154_stateInitClearSlots(void);

void Ov154_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x28, Ov154_stateInitClearSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
