/* Spawn a child object via CreateRegistryEntry, store this object at the child's +0xc, seed +0 from
 * *(this)+0x3e4 and return the child. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov237_SparkEmitterStart(int);
int Ov237_CreateSparkEmitter(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x20, (void *)&Ov237_SparkEmitterStart, 0, &obj);
    *(int *)(obj + 0xc) = param_1;
    *(int *)obj = *(int *)(param_1 + 0x3e4);
    return obj;
}
