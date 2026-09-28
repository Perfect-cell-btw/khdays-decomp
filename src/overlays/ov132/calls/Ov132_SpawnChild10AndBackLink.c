/* Create a sub-object via CreateRegistryEntry and back-link it to the owner.
 * Returns c5c0's result: that is what keeps r0 live across the out-param
 * load, so the ROM's `ldr r1,[sp,#8]` needs no extra instruction. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb1, void *cb2, int **out);
extern void Ov132_stInitChildActor(void);
extern void Ov132_ChildTaskTeardownAndFlag(void);

int Ov132_SpawnChild10AndBackLink(int this_) {
    int *entry;
    int rc = CreateRegistryEntry(*(int *)(this_ + 0x3c), 0x64, 0x10, Ov132_stInitChildActor, Ov132_ChildTaskTeardownAndFlag, &entry);
    *entry = this_;
    return rc;
}
