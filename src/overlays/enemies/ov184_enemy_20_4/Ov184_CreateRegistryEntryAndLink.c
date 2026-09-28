/* Spawn a child object via CreateRegistryEntry (callback Ov184_InitNodeAndRegisterHandlers), link
 * it back to this object and store it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov184_InitNodeAndRegisterHandlers(void);

void Ov184_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x88, Ov184_InitNodeAndRegisterHandlers, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
