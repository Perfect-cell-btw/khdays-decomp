/* Spawn a child object via CreateRegistryEntry (callback 020cf3b8), link it back to this
 * object, copy *(child)+0x384 into the child's +4 field and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov236_InitMountState(int);
void Ov236_SpawnActorRegistryEntry(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x60, (void *)&Ov236_InitMountState, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 4) = *(int *)(*(int *)obj + 0x384);
    *(int *)(param_1 + 0x214) = obj;
}
