/* Play the anim (ov107 mode 2) on *child and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov254_AiStep_QueueAction0OnAnimEnd_3(int);
void Ov254_SetPose2ThenAdvanceSlot(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 2, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov254_AiStep_QueueAction0OnAnimEnd_3);
}
