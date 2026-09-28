/* Teardown: release +0x388, release the 3 stride-8 entries in the +0x3a4 table, free it, finalise. */
struct row8 { int p; int pad; };
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov277_Destroy(int param_1) {
    int i;
    DestroyInstance(*(int *)(param_1 + 0x388));
    for (i = 0; i < 3; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x3a4))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x3a4));
    Ov107_DestroyObject(param_1);
}
