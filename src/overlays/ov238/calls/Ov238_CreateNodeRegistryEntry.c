/* Spawn a child object via CreateRegistryEntry (+0x388 copy), link back to owner, store at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov238_BeginPhasedReaction(int);
void Ov238_CreateNodeRegistryEntry(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x38, (void *)&Ov238_BeginPhasedReaction, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 4) = *(int *)(*(int *)obj + 0x388);
    *(int *)(param_1 + 0x214) = obj;
}
