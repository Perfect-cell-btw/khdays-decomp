/* Teardown: free +0x3e4 table, release +0x384/+0x3a0, release the 2 stride-8 table entries at
 * +0x3e8, free it, finalise. */
struct row8 { int p; int pad; };
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov253_QueueActor_Destroy(int param_1) {
    int i;
    FreeInstanceMemory(*(int *)(param_1 + 0x3e4));
    DestroyInstance(*(int *)(param_1 + 0x384));
    DestroyInstance(*(int *)(param_1 + 0x3a0));
    for (i = 0; i < 2; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x3e8))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x3e8));
    Ov107_DestroyObject(param_1);
}
