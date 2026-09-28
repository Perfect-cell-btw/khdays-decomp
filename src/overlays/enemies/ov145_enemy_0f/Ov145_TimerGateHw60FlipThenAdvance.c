/* Timed step: advances the timer by the owner's frame step and waits for it to pass its threshold;
 * then updates the state bits in the high byte of the actor's flags (+0x60), clears the pending
 * action (+0x1c7) and clears the step handler. */

struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot();

void Ov145_TimerGateHw60FlipThenAdvance(int this_) {
    int holder = *(int *)(this_ + 4);
    int field0 = *(int *)this_;
    int t = *(int *)(holder + 0x38) + *(int *)(field0 + 0x2c);
    *(int *)(holder + 0x38) = t;
    if (t < 0xd48) return;
    ((struct hw60 *)(*(int *)holder + 0x60))->hi &= ~1;
    {
        unsigned short *p = (unsigned short *)(*(int *)holder + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x80) << 0x18) >> 0x10));
    }
    *(signed char *)(*(int *)holder + 0x1c7) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
