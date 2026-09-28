/* Tear down the actor: destroy the work list (+0x388), clear +0x394, release the render
 * (+0x384) and anim (+0x3b4) handles, free all 5 slot handles at +0x3e0, then release the
 * handle table and the actor itself. */
extern void FreeAllResourceTables(int a);
extern void DestroyInstance(int a);
extern void Ov107_ActionResource_Destroy(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
struct row8_020cc440 { int p; int q; };
void Ov275_Destroy(int param_1) {
    int i;
    FreeAllResourceTables(param_1 + 0x388);
    *(int *)(param_1 + 0x394) = 0;
    DestroyInstance(*(int *)(param_1 + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(param_1 + 0x3b4));
    for (i = 0; i < 5; i++) {
        DestroyInstance(((struct row8_020cc440 *)*(int *)(param_1 + 0x3e0))[i].p);
    }
    FreeInstanceMemory(*(int *)(param_1 + 0x3e0));
    Ov107_DestroyObject(param_1);
}
