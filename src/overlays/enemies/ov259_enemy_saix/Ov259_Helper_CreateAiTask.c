/* Creates the helper's AI task and links it. */

extern void CreateRegistryEntry();
extern void Ov259_Helper_AiStateInit(void);
void Ov259_Helper_CreateAiTask(int param_1) {
    int *entry;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 100, 0x54, Ov259_Helper_AiStateInit, 0, &entry);
    *entry = param_1;
    entry[1] = *entry + 0x384;
    *(int **)(param_1 + 0x214) = entry;
}
