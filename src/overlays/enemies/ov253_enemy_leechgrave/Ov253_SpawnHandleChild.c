/* Ov253_SpawnHandleChild -- spawn the 0x28-byte sub-object of kind 0x64 (tick 020d1170, finish
 * 020d1220) linked to the actor, seeded with the +0x3b0 item's +8 handle. */
extern int CreateRegistryEntry(int scene, int kind, int size, void *cb, void *cb2, int **out);
extern void Ov253_CarriedSetup(void);
extern void Ov253_ResetEntryMarkDirty(void);

int Ov253_SpawnHandleChild(int self) {
    int *out;
    int rc = CreateRegistryEntry(*(int *)(self + 0x3c), 100, 0x28, Ov253_CarriedSetup, Ov253_ResetEntryMarkDirty, &out);
    out[0] = self;
    out[1] = *(int *)(*(int *)(out[0] + 0x3b0) + 8);
    return rc;
}
