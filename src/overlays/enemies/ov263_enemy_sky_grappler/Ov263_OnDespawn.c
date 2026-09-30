/* Despawn handler: destroys the render object built by the class initialiser, then tail-calls the
 * shared actor teardown. */

extern int DestroyInstance();
extern int Ov107_DestroyObject();

int Ov263_OnDespawn(int *r0) {
    DestroyInstance(((int *)r0)[0x384 / 4]);
    return Ov107_DestroyObject(r0);
}
