/* Tail-call Ov002_SetSceneNodeEnabled on the sub-object at param_1+0x3c. */
extern void Ov002_SetSceneNodeEnabled(void *obj);
void Ov016_SetEmbeddedSceneNodeEnabled(int param_1) {
    Ov002_SetSceneNodeEnabled((void *)(param_1 + 0x3c));
}
