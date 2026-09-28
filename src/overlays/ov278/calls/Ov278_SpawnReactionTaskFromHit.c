/* Ov278_SpawnReactionTaskFromHit -- spawn the 0xc-byte task for this reaction (step Ov278_EnterRelease,
 * completion Ov278_SetField5cBit1BothEntries, priority 0x64) and seed its payload with (self, hit.x, hit.z)
 * read from the collision record at +0x3b0. Returns the task handle -- see the sibling
 * Ov236_SpawnReactionTaskAB for why the return type is load-bearing. */
extern int CreateRegistryEntry(int owner, int a, int b, void *step, void *done, int **out);
extern void Ov278_EnterRelease(void);
extern void Ov278_SetField5cBit1BothEntries(void);

int Ov278_SpawnReactionTaskFromHit(int obj) {
    int *out;
    int r = CreateRegistryEntry(*(int *)(obj + 0x3c), 0x64, 0xc, (void *)Ov278_EnterRelease,
                          (void *)Ov278_SetField5cBit1BothEntries, &out);
    out[0] = obj;
    out[1] = *(int *)(*(int *)(obj + 0x3b0) + 0x40);
    out[2] = *(int *)(*(int *)(obj + 0x3b0) + 0x48);
    return r;
}
