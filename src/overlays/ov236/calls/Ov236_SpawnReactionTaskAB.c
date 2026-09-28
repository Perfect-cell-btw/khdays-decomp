/* Ov236_SpawnReactionTaskAB -- spawn the 0xc-byte task that drives this reaction (step
 * Ov236_ResetModelTracks, completion Ov236_TaskTeardown_FlagPart, priority 0x64) and seed its three-word
 * payload with (self, a, b). RETURNS the task handle: the ROM leaves r0 untouched from the spawn
 * call to the `pop`, and declaring the function `void` frees r0 so mwcc reuses it for the payload
 * pointer -- one register off, nothing else.
 * The payload pointer is re-read from the stack before each store because its address escaped into
 * the spawn call, so the stores could alias it; that is the ROM's three `ldr r1,[sp,#8]`. */
extern int CreateRegistryEntry(int owner, int a, int b, void *step, void *done, int **out);
extern void Ov236_TaskTeardown_FlagPart(void);
extern void Ov236_ResetModelTracks(void);

int Ov236_SpawnReactionTaskAB(int obj, int a, int b) {
    int *out;
    int r = CreateRegistryEntry(*(int *)(obj + 0x3c), 0x64, 0xc, (void *)Ov236_ResetModelTracks,
                          (void *)Ov236_TaskTeardown_FlagPart, &out);
    out[0] = obj;
    out[1] = a;
    out[2] = b;
    return r;
}
