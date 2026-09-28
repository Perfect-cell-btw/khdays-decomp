/* Spawn a child object via CreateRegistryEntry (+0x384 copy), link back to owner, store at +0x214.
 */

extern void CreateRegistryEntry();
extern void Ov281_InitReactionSlots(void);

void Ov281_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x40, Ov281_InitReactionSlots, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
