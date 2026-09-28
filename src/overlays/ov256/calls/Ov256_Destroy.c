/* Teardown: release +0x384 (c7e8) and +0x390 (ov107), finalise. */
extern void DestroyInstance(int a);
extern void Ov107_ActionResource_Destroy(int a);
extern void Ov107_DestroyObject(int a);
void Ov256_Destroy(int param_1) {
    DestroyInstance(*(int *)(param_1 + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(param_1 + 0x390));
    Ov107_DestroyObject(param_1);
}
