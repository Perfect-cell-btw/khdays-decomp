/* Create a sub-object via CreateRegistryEntry and populate it through the stack out-param.
 * Returns c5c0's result: that is what keeps r0 live across the out-param reload, so the
 * ROM's `ldr r1,[sp,#N]` needs no extra instruction. */

extern int CreateRegistryEntry(int scene, int kind, int size, void *cb, void *cb2, int **out);
extern void Ov255_TaskTeardown_FlagOwner(void);
extern void Ov255_SnapshotPoseRegister2(void);

int Ov255_SpawnChildStoreTwoArgs(int self, int a, int b) {
    int *out;

    int rc = CreateRegistryEntry(*(int *)(self + 0x3c), 100, 0xc, Ov255_SnapshotPoseRegister2, Ov255_TaskTeardown_FlagOwner, &out);
    out[0] = a;
    out[1] = b;
    return rc;
}
