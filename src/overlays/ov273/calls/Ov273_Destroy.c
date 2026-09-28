/* Teardown: release *(+0x3a8) target, free the +0x3a8 table, release +0x388/+0x38c, finalise. */
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov273_Destroy(int param_1) {
    DestroyInstance(*(int *)*(int *)(param_1 + 0x3a8));
    FreeInstanceMemory(*(int *)(param_1 + 0x3a8));
    DestroyInstance(*(int *)(param_1 + 0x388));
    DestroyInstance(*(int *)(param_1 + 0x38c));
    Ov107_DestroyObject(param_1);
}
