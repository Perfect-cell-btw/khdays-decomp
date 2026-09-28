/* Spawn a child object via CreateRegistryEntry (callback ov212_020ce440), link it back to this object,
 * copy *(child)+0x384 into the child's +4 field and store the child at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov266_BeginPhaseSequence(int);
void Ov266_CreateNodeRegistryEntry(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x74, (void *)&Ov266_BeginPhaseSequence, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 4) = *(int *)(*(int *)obj + 0x384);
    *(int *)(param_1 + 0x214) = obj;
}
