/* Spawn a child object via CreateRegistryEntry (callback Ov152_EnterAimStateInstallCallbacks), link
 * it back to this object and store it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov152_EnterAimStateInstallCallbacks(void);

void Ov152_CreateRegistryEntryAndLink_2(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x50, Ov152_EnterAimStateInstallCallbacks, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
