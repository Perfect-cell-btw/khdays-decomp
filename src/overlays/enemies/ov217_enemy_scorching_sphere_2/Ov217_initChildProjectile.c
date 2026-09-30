/* Initialises a child projectile model: frees its old resource tables, sets up its render object,
 * registers its sequence, resets its slot rows, starts its first animation and refreshes its
 * callbacks. */

extern void FreeAllResourceTables(void *p);
extern void NNS_G3dRenderObjInit(void *a, int b);
extern void Snd_RegisterSeqAndBind(void *a, void *b, int c, int d);
extern void MainBlob_ResetSlotRows(void *a, void *b);
extern void SetSubitemState(void *a, int b, int c, int d);
extern void RefreshObjectCallbacks(void *a, int b);

void Ov217_initChildProjectile(char *this, int param2, int param3, char *param4) {
    char *obj = *(char **)(this + 0x88);
    FreeAllResourceTables(param4);
    *(int *)(param4 + 0xc) = 0;
    NNS_G3dRenderObjInit(obj + 0x20, *(int *)(obj + 0x78));
    Snd_RegisterSeqAndBind(param4, obj, param2, 0xc);
    MainBlob_ResetSlotRows(this, param4);
    SetSubitemState(this, 0, 0, param3);
    RefreshObjectCallbacks(this, 0);
}
