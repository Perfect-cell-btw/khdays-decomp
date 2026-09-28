/* Create a sub-object via CreateRegistryEntry (kind 0x64/0x48, handler Ov198_InitReactionSlots),
 * back-link it, copy owner state at +0x384, and store it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov198_InitReactionSlots(void);

void Ov198_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x48, Ov198_InitReactionSlots, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
