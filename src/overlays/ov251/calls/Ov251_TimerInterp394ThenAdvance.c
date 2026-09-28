extern int FX_Div(int a, int b);
extern void SetIndexedSlot();

void Ov251_TimerInterp394ThenAdvance(int this_) {
    int field0 = *(int *)this_;
    int holder = *(int *)(this_ + 4);
    int t = *(int *)(holder + 0x1c) + *(int *)(field0 + 0x2c);
    *(int *)(holder + 0x1c) = t;
    *(int *)(*(int *)holder + 0x394) = 0x1000 - FX_Div(t, 0x555);
    if (*(int *)(*(int *)holder + 0x394) < 1) {
        *(int *)(*(int *)holder + 0x394) = 1;
    }
    if (*(int *)(holder + 0x1c) < 0x555) return;
    *(signed char *)(*(int *)holder + 0x1c7) = 0xc;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
