/* Same routine as the ov157 function of this name, with the 0x4c size variant; see it for the
 * details. */

extern void CreateRegistryEntry();
extern void Ov149_stInitSlotsFlags6(void);

void Ov149_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x4c, Ov149_stInitSlotsFlags6, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
