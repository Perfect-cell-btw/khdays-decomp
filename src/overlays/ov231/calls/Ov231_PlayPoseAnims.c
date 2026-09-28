/* Pose helper: play anim param_2 on *child and anim param_3 on its owner node
 * *(*child+0x388) (both at speed param_4), then register the given handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_StartAnim(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
void Ov231_PlayPoseAnims(int param_1, int param_2, int param_3, int param_4, void *handler) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, param_2, param_4);
    Ov107_StartAnim(*(int *)(*(int *)child + 0x388), param_3, param_4);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), handler);
}
