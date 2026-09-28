/* Tear down the actor: destroy the work list (+0x388) and the list at +0x3d4, release the
 * render (+0x384) and anim (+0x3b8) handles, free all 8 slot handles at +0x3d0, then release
 * the handle table and the actor itself. */
extern void FreeAllResourceTables(int a);
extern void FreeInstanceMemory(int a);
extern void DestroyInstance(int a);
extern void Ov107_ActionResource_Destroy(int a);
extern void Ov107_DestroyObject(int a);
struct row8_020cfee8 { int p; int q; };
void Ov210_Destroy(int param_1) {
    int i;
    FreeAllResourceTables(param_1 + 0x388);
    FreeInstanceMemory(*(int *)(param_1 + 0x3d4));
    DestroyInstance(*(int *)(param_1 + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(param_1 + 0x3b8));
    for (i = 0; i < 8; i++) {
        DestroyInstance(((struct row8_020cfee8 *)*(int *)(param_1 + 0x3d0))[i].p);
    }
    FreeInstanceMemory(*(int *)(param_1 + 0x3d0));
    Ov107_DestroyObject(param_1);
}
