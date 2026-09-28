/* Create a sub-object via CreateRegistryEntry (kind 0x64/0x48, handler Ov197_InitReactionSlots),
 * back-link it, copy owner state at +0x384, and store it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov197_InitReactionSlots(void);

void Ov197_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x48, Ov197_InitReactionSlots, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
