extern void CreateRegistryEntry();
extern void Ov294_SetupActorNodeAndStateSlots();

void Ov294_CreateRegistryEntryForActor(int this_) {
    int out;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 0x64, 0x10, (int)&Ov294_SetupActorNodeAndStateSlots, 0, &out);
    *(int *)out = this_;
    *(int *)(this_ + 0x214) = out;
}
