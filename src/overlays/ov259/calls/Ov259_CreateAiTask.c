/* Spawn a child object via CreateRegistryEntry (+0x38c copy), link back to owner, store at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov259_StartBrain(int);
void Ov259_CreateAiTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0xb0, (void *)&Ov259_StartBrain, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 4) = *(int *)(*(int *)obj + 0x38c);
    *(int *)(param_1 + 0x214) = obj;
}
