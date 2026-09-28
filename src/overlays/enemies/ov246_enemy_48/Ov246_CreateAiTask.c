/* Creates the AI task (first step InitChase) and links it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov246_BeginPhasedReaction(void);
void Ov246_CreateAiTask(int param_1) {
    int *entry;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 100, 0x58, Ov246_BeginPhasedReaction, 0, &entry);
    *entry = param_1;
    entry[1] = *(int *)(*entry + 0x388);
    *(int **)(param_1 + 0x214) = entry;
}
