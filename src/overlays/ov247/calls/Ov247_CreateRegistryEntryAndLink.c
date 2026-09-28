/* Create a sub-object via CreateRegistryEntry (kind 0x64/0x2c, handler Ov247_stateInitClearSlots), back-
 * link it to the owner, and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *handler, int e, int *out);
extern void Ov247_stateInitClearSlots(void);
void Ov247_CreateRegistryEntryAndLink(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x2c, (void *)&Ov247_stateInitClearSlots, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(param_1 + 0x214) = obj;
}
