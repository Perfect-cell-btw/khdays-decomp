/* Tear down the actor: destroy the render instance at +0x384 and the list instance at
 * +0x394 if present, then release the actor itself. */
extern void DestroyInstance(int a);
extern void Ov107_DestroyObject(int a);
void Ov224_Projectile_Destroy(int param_1) {
    if (*(int *)(param_1 + 0x384) != 0) DestroyInstance(*(int *)(param_1 + 0x384));
    if (*(int *)(param_1 + 0x394) != 0) DestroyInstance(*(int *)(param_1 + 0x394));
    Ov107_DestroyObject(param_1);
}
