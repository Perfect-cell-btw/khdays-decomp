/* Object teardown: release/free sub-resources and run the finaliser. */
struct row8 { int p; int pad; };
extern void FreeAllResourceTables(int a);
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
extern void Ov107_ActionResource_Destroy(int a);
void Ov278_Destroy(int param_1) {
    int i;
    FreeAllResourceTables(*(int *)(param_1 + 0x38c));
    FreeInstanceMemory(*(int *)(param_1 + 0x38c));
    FreeAllResourceTables(*(int *)(param_1 + 0x390));
    FreeInstanceMemory(*(int *)(param_1 + 0x390));
    DestroyInstance(*(int *)(param_1 + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(param_1 + 0x3ac));
    DestroyInstance(*(int *)(param_1 + 0x388));
    for (i = 0; i < 10; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x3b0))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x3b0));
    Ov107_DestroyObject(param_1);
}
