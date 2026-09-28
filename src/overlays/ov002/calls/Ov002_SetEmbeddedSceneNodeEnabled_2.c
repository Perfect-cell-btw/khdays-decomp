/* Class slot 0x3c: forwards to SetSceneNodeEnabled on the scene node at +0x3c. */

extern int Ov002_SetSceneNodeEnabled();

int Ov002_SetEmbeddedSceneNodeEnabled_2(int arg0) {
    return Ov002_SetSceneNodeEnabled(arg0 + 0x3c);
}
