/* Creates the object's state-machine registry entry (starting in its init state), links it back to
 * the object and stores it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov204_EnterAimStateInstallCallbacks(void);

void Ov204_CreateRegistryEntryAndLink(int this_) {
    int *entry;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x5c, Ov204_EnterAimStateInstallCallbacks, 0, &entry);
    *entry = this_;
    *(int **)(this_ + 0x214) = entry;
}
