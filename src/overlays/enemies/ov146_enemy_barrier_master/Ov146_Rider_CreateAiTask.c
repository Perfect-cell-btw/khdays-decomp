/* Spawn a child object via CreateRegistryEntry (callback 020ce83c), link it back to this object, copy
 * *(child)+0x384 into its +4 field and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov146_BrainStart(int);
void Ov146_Rider_CreateAiTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x20, (void *)&Ov146_BrainStart, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 4) = *(int *)(*(int *)obj + 0x384);
    *(int *)(param_1 + 0x214) = obj;
}
