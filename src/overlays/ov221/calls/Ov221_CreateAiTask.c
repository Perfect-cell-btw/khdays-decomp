/* Create a sub-object via CreateRegistryEntry (kind 0x64/0x80, handler Ov221_ResetSubObjectsAndArm), back-
 * link it, copy the owner state at +0x384 into it, and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *handler, int e, int *out);
extern void Ov221_ResetSubObjectsAndArm(void);
void Ov221_CreateAiTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x80, (void *)&Ov221_ResetSubObjectsAndArm, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 4) = *(int *)(*(int *)obj + 0x384);
    *(int *)(param_1 + 0x214) = obj;
}
