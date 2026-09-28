/* Spawn a child object via CreateRegistryEntry (callback 020d1630), link it back to this object, copy
 * *(child)+0x384 into its +4 field and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov245_stateInitClearSlots_3(int);
void Ov245_Thrown_CreateAiTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x34, (void *)&Ov245_stateInitClearSlots_3, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 4) = *(int *)(*(int *)obj + 0x384);
    *(int *)(param_1 + 0x214) = obj;
}
