/* Tear down: release +0x388, release the 3 stride-8 entries in the +0x38c table, free it and
 * run the ov107 finaliser. */
struct row8 { int p; int pad; };
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov277_Destroy_2(int param_1) {
    int i;
    DestroyInstance(*(int *)(param_1 + 0x388));
    for (i = 0; i < 3; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x38c))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x38c));
    Ov107_DestroyObject(param_1);
}
