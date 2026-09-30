/* Creates the actor's AI registry entry (seeding its vector and arming it) and links it. */

extern void CreateRegistryEntry();
extern void Ov117_SeedVecAndArm();

void Ov117_CreateRegistryEntryForActor(int this_) {
    int out;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 0x64, 0x98, (int)&Ov117_SeedVecAndArm, 0, &out);
    *(int *)out = this_;
    *(int *)(this_ + 0x214) = out;
}
