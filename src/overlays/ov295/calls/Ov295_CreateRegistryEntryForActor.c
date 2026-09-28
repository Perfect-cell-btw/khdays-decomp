/* Spawn a child object via CreateRegistryEntry (callback Ov295_SetupActorNodeAndStateSlots), link
 * it back to this object and store it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov295_SetupActorNodeAndStateSlots();

void Ov295_CreateRegistryEntryForActor(int this_) {
    int out;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 0x64, 0x10, (int)&Ov295_SetupActorNodeAndStateSlots, 0, &out);
    *(int *)out = this_;
    *(int *)(this_ + 0x214) = out;
}
