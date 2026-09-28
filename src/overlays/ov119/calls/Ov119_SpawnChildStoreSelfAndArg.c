/* Create a sub-object via CreateRegistryEntry and populate it through the stack out-param.
 * Returns c5c0's result: that is what keeps r0 live across the out-param reload, so the
 * ROM's `ldr r1,[sp,#N]` needs no extra instruction. */

extern int CreateRegistryEntry(int scene, int kind, int size, void *cb, void *cb2, int **out);
extern void Ov119_ChildReleaseNoOp(void);
extern void Ov119_TimerBlinkStart(void);

int Ov119_SpawnChildStoreSelfAndArg(int self, int arg) {
    int *out;

    int rc = CreateRegistryEntry(*(int *)(self + 0x3c), 100, 0x10, Ov119_TimerBlinkStart, Ov119_ChildReleaseNoOp, &out);
    out[0] = self;
    out[3] = arg;
    return rc;
}
