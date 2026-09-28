/* Teardown: release +0x388, the 2 stride-8 table entries at +0x3c0, free it, finalise. */
struct row8 { int p; int pad; };
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov255_Partner_Destroy(int param_1) {
    int i;
    DestroyInstance(*(int *)(param_1 + 0x388));
    for (i = 0; i < 2; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x3c0))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x3c0));
    Ov107_DestroyObject(param_1);
}
