/* Clear the +4 field, set (child)+0x2c = *child + 0xb0 and tail-call the dispatcher. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov211_AiEnterIdle(int);
void Ov211_AiGoToIdle(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 4) = 0;
    *(int *)(child + 0x2c) = *(int *)child + 0xb0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov211_AiEnterIdle);
}
