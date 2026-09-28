/* Tear down: release the +0x394/+0x388/+0x38c resources and run the ov107 finaliser. */
struct row8 { int p; int pad; };
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov273_Destroy_3(int param_1) {
    DestroyInstance(*(int *)(param_1 + 0x394));
    DestroyInstance(*(int *)(param_1 + 0x388));
    DestroyInstance(*(int *)(param_1 + 0x38c));
    Ov107_DestroyObject(param_1);
}
