/* Spawn a child object via CreateRegistryEntry (callback Ov161_AiStateInit), link it back to this
 * object, copy *(child)+0x384 into the child's +4 field and store it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov161_AiStateInit(void);

void Ov161_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x60, Ov161_AiStateInit, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
