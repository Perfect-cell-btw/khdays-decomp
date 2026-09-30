/* Create a sub-object via CreateRegistryEntry and back-link it to the owner.
 * Returns c5c0's result: that is what keeps r0 live across the out-param
 * load, so the ROM's `ldr r1,[sp,#8]` needs no extra instruction. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb1, void *cb2, int **out);
extern void Ov257_StartPartHelper(void);
extern void Ov257_MarkAllSubNodesDirty(void);

int Ov257_SpawnChild10AndBackLink(int this_) {
    int *entry;
    int rc = CreateRegistryEntry(*(int *)(this_ + 0x3c), 0x64, 0x4, Ov257_StartPartHelper, Ov257_MarkAllSubNodesDirty, &entry);
    *entry = this_;
    return rc;
}
