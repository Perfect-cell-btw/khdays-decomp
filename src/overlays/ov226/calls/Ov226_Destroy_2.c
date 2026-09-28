/* Tear down the actor: destroy the render instance (+0x384) and the list instance (+0x394),
 * then release the actor itself. */
extern void DestroyInstance(int a);
extern void Ov107_DestroyObject(int a);
void Ov226_Destroy_2(int param_1) {
    DestroyInstance(*(int *)(param_1 + 0x384));
    DestroyInstance(*(int *)(param_1 + 0x394));
    Ov107_DestroyObject(param_1);
}
