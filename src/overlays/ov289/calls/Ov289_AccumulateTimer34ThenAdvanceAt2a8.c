extern unsigned int RandNextScaled(int);
extern void Ov107_PostTagUpdate(int node, int a, int b);
extern void SetIndexedSlot();
extern void Ov289_AiStep_QueueAction2OnAnimEnd(void);

struct hw60 { unsigned short lo : 8, hi : 8; };

void Ov289_AccumulateTimer34ThenAdvanceAt2a8(int this_) {
    int f0 = *(int *)this_;
    int holder = *(int *)(this_ + 4);
    int t = *(int *)(holder + 0x34) + *(int *)(f0 + 0x2c);
    *(int *)(holder + 0x34) = t;
    if (t < 0x2a8) return;
    ((struct hw60 *)(*(int *)holder + 0x60))->hi &= ~0x80;
    *(int *)(*(int *)holder + 0x394) = 1;
    *(int *)(*(int *)holder + 0x38c) = RandNextScaled(0x64) < 0xa;
    Ov107_PostTagUpdate(*(int *)holder, 0, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov289_AiStep_QueueAction2OnAnimEnd);
}
