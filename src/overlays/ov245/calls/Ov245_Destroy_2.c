/* Teardown: release +0x384/+0x398, finalise. */
extern void DestroyInstance(int a);
extern void Ov107_DestroyObject(int a);
void Ov245_Destroy_2(int param_1) {
    DestroyInstance(*(int *)(param_1 + 0x384));
    DestroyInstance(*(int *)(param_1 + 0x398));
    Ov107_DestroyObject(param_1);
}
