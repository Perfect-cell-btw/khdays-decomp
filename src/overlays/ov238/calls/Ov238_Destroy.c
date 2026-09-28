/* Destroys the model instances, then the base object. */

/* Teardown: release +0x384/+0x3a4, finalise. */
extern void DestroyInstance(int a);
extern void Ov107_DestroyObject(int a);
void Ov238_Destroy(int param_1) {
    DestroyInstance(*(int *)(param_1 + 0x384));
    DestroyInstance(*(int *)(param_1 + 0x3a4));
    Ov107_DestroyObject(param_1);
}
