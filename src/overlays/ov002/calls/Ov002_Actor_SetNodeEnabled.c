extern int Ov002_SetSceneNodeEnabled();

int Ov002_Actor_SetNodeEnabled(int arg0) {
    return Ov002_SetSceneNodeEnabled(arg0 + 0x2c);
}
