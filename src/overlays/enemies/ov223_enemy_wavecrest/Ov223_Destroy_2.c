/* Destroys the models and attached instances (freeing their table), then the base object. */

/* Teardown: release +0x384/+0x398/+0x394, finalise. */
extern void DestroyInstance(int a);
extern void Ov107_DestroyObject(int a);
void Ov223_Destroy_2(int param_1) {
    DestroyInstance(*(int *)(param_1 + 0x384));
    DestroyInstance(*(int *)(param_1 + 0x398));
    DestroyInstance(*(int *)(param_1 + 0x394));
    Ov107_DestroyObject(param_1);
}
