/* Play the anim (ov107 mode 3,1) and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov277_ApproachTick(int);
void Ov277_SetPose3ThenAdvanceSlot(int param_1) {
    Ov107_PostTagUpdate(*(int *)*(int *)(param_1 + 4), 3, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov277_ApproachTick);
}
