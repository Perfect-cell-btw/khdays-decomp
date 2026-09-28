/* Spawn a child object via CreateRegistryEntry (callback ov212_020d0e7c), link it back to this object
 * and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov212_stateInitClearSlots(int);
void Ov212_CreateAiTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x64, (void *)&Ov212_stateInitClearSlots, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(param_1 + 0x214) = obj;
}
