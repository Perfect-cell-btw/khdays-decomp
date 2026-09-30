/* Tear down the actor: release the list at +0x390, destroy the render instance at +0x384,
 * then release the actor itself. */
extern void FreeInstanceMemory(int a);
extern void DestroyInstance(int a);
extern void Ov107_DestroyObject(int a);
void Ov185_Destroy(int param_1) {
    FreeInstanceMemory(*(int *)(param_1 + 0x390));
    DestroyInstance(*(int *)(param_1 + 0x384));
    Ov107_DestroyObject(param_1);
}
