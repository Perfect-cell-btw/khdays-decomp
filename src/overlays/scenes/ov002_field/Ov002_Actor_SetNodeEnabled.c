/* Actor class slot 0x3c: enables/disables the scene node at +0x2c. */

extern int Ov002_SetSceneNodeEnabled();

int Ov002_Actor_SetNodeEnabled(int arg0, int arg1) {
    return Ov002_SetSceneNodeEnabled(arg0 + 0x2c, arg1);
}
