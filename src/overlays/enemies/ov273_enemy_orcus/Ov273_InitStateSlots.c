/* Clear the +0x1c6 byte, mark sub-state -1, set +4 = *(child)+0xb0 and register three handlers
 * in turn (slots 1, 0, 2). */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov273_AiLockAndResume(int);
extern void Ov273_ConsumePoseRequestB(int);
extern void Ov273_PublishPoseAndReset(int);
void Ov273_InitStateSlots(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(signed char *)(*(int *)child + 0x1c6) = 0;
    *(signed char *)(*(int *)child + 0x1c7) = -1;
    *(int *)(child + 4) = *(int *)child + 0xb0;
    SetIndexedSlot(param_1, 1, (void *)&Ov273_AiLockAndResume);
    SetIndexedSlot(param_1, 0, (void *)&Ov273_ConsumePoseRequestB);
    SetIndexedSlot(param_1, 2, (void *)&Ov273_PublishPoseAndReset);
}
