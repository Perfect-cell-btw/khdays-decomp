/* Timed step: advances the timer, sends a state update once when it passes 0x7f8, and when the
 * model's animation ends queues action 2, stores the frame step and clears the step handler. */

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot();

void Ov215_TimerActionOnceThenAdvance(int this_) {
    int field0 = *(int *)this_;
    int holder = *(int *)(this_ + 4);
    *(int *)(holder + 0x50) += *(int *)(field0 + 0x2c);
    if (*(unsigned char *)(holder + 0x70) == 0 && *(int *)(holder + 0x50) >= 0x7f8) {
        Ov107_BuildAndSendUpdate(*(int *)holder, 0x129, 8, *(int *)(holder + 0x10));
        *(unsigned char *)(holder + 0x70) = 1;
    }
    if (*(unsigned char *)(*(int *)(holder + 4) + 0xad) != 0) return;
    *(signed char *)(*(int *)holder + 0x1c7) = 2;
    *(int *)(holder + 0x54) = *(int *)(*(int *)this_ + 0x2c);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
