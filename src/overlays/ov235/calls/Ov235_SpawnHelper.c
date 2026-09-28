/* Spawns an ov235 helper object through CreateRegistryEntry (scene +0x3c, kind 100, 0x18 bytes, update
 * Ov235_HelperStartB, teardown Ov235_HelperTaskTeardown) and fills it with the owner and the three
 * arguments; returns the spawner's result. */
extern int CreateRegistryEntry(int scene, int kind, int size, void *cb, void *cb2, int **out);
extern void Ov235_HelperStartB(void);
extern void Ov235_HelperTaskTeardown(void);

int Ov235_SpawnHelper(int self, int a, int b, int c)
{
    int *out;

    int rc = CreateRegistryEntry(*(int *)(self + 0x3c), 100, 0x18, Ov235_HelperStartB, Ov235_HelperTaskTeardown, &out);
    out[0] = self;
    out[1] = a;
    out[2] = b;
    out[3] = c;
    return rc;
}
