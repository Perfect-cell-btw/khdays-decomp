/* Spawn a child object via CreateRegistryEntry, link back to owner, store at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov254_TwinMarker_AiStateInit(int);
void Ov254_TwinMarker_CreateAiTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x4, (void *)&Ov254_TwinMarker_AiStateInit, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(param_1 + 0x214) = obj;
}
