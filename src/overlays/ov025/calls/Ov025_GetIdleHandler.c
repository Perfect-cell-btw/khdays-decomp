/* Ov025_GetIdleHandler -- pick the ov025 idle handler from the heap state word.
 * Bit 0 set = busy, no handler. Otherwise flush pending work (Ov025_SetMenuFlag4) when
 * Ov025_CommitPage says so, and return Ov025_IdleHandlerNoOp only if bit 2 is set.
 *
 * The lever that closed this one (it was parked as a "one-byte predication tie"): the ROM
 * materialises the 0 UNCONDITIONALLY between the `tst` and the `popne`, where mwcc predicates
 * it (`movne r0,#0`). That constant is doing double duty -- it is both the early return value
 * and r0 for the call that immediately follows the conditional return, which is what forces it
 * above the branch. Ov025_CommitPage is defined `(void)` and ignores it, so the declaration
 * here is the K&R one the original translation unit must have used. A constant hoisted above a
 * branch is the arity smell, not a predication tie. */
extern int  NNSi_FndGetCurrentRootHeap(void);
extern int  Ov025_CommitPage();
extern void Ov025_SetMenuFlag4(int arg);
extern void Ov025_IdleHandlerNoOp(void);

int Ov025_GetIdleHandler(void) {
    unsigned int *state = (unsigned int *)NNSi_FndGetCurrentRootHeap();
    if ((*state & 1) != 0) {
        return 0;
    }
    if (Ov025_CommitPage(0) != 0) {
        Ov025_SetMenuFlag4(0);
    }
    if ((*state & 4) != 0) {
        return (int)Ov025_IdleHandlerNoOp;
    }
    return 0;
}
