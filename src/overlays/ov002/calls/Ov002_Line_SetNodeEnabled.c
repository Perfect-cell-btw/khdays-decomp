/* If the signed flag at (*(param_1+8))+0x58 is set, forward the +0x3c subobject
 * (and param_2) to its handler. */
extern void Ov002_SetSceneNodeEnabled(int obj, int arg);

void Ov002_Line_SetNodeEnabled(int param_1, int param_2) {
    if (*(signed char *)(*(int *)(param_1 + 8) + 0x58) != 0) {
        Ov002_SetSceneNodeEnabled(param_1 + 0x3c, param_2);
    }
}
