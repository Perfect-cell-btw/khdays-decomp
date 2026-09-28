/* Teardown: release +0x384, release the 9 stride-8 table entries at +0x39c, free it, finalise. */
struct row8 { int p; int pad; };
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov126_Destroy(int param_1) {
    int i;
    DestroyInstance(*(int *)(param_1 + 0x384));
    for (i = 0; i < 9; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x39c))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x39c));
    Ov107_DestroyObject(param_1);
}
