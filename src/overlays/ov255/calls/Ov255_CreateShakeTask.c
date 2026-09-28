/* Spawn a child object via CreateRegistryEntry, seed +4 from *(this)+0x388, link back to owner and
 * return the child. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov255_ShakeTask_Init(int);
int Ov255_CreateShakeTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x14, (void *)&Ov255_ShakeTask_Init, 0, &obj);
    *(int *)(obj + 4) = *(int *)(param_1 + 0x388);
    *(int *)obj = param_1;
    return obj;
}
