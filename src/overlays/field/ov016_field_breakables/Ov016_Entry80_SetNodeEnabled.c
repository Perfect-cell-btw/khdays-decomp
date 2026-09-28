/* Tail-call Ov002_SetSceneNodeEnabled on the sub-object at param_1+0x4a8, forwarding
 * param_2. */
extern int Ov002_SetSceneNodeEnabled(void *obj, int arg);
int Ov016_Entry80_SetNodeEnabled(int param_1, int param_2) {
    return Ov002_SetSceneNodeEnabled((void *)(param_1 + 0x4a8), param_2);
}
