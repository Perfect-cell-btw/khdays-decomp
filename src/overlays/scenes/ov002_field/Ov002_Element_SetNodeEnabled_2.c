/* If bit0 of the flag byte at param_1+0x1bb is set, forward the +0x3c subobject
 * (and param_2) to its handler. */
extern void Ov002_SetSceneNodeEnabled(int obj, int arg);

void Ov002_Element_SetNodeEnabled_2(int param_1, int param_2) {
    if (*(unsigned char *)(param_1 + 0x1bb) & 1) {
        Ov002_SetSceneNodeEnabled(param_1 + 0x3c, param_2);
    }
}
