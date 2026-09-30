/* AI step: advances the timer; once the actor is on the ground and the timer passes 0x400, queues
 * action 2 and clears the step handler. */

extern void SetIndexedSlot();

struct b1 { unsigned char b : 1; };

void Ov285_AccumulateTimer28ThenAdvanceAt400(int this_) {
    int a = *(int *)this_;
    int b = *(int *)(this_ + 4);
    int obj;
    *(int *)(b + 0x28) = *(int *)(b + 0x28) + *(int *)(a + 0x2c);
    obj = *(int *)b;
    if (((struct b1 *)(obj + 0x17a))->b == 0) return;
    if (*(int *)(b + 0x28) < 0x400) return;
    *(signed char *)(obj + 0x1c7) = 2;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
