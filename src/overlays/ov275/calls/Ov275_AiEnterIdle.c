/* Reset the timer (+0x24=0), play the anim (ov107 mode 1,1) and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov275_AiIdleTimer(int);
void Ov275_AiEnterIdle(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x24) = 0;
    Ov107_PostTagUpdate(*(int *)child, 1, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov275_AiIdleTimer);
}
