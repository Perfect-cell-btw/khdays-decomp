/* Create a sub-object via CreateRegistryEntry and back-link it to the owner.
 * Returns c5c0's result: that is what keeps r0 live across the out-param
 * load, so the ROM's `ldr r1,[sp,#8]` needs no extra instruction. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb1, void *cb2, int **out);
extern void Ov131_stateInitSubitem(void);
extern void Ov131_ChildTaskTeardown(void);

int Ov131_SpawnChild0cAndBackLink(int this_) {
    int *entry;
    int rc = CreateRegistryEntry(*(int *)(this_ + 0x3c), 100, 0xc, Ov131_stateInitSubitem, Ov131_ChildTaskTeardown, &entry);
    *entry = this_;
    return rc;
}
