extern int Ov002_SetSceneNodeEnabled();

int Ov002_SetEmbeddedSceneNodeEnabled(int arg0) {
    return Ov002_SetSceneNodeEnabled(arg0 + 0x3c);
}
