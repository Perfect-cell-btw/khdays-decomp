/* Spawn a child object via CreateRegistryEntry (callback 020d1bf4), link it back to this object and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov255_Partner_AiStateInit(int);
void Ov255_CreateRegistryEntryAndLink(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x28, (void *)&Ov255_Partner_AiStateInit, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(param_1 + 0x214) = obj;
}
