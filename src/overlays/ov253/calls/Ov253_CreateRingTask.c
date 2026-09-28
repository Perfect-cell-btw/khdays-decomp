/* Spawn a child object via CreateRegistryEntry, seed its +0 from *(this)+0x3a8 and return it. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov253_RingSetup(int);
int Ov253_CreateRingTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0xc, (void *)&Ov253_RingSetup, 0, &obj);
    *(int *)obj = *(int *)(param_1 + 0x3a8);
    return obj;
}
