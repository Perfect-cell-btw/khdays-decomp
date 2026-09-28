/* Teardown: run 0202a440 on &(+0x3a8), release +0x384, ov107-release +0x3a0,
 * release the 5 stride-8 table entries at +0x3a4, free it, finalise. */
struct row8 { int p; int pad; };
extern void FreeAllResourceTables(int a);
extern void DestroyInstance(int a);
extern void Ov107_ActionResource_Destroy(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov245_Rider_Destroy(int param_1) {
    int i;
    FreeAllResourceTables(param_1 + 0x3a8);
    DestroyInstance(*(int *)(param_1 + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(param_1 + 0x3a0));
    for (i = 0; i < 5; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x3a4))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x3a4));
    Ov107_DestroyObject(param_1);
}
