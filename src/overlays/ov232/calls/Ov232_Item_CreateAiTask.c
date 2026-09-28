/* Spawn a child object via CreateRegistryEntry (callback ov231_020cf338), link it back to this object,
 * set the child's +0x24 field to 0x155 and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov232_stateInitClearSlots(int);
void Ov232_Item_CreateAiTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x28, (void *)&Ov232_stateInitClearSlots, 0, &obj);
    *(int *)obj = param_1;
    *(short *)(obj + 0x24) = 0x155;
    *(int *)(param_1 + 0x214) = obj;
}
