/* Teardown: run 0202a440 on &(+0x388), release +0x384, finalise. */
extern void FreeAllResourceTables(int a);
extern void DestroyInstance(int a);
extern void Ov107_DestroyObject(int a);
void Ov146_Destroy(int param_1) {
    FreeAllResourceTables(param_1 + 0x388);
    DestroyInstance(*(int *)(param_1 + 0x384));
    Ov107_DestroyObject(param_1);
}
