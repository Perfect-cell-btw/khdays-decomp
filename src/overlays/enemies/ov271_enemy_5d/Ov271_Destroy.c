/* Tear down the actor: destroy the render (+0x384) and list (+0x3a8) instances, free the 4
 * slot handles at +0x3a4, release the 3 sub-actors at +0x390, then release the handle table
 * and the actor itself. */
extern void DestroyInstance(int a);
extern void Ov271_Destroy_2(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
struct row8_020ce0d0 { int p; int q; };
void Ov271_Destroy(int param_1) {
    int i;
    DestroyInstance(*(int *)(param_1 + 0x384));
    DestroyInstance(*(int *)(param_1 + 0x3a8));
    for (i = 0; i < 4; i++) {
        DestroyInstance(((struct row8_020ce0d0 *)*(int *)(param_1 + 0x3a4))[i].p);
    }
    for (i = 0; i < 3; i++) {
        Ov271_Destroy_2(((int *)param_1)[i + 0xe4]);
    }
    FreeInstanceMemory(*(int *)(param_1 + 0x3a4));
    Ov107_DestroyObject(param_1);
}
