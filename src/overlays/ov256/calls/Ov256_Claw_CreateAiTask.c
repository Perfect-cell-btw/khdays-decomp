/* Spawn a child object via CreateRegistryEntry, copy fields from *(child), store at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov256_Claw_AiStateInit(int);
void Ov256_Claw_CreateAiTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x90, (void *)&Ov256_Claw_AiStateInit, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 0x8) = *(int *)(*(int *)obj + 0x384);
    *(int *)(param_1 + 0x214) = obj;
}
