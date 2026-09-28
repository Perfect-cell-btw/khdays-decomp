/* Teardown: release +0x38c/+0x3b8, the 5 stride-8 table entries at +0x3b0, free it, finalise. */
struct row8 { int p; int pad; };
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov253_Segment_Destroy(int param_1) {
    int i;
    DestroyInstance(*(int *)(param_1 + 0x38c));
    DestroyInstance(*(int *)(param_1 + 0x3b8));
    for (i = 0; i < 5; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x3b0))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x3b0));
    Ov107_DestroyObject(param_1);
}
