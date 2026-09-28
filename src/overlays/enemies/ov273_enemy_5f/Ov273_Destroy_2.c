/* Tear down: release the 2 stride-8 entries in the +0x394 table, free it, release +0x388 and
 * run the ov107 finaliser. */
struct row8 { int p; int pad; };
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov273_Destroy_2(int param_1) {
    int i;
    for (i = 0; i < 2; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x394))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x394));
    DestroyInstance(*(int *)(param_1 + 0x388));
    Ov107_DestroyObject(param_1);
}
