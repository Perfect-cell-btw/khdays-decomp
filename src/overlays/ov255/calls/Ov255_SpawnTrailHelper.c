/* Spawn of the ov255 trail helper (0x14-byte state, kind 100): its tick is Ov255_StartHelper and
 * its second callback Ov255_SetField5cBit1Pair; the helper keeps the two parts and the source pose. */
extern int CreateRegistryEntry(int scene, int kind, int size, void *cb, void *cb2, int **out);
extern void Ov255_StartHelper(void);
extern void Ov255_SetField5cBit1Pair(void);

int Ov255_SpawnTrailHelper(int self, int a, int b, int c)
{
    int *out;

    int rc = CreateRegistryEntry(*(int *)(self + 0x3c), 100, 0x14, Ov255_StartHelper, Ov255_SetField5cBit1Pair, &out);
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return rc;
}
