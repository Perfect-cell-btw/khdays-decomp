/* Tear down this object: release the +0x384 resource, release each of the 5 stride-8 entries in
 * the +0x3a8 table, free the table and run the ov107 finaliser. */
struct row8 { int p; int pad; };
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov279_Destroy(int param_1) {
    int i;
    DestroyInstance(*(int *)(param_1 + 0x384));
    for (i = 0; i < 5; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x3a8))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x3a8));
    Ov107_DestroyObject(param_1);
}
