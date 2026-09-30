/* Spawn a child object via CreateRegistryEntry (callbacks ov210_020d40a8 and ov210_020d4078), link it
 * back to this object and return it. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, void *cb2, int *out);
extern void Ov211_SwoopTaskReleaseNoOp(int);
extern void Ov211_AiGoToIdle(int);
int Ov211_CreateSwoopTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x4c, (void *)&Ov211_AiGoToIdle,
                  (void *)&Ov211_SwoopTaskReleaseNoOp, &obj);
    *(int *)obj = param_1;
    return obj;
}
