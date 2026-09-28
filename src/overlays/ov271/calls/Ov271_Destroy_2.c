/* Destroy the three sub-instances at (param_1)+4/+8/+0xc. */
extern void DestroyInstance(int a);
void Ov271_Destroy_2(int param_1) {
    DestroyInstance(*(int *)(param_1 + 4));
    DestroyInstance(*(int *)(param_1 + 8));
    DestroyInstance(*(int *)(param_1 + 0xc));
}
