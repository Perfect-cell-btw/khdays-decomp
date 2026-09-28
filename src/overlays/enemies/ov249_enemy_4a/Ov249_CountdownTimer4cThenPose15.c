/* Count the timer at (child)+0x4c down by the owner rate (+0x2c); while it stays
 * positive keep waiting, otherwise stop the anim (ov107 mode 0x15) and dispatch. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov249_AiStep_QueueAction2OnAnimEnd(int);
void Ov249_CountdownTimer4cThenPose15(int param_1) {
    int child = *(int *)(param_1 + 4);
    int c = *(int *)(child + 0x4c) - *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x4c) = c;
    if (c > 0) return;
    Ov107_PostTagUpdate(*(int *)child, 0x15, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov249_AiStep_QueueAction2OnAnimEnd);
}
