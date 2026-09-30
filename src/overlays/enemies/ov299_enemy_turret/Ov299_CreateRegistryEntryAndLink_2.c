/* Creates the object's state-machine registry entry (starting in its init state), links it back to
 * the object and stores it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov299_stateInitClearSlots(void);

void Ov299_CreateRegistryEntryAndLink_2(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x34, Ov299_stateInitClearSlots, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
