/* Create a sub-object via CreateRegistryEntry and populate it through the stack out-param.
 * Returns c5c0's result: that is what keeps r0 live across the out-param reload, so the
 * ROM's `ldr r1,[sp,#N]` needs no extra instruction. */

extern int CreateRegistryEntry(int scene, int kind, int size, void *cb, void *cb2, int **out);
extern void Ov244_TaskTeardown_FlagPart(void);
extern void Ov244_EnterRelease(void);

int Ov244_SpawnChildStoreSelfAndArg(int self, int arg) {
    int *out;

    int rc = CreateRegistryEntry(*(int *)(self + 0x3c), 100, 0xc, Ov244_EnterRelease, Ov244_TaskTeardown_FlagPart, &out);
    out[0] = self;
    out[1] = arg;
    return rc;
}
