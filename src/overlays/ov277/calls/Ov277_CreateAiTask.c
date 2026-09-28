/* Spawn a child object via CreateRegistryEntry (callback 020d0fbc), link it back to this
 * object and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov277_stateInitClearSlots(int);
void Ov277_CreateAiTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x18, (void *)&Ov277_stateInitClearSlots, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(param_1 + 0x214) = obj;
}
