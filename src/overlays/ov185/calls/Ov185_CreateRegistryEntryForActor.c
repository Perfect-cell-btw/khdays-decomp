/* Spawn a child object via CreateRegistryEntry (callback ov185_020d0064), link it back to this object
 * and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov185_SeedVecAndArm_2(int);
void Ov185_CreateRegistryEntryForActor(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x98, (void *)&Ov185_SeedVecAndArm_2, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(param_1 + 0x214) = obj;
}
