/* Ov253_SpawnItemChild -- spawn the 8-byte sub-object of kind 0x64 (tick 020d1894, finish
 * 020d1aa0) linked to the actor and its +0x3b8 item, whose bit 1 of +0x5c is cleared. */
extern int CreateRegistryEntry(int scene, int kind, int size, void *cb, void *cb2, int **out);
extern void Ov253_RingLayout(void);
extern void Ov253_ResetEntryList(void);

int Ov253_SpawnItemChild(int self) {
    int *out;
    int rc = CreateRegistryEntry(*(int *)(self + 0x3c), 100, 8, Ov253_RingLayout, Ov253_ResetEntryList, &out);
    out[0] = self;
    out[1] = *(int *)(self + 0x3b8);
    *(int *)(out[1] + 0x5c) &= ~2;
    return rc;
}
