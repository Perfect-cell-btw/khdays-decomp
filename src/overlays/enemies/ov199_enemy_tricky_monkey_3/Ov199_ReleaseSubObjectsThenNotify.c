/* Teardown: release +0x384/+0x388/+0x3f0, finalise. */
extern void DestroyInstance(int a);
extern void Ov107_DestroyObject(int a);
void Ov199_ReleaseSubObjectsThenNotify(int param_1) {
    DestroyInstance(*(int *)(param_1 + 0x384));
    DestroyInstance(*(int *)(param_1 + 0x388));
    DestroyInstance(*(int *)(param_1 + 0x3f0));
    Ov107_DestroyObject(param_1);
}
