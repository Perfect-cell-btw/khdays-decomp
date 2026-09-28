/* Spawn a child object via CreateRegistryEntry, copy fields from *(child), store at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov258_AiStateInit(int);
void Ov258_CreateAiTask_2(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x20, (void *)&Ov258_AiStateInit, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 0x4) = *(int *)(*(int *)obj + 0x384);
    *(signed char *)(obj + 0x1d) = -1;
    *(int *)(param_1 + 0x214) = obj;
}
