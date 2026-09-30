/* Creates the object's state-machine registry entry (starting in its AI init state), links it to
 * the object and its model (+0x384) and stores it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov122_InitAiState(void);

void Ov122_SpawnActorRegistryEntry(int this_) {
    int *result;
    CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0x50, Ov122_InitAiState, 0, &result);
    *result = this_;
    result[1] = *(int *)(*result + 0x384);
    *(int **)(this_ + 0x214) = result;
}
