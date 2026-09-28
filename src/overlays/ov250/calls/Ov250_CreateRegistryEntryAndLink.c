/* Spawn a child object via CreateRegistryEntry (callback Ov250_InitStates), link it back to this
 * object and store it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov250_InitStates(void);

void Ov250_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x88, Ov250_InitStates, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
