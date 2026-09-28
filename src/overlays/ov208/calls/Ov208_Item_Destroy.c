/* Tear down the actor: destroy the render instance at +0x384, free the four sub-instances
 * at +0x398 (stride 8), then release the actor itself. */
extern void DestroyInstance(int a);
extern void Ov107_DestroyObject(int a);
struct row8_020d393c { int p; int q; };
void Ov208_Item_Destroy(int param_1) {
    int i;
    DestroyInstance(*(int *)(param_1 + 0x384));
    for (i = 0; i < 4; i++) {
        DestroyInstance(((struct row8_020d393c *)param_1)[i + 0x73].p);
    }
    Ov107_DestroyObject(param_1);
}
