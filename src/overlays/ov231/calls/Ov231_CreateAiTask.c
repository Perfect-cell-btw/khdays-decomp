/* Spawn a child object via CreateRegistryEntry (callback ov231_020cd118), link it back to this object,
 * store it at +0x214 and initialise the child's +0x58 and +0x50 fields. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov231_AiStateInit(int);
void Ov231_CreateAiTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x5c, (void *)&Ov231_AiStateInit, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(param_1 + 0x214) = obj;
    *(int *)(obj + 0x58) = 1;
    *(short *)(obj + 0x50) = 0x155;
}
