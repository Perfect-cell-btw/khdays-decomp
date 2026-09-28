/* Spawn a child object via CreateRegistryEntry (callback 020d09a8), link it back to this
 * object and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov213_InitChaseState(int);
void Ov213_CreateRegistryEntryAndLink(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x88, (void *)&Ov213_InitChaseState, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(param_1 + 0x214) = obj;
}
