/* Teardown: release +0x384, the 2 stride-8 table entries at +0x398, free it, finalise. */
struct row8 { int p; int pad; };
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov253_ReleaseSubObjectsListThenNotify(int param_1) {
    int i;
    DestroyInstance(*(int *)(param_1 + 0x384));
    for (i = 0; i < 2; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x398))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x398));
    Ov107_DestroyObject(param_1);
}
