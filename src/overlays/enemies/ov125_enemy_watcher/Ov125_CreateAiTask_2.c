/* Spawn a child object via CreateRegistryEntry (callback ov125_020cfaac), link it back to this object,
 * copy *(child)+0x9c into the child's +4 field and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov125_stateInitClearSlots(int);
void Ov125_CreateAiTask_2(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x20, (void *)&Ov125_stateInitClearSlots, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 4) = *(int *)(*(int *)obj + 0x9c);
    *(int *)(param_1 + 0x214) = obj;
}
