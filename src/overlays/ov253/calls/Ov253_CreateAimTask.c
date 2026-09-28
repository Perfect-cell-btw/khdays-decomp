/* Create a sub-object via CreateRegistryEntry and populate it through the stack out-param.
 * Returns c5c0's result: that is what keeps r0 live across the out-param reload, so the
 * ROM's `ldr r1,[sp,#N]` needs no extra instruction. */

extern int CreateRegistryEntry(int scene, int kind, int size, void *cb, void *cb2, int **out);
extern void Ov253_NotifyOwnerHooks(void);
extern void Ov253_AimSetup(void);

int Ov253_CreateAimTask(int self, int arg) {
    int *out;

    int rc = CreateRegistryEntry(*(int *)(self + 0x3c), 100, 0x2c, Ov253_AimSetup, Ov253_NotifyOwnerHooks, &out);
    out[0] = self;
    out[1] = arg;
    return rc;
}
