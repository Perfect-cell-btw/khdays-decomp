/* Play the anim (ov107 mode 0,1), reset the timer (+0x1c) and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov253_GrowTick(int);
void Ov253_AiEnterGrow(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 0, 1);
    *(int *)(child + 0x1c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_GrowTick);
}
